This computer version of the Othello board game was written in C++ using the SFML API. 

To build this game from scratch, download a C++ compiler of your choice and use CMAKE to generate a solution for that compiler and simply build it. SFML and all of its dependencies will be built alongside Othello.

After that, from this directory, navigate to external\SFML\extlibs\bin and find a version of OpenAl that runs on your operating system and copy it to the Othello folder inside your specified build directory. Then run the game!

To run a precompiled Windows version of the game, navigate to the `Build For Windows` directory and run `Othello.exe`