# GAME
# Ping Pong Game

## Table of Contents
1. [Introduction](#introduction)
2. [Features](#features)
3. [Game Modes](#game-modes)
4. [Controls](#controls)
5. [Technical Details](#technical-details)
6. [Installation](#installation)
7. [How to Play](#how-to-play)
8. [Limitations](#limitations)
9. [Future Improvements](#future-improvements)
10. [Troubleshooting](#troubleshooting)
11. [Credits](#credits)

## Introduction

Welcome to the Ping Pong Game, a classic arcade-style implementation using C and the Borland Graphics Interface (BGI). This project aims to recreate the timeless enjoyment of Ping Pong in a digital format, offering both single-player and multiplayer experiences. Developed as a learning exercise, this game showcases fundamental game development concepts, including game loops, collision detection, and simple AI.

## Features

- **Dual Game Modes**: Choose between single-player (vs AI) or two-player local multiplayer.
- **Adjustable AI Difficulty**: Test your skills against Easy, Medium, or Hard AI opponents.
- **Real-time FPS Counter**: Monitor game performance with an on-screen FPS display.
- **Dynamic Scoring System**: Keep track of your victories with an in-game score tracker.
- **Immersive Sound Effects**: Enjoy audio feedback for ball collisions and scoring events.
- **Game Over Screen**: View recent scores and choose to play again or exit.

## Game Modes

### Single Player Mode
Challenge yourself against an AI opponent with three difficulty levels:
- **Easy**: The AI makes frequent mistakes, suitable for beginners.
- **Medium**: Balanced AI performance for intermediate players.
- **Hard**: Quick reflexes and minimal mistakes, perfect for experienced players.

### Two Player Mode
Compete against a friend in local multiplayer action. Test your reflexes and strategy in head-to-head matches.

## Controls

| Action | Player A (Left) | Player B (Right) |
|--------|-----------------|-------------------|
| Move Up | 'A' key | 'K' key |
| Move Down | 'Z' key | 'M' key |
| Quit Game | 'Q' key | 'Q' key |

## Technical Details

### Programming Language and Environment
- **Language**: C
- **Compiler**: Turbo C++
- **Graphics Library**: Borland Graphics Interface (BGI)

### Key Components
1. **Ball Physics**: 
   - Implemented using simple vector mathematics.

2. **Collision Detection**:
   - Precise calculations for ball-paddle and ball-wall collisions.

3. **AI Logic**:
   - Difficulty-based decision making for AI paddle movement.

4. **FPS Counter**:
   - Utilizes the `clock()` function for time-based frame counting.
   - Updates display every second for accurate representation.

5. **Sound System**:
   - Leverages DOS-based `sound()` function for audio cues.
   - Different frequencies used for various in-game events.

6. **File Handling**:
   - Stores and retrieves recent scores using file I/O operations.
   - Implements basic error handling for file operations.

## Installation

1. **Turbo C++ Setup**:
   - Download and install Turbo C++ (version 3.0 or later recommended).
   - Ensure BGI library is correctly configured in your Turbo C++ environment.

2. **Game Installation**:
   - Create a new project in Turbo C++.
   - Copy the provided source code into the project.
   - Save the project in your desired location.

3. **Compilation**:
   - Open the project in Turbo C++.
   - Compile the code using the built-in compiler (usually F9 key).

## How to Play

1. **Starting the Game**:
   - Run the compiled executable from within Turbo C++.
   - You'll be greeted with the main menu.

2. **Selecting Game Mode**:
   - Choose between Single Player (1) or Two Player (2) mode.
   - For Single Player, select your preferred AI difficulty.

3. **Gameplay**:
   - Use the designated keys to move your paddle up and down.
   - Prevent the ball from passing your paddle while trying to score against your opponent.
   - The game continues until one player reaches 5 points.

4. **Post-Game**:
   - View the final score and recent game history.
   - Choose to play again (P) or quit (Q).

## Limitations

1. **Platform Dependency**:
   - Exclusively compatible with Turbo C++ and DOS-based systems.
   - Not portable to modern operating systems or compilers without significant modifications.

2. **Graphics Constraints**:
   - Relies on the outdated BGI library, limiting visual capabilities.
   - Fixed resolution and color palette, not adaptable to various screen sizes or color depths.

3. **Performance Issues**:
   - FPS counter may not accurately reflect true frame rate due to `clock()` function limitations.
   - Game speed tied to system clock, potentially varying on different hardware.

4. **Sound Limitations**:
   - Basic beep sounds using `sound()` function, not compatible with modern audio systems.
   - Limited audio quality and variety.

5. **Input Handling**:
   - Uses `kbhit()` and `getch()` for keyboard input, which may not be ideal for smooth, responsive controls.

6. **File System Constraints**:
   - Requires write permissions in the game directory for score saving.
   - Uses a fixed filename ("Q.txt") which may conflict with existing files.



## Troubleshooting

1. **Compilation Errors**:
   - Ensure Turbo C++ is correctly installed and configured.
   - Check that all required header files are available in your include path.
   - Verify BGI library is properly linked in your project settings.

2. **Graphics Issues**:
   - Confirm BGI driver files are present in the correct directory.
   - Try different BGI modes if the default doesn't work on your system.

3. **Performance Problems**:
   - Adjust the delay in the main game loop to balance between smooth gameplay and CPU usage.
   - Optimize collision detection and AI calculations if frame rate is consistently low.

4. **Sound Not Working**:
   - Check if your system supports DOS-based sound functions.
   - Ensure volume is unmuted and at an audible level.

5. **File Writing Errors**:
   - Verify you have write permissions in the game's directory.
   - Close any other applications that might be accessing the score file.

## Credits

Developed by Harshit Behal

Special thanks to:
- The Turbo C++ development team for providing the development environment.
- The BGI library creators for enabling graphical implementations in DOS-based systems.
- The open-source community for inspiration and resources on game development techniques.

---