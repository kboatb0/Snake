# SNAKE GAME
This is a basic snake that I made using the raylib library. I used the cmake build tool to make it cross-platform and as such it is
vey convenient to use.

## Prerequsites
- Cmake
- IDE

## Game Structure
- The game was made using a **30x30** <ins>grid</ins>.
- The **Snake.h** contains information about *snake*.
- The **SnakeFood.h** contains information about the *apple*.
- The **Game.h** is where all the game logic like *Collisions*, *Game Status*, *Generating food position* etc. has been defined.
- The **Snake.cpp** is the executable file which is in charge of defining the game loop and drawing stuffs on the window.

## User input
- The game accepts user input by using the arrow keys on the keyboard ie. *up_arrow, down_arrow , left_arrow and right_arrow keys*.
- A check was implemented for the user input to prevent the snake from being able to **reverse** abruptly if there is a successive 
user inputs.
- The snake adjusts its direction based on the given input.

### Directory Structure
- The root directory is called **Snake**
- I have included all the necessay dependencies (**include and library files**) in the *Dependencies directory*.
- The header files and source files can be found in the *Snake* directory found within the root directory.
- The *CMakeList* in the *Snake* sub-directory is where all the executables, directories and libraries were included and linked

### Note
The library was linked statically

Find more my repository [kboatb0](https://github.com/kboatb0)