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

// Function declarations
int displayMenu();

char recentScores[3][100]; // Array to store recent scores from past games
char scoreText[15]; // Character array to store the text representation of the score
char authorName[25]; // Character array to store the name of the game's author
char gameTitle[50]; // Character array to store the title of the game
int scoreIndex = 0; // Integer to track the index of the current score in the recentScores array
int mode; // Integer to track the current game mode (e.g., single player, multiplayer)
int difficulty; // Integer to track the difficulty level of the game (e.g., easy, medium, hard)

int main() {
    int gd = DETECT, gm;  // 'gd' and 'gm' are variables to hold graphics drivers and mode. DETECT allows automatic detection of graphics driver.
    srand(time(NULL));
    
    // Initialize the graphics mode by specifying the path to the BGI (Borland Graphics Interface) files in Turbo C++
    initgraph(&gd, &gm, "C:/TURBOC3/bgi");
    mode = displayMenu();
    return 0;
}


int displayMenu() {
    char choice;
    while (1) {
        cleardevice();  // Clears the screen
        
        // Set the text style and display the menu options
        settextstyle(3, HORIZ_DIR, 3); // Font size 3, horizontal direction
        outtextxy(100, 100, "Choose Mode:");
        outtextxy(100, 150, "1. Play against AI");
        outtextxy(100, 200, "2. Play with a friend");

        choice = getch();  // Capture the user's input

        if (choice == '1') {
            return 1;  // Single-player mode selected
        } else if (choice == '2') {
            return 2;  // Two-player mode selected
        } else {
            // If an invalid input is given, show "Invalid input" and re-display the menu
            outtextxy(100, 250, "Invalid input. Please choose again.");
            delay(1000);  // Wait for a second
            displayMenu();
        }
    }
}
