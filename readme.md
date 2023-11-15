# My First Game : so_long

Graphics are bad, ok. But it was not the point of the project.

## How to install so_long

To play this game, copy the following commands in your terminal.

	cd ~    # go to your home directory
	git clone https://github.com/Bonnet2B1/so_long.git    # clone the repository
	cd so_long    # go to the game folder
	git clone https://github.com/codam-coding-college/MLX42.git    # install graphics library
	cd MLX42    # go to the graphics library folder
	cmake -B build    # build here refers to the outputfolder.
	cmake --build build -j4    # or do make -C build -j4
	cd ~    # go to your home directory

## How to play so_long

To play this game, copy the following commands in your terminal.

	cd ~/so_long    # go to the game folder
	make    # compile the game
	./so_long map.ber    # play the game with the map (here map.ber)

You can move the player (the blue square) with W,A,S,D keys.


## How to uninstall so_long

To uninstall this game, copy the following commands in your terminal.

	cd ~    # go to your home directory
	rm -rf so_long    # remove the game folder

## How to edit the map

To edit the map, you have to edit the map.ber file.

Copy the following commands in your terminal.

	open -e ~/so_long/map.ber    # open the map.ber file with the text editor


The map.ber file must have the following rules:

- The map must be surrounded by walls.
- The map must be rectangular.
- The map must be doable.
- The map must have at least one exit.
- The map must have at least one collectible.
- The map must have at least one player.

Representation of the pixels in the map.ber file :

- floor = 0
- wall = 1
- player = P
- collectible = C
- exit = E
- ennemy = Z (bonus)

Then, you can save the map.ber file and play the game with the new map by the instruction in "[How to play so_long](#how-to-play-so_long)" section.
