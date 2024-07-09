# cub3D - 3D Maze Game
cub3D is a 3D maze game inspired by the classic Wolfenstein 3D, developed as part of the 42 school curriculum. This project implements a raycasting engine to create a first-person perspective view of a maze.

### Features

First-person 3D rendering using raycasting
Textured walls with different textures for each direction (North, South, East, West)
Player movement (forward, backward, strafe left, right) and rotation
Map parsing from a .cub file
Customizable floor and ceiling colors

### What I Learned
Developing this project provided valuable experience in:

#### Graphics Programming: Implementing a raycasting algorithm to create a 3D perspective from a 2D map.
#### Game Development Fundamentals: Creating a game loop, handling user input, and managing game state.
#### File Parsing: Reading and interpreting a custom file format (.cub) to generate the game map and settings.
#### Mathematics in Computer Graphics: Applying trigonometry and vector calculations for player movement and raycasting.
#### Memory Management: Ensuring proper allocation and deallocation of resources to prevent memory leaks.
#### Software Architecture: Designing a structure for a complex program with multiple interconnected components.
#### Problem Solving: Debugging and optimizing the raycasting algorithm for smooth performance.
#### Working with External Libraries: Utilizing the MinilibX library for creating windows and handling events.
#### Error Handling: Implementing robust error checking for file parsing and runtime issues.
#### Code Organization: Managing a larger-scale project with multiple source files and a Makefile.

### Usage

Clone the repository
Run make to compile the project
Execute the program with a valid .cub file: ./cub3D map.cub

### Controls

W, A, S, D: Move the player
Left/Right arrow keys: Rotate the camera
ESC: Exit the game

### Requirements

MinilibX library
C compiler (gcc recommended)
Make

This project was an exciting journey into the world of 3D graphics and game development, providing a deep understanding of how early 3D games were created and the mathematics behind them.
