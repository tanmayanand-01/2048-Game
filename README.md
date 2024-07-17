# 2048-Game
A simple non-GUI C++ implementation of the popular puzzle game 2048.

-	A command-line version of the 2048 game, where players can move tiles in four directions to combine numbers and achieve the 2048 tile.
-	Implementing the core game mechanics, including the 4x4 grid, tile merging rules, and movement logic (up, down, left, right).
-	Ensure tiles combine correctly when moved and handle the generation of new tiles (2 or 4) after each move.
-	Create a text-based interface to display the game grid and capture user input. 
-	Use the console to print the grid after every move and accept commands from the user to control the direction of the tile movement.

HOW TO RUN -
For Linux-based distros (Debian, Arch Linux) :
- Open your terminal and change the directory to 2048-Game/src/main.cpp
- Run the command g++ main.cpp
- After that run the command ./a.out
- Now the puzzle game in CLI is ready.

  For Windows :
  - First in "line 249" of the code file "main. cpp" change system("clear") to system("cls")
  - Follow all the steps that are for Linux.
  -  Now the puzzle game in CLI is ready.
