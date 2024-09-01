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
void initialize();
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


void initialize() {

    cleardevice();

    // Initialize ball properties: center position on the screen, radius, and speed in both x and y directions
    ball.xAxis = getmaxx() / 2;  
    ball.yAxis = getmaxy() / 2;  
    ball.radius = 7;  
    ball.xSpeed = 7;  
    ball.ySpeed = 9;  

    // Initialize left bat (paddle) properties: position, size, and speed
    l_bat.xAxis = 20;  
    l_bat.yAxis = 237;  
    l_bat.length = 60; 
    l_bat.width = 4;  
    l_bat.speed = 13;  

    // Initialize right bat (paddle) properties: position, size, and speed
    r_bat.xAxis = 620;  
    r_bat.yAxis = 237;  
    r_bat.length = 60;  
    r_bat.width = 4;  
    r_bat.speed = 13;  

    // Reset scores for both players
    l_score.sc = 0;  
    r_score.sc = 0;  

    // Set the background color of the screen to green
    setbkcolor(GREEN);  

    // Set the font style and size for the game title text
    settextstyle(8, HORIZ_DIR, 6);  // Set the text style with font 8, horizontal direction, and size 6

    // Display the game title "PING PONG GAME" on the screen
    sprintf(gameTitle, "PING PONG GAME");  // Format the game title into the string
    outtextxy(60, (getmaxy() / 2) - 75, gameTitle);  // Display the game title at specified coordinates

    // Pause the screen for 2 seconds to show the title
    delay(2000);  

}