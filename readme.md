# My First Game : so_long
Graphics are bad, ok.
But it was not the point of the project.

## How To Play This Game
To play this game, copy the following commands in your terminal.

	git clone https://github.com/Bonnet2B1/so_long.git
	cd so_long
	git clone https://github.com/codam-coding-college/MLX42.git
	cmake -B build # build here refers to the outputfolder.
	cmake --build build -j4 # or do make -C build -j4
	cd ..
	make
	./so_long map.ber
