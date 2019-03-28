This computer version of the Othello board game was written in C++ using the SFML API. 


To build this game from scratch, you will first need to pull the SFML git repo submodule. To do this, run the following command from this directory.

	git submodule update --init --recursive

Now, download a C++ compiler of your choice and use CMAKE to generate a solution for that compiler and simply build it. SFML will be built alongside Othello and be referenced as a dependency.

From this directory, navigate to external\SFML\extlibs\bin and find a version of OpenAl that runs on your operating system and copy it to the Othello folder inside your specified build directory. Then simply run the game!

To run a precompiled Windows version of the game, navigate to the `Build For Windows` directory and run `Othello.exe`