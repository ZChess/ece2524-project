Hello, welcome to command line checkers. This game has the option of choosing between two players or a one player game vs. an AI.
===========================================================

There are no special requirements to run the program, just compile the game using the make command and run ./checkers from the screen to begin.

How To Play
----------------------------------------------------------

	The game will ask how many players want to play the game. If the player chooses 1 as an option the player will be x's against an AI o. Chooseing 2 players will have player 1 be x's and player 2 become o's. Any other input will cause the program to ask for another input until the player puts in a 1 or 2.

	The way that the game works is that the board will be displayed after every move the player tries to make. The game will then ask "What piece do you want to move?" and wait for a command line input. The player then selects the piece by typing where it is positioned on the board. A space where a peice can be placed is indicated by an underscore "_". An example of a move is as follows:

		What piece do you want to move?
		>>B1
		Where do you want to move it to?
		>>C2

	If the move was valid the program then asks the player if he/she is done with their turn. This allows the player to do a double jump, if the option is avaliable on the board. Note that only capital letters can be used for selecting peices. If the player trys to make an invalid move then the program will redisplay the board and ask for a different move.

	When the game is over then the player has the option to play again or quit. If the player decides to play again then the game will go back to the start and ask how many players want to play. If the player wants to quit then the program will terminate.

Hope you have fun and good luck!
