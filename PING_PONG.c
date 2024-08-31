#include <graphics.h>  // Used for handling graphical operations like drawing shapes, lines, and images.
#include <stdio.h>     // Standard input/output library used for handling I/O operations. 
#include <stdlib.h>    // Provides functions for dynamic memory allocation (malloc, free), process control (exit), conversions, and other utilities like random number generation (rand).
#include <conio.h>     // Console input/output library, mainly for Turbo C/C++ environments.
#include <dos.h>       // Used for low-level system functions related to the Disk Operating System (DOS).
#include <time.h>      // Time library used for handling time-related operations such as measuring time (clock), managing dates, and delays based on real-time values.

// Struct to represent the ball's properties and movements in the game
struct ball {
    int xAxis;    // X-coordinate of the ball
    int yAxis;    // Y-coordinate of the ball
    int radius;   // Radius of the ball
    int xSpeed;   // Speed of the ball along the X-axis (horizontal movement)
    int ySpeed;   // Speed of the ball along the Y-axis (vertical movement)
} ball;

// Struct to represent the paddle (bat) properties for both left and right players
struct bat {
    int xAxis;    // X-coordinate of the bat
    int yAxis;    // Y-coordinate of the bat
    int length;   // Length of the bat (height)
    int width;    // Width of the bat
    int speed;    // Speed of the bat movement
} l_bat, r_bat;

// Struct to represent the score of the players
struct score {
    int sc;
} l_score, r_score;

// Array to store recent scores from past games
char recentScores[3][100];

// Character array to store the text representation of the score
char scoreText[15];

// Character array to store the name of the game's author
char authorName[25];

// Character array to store the title of the game
char gameTitle[50];

// Integer to track the index of the current score in the recentScores array
int scoreIndex = 0;

// Integer to track the current game mode (e.g., single player, multiplayer)
int mode;  

// Integer to track the difficulty level of the game (e.g., easy, medium, hard)
int difficulty;
