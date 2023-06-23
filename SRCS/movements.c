/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 19:16:51 by edelarbr          #+#    #+#             */
/*   Updated: 2023/06/23 19:59:51 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	end(t_map *m, int i)
{
	if (i == -1)
	{
		ft_putstr("-------------\n");
		ft_putstr("| ");
		ft_putstr("\033[1;31mGame Over\033[00m");
		ft_putstr(" |\n");
		ft_putstr("-------------\n");
	}
	else if (i == 1)
	{
		ft_putstr("-----------\n");
		ft_putstr("| ");
		ft_putstr("\033[1;32mYou Win\033[00m");
		ft_putstr(" |\n");
		ft_putstr("-----------\n");
	}
	else if (i == 0)
	{
		ft_putstr("-------------\n");
		ft_putstr("| ");
		ft_putstr("\033[1;36mExit Game\033[00m");
		ft_putstr(" |\n");
		ft_putstr("-------------\n");
	}
	return (freeall(m), exit(0));
}

int	move(t_map *m, char **old_map, int x, int y)
{
	if (m->map[m->player_y + y][m->player_x + x] == '1')
		return (0);
	if (m->map[m->player_y + y][m->player_x + x] == 'Z')
		return (ft_putnbr(++m->movements), write(1, "\n", 1), end(m, -1), 0);
	if (m->map[m->player_y + y][m->player_x + x] == 'C')
	{
		m->map[m->player_y + y][m->player_x + x] = 'P';
		m->collectible--;
	}
	else if (m->map[m->player_y + y][m->player_x + x] == '0')
		m->map[m->player_y + y][m->player_x + x] = 'P';
	else if (m->map[m->player_y + y][m->player_x + x] == 'E' && m->collectible)
		m->map[m->player_y + y][m->player_x + x] = 'e';
	else if (m->map[m->player_y + y][m->player_x + x] == 'E' && !m->collectible)
		return (ft_putnbr(++m->movements), write(1, "\n", 1), end(m, 1), 1);
	if (m->map[m->player_y][m->player_x] == 'e')
		m->map[m->player_y][m->player_x] = 'E';
	else
		m->map[m->player_y][m->player_x] = '0';
	m->player_x += x;
	m->player_y += y;
	render_map(m, old_map);
	return (freemap(old_map, m->height), ft_putnbr(++m->movements), write(1, "\n", 1), 1);
}

void	key(mlx_key_data_t keydata, void *param)
{
	t_map	*m;

	m = param;
	if (keydata.key == MLX_KEY_ESCAPE)
		end(m, 0);
	if (mlx_is_key_down(m->mlx, MLX_KEY_A))
		move(m, copy_map(m, m->map), -1, 0);
	else if (mlx_is_key_down(m->mlx, MLX_KEY_D))
		move(m, copy_map(m, m->map), 1, 0);
	else if (mlx_is_key_down(m->mlx, MLX_KEY_W))
		move(m, copy_map(m, m->map), 0, -1);
	else if (mlx_is_key_down(m->mlx, MLX_KEY_S))
		move(m, copy_map(m, m->map), 0, 1);
}
