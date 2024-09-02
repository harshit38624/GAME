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
int aiMovement();
int chooseDifficulty();

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
    mode = displayMenu();  // Display the main menu and store the chosen mode (1 for single-player, 2 for two-player)
    // If the player chooses single-player mode
    if (mode == 1) {
        difficulty = chooseDifficulty();  // Display the difficulty selection menu and store the chosen difficulty level
    }
    initialize();
    getch();  // Wait for a key press before closing the graphics window
    closegraph();  // Close the graphics window and clean up resources

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

int chooseDifficulty() {
    char choice; 
    cleardevice();  
    
    // Set text style and display the difficulty options
    settextstyle(3, HORIZ_DIR, 3);
    outtextxy(100, 100, "Choose Difficulty:");
    outtextxy(100, 150, "1. Easy");
    outtextxy(100, 200, "2. Medium");
    outtextxy(100, 250, "3. Hard");
    
    choice = getch();  // Wait for the user to press a key
    
    // Check if the user pressed a valid option (1, 2, or 3)
    if (choice >= '1' && choice <= '3') {
        return choice - '0';  
    } else {
        outtextxy(100, 250, "Invalid input. Please choose again.");
        delay(1000);  // Wait for a second
        return chooseDifficulty();  // If invalid input, call the function again to prompt the user for a valid input
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

    while (1) {  

        cleardevice();

        // Display the scores of both players
        settextstyle(0, HORIZ_DIR, 1);  
        sprintf(scoreText, "A - %d", l_score.sc);
        outtextxy(10, 450, scoreText);  // Display player A's score at (10, 450)
        sprintf(scoreText, "B - %d", r_score.sc); 
        outtextxy(560, 450, scoreText);  // Display player B's score at (560, 450)

        // Display author information at the bottom center of the screen
        settextstyle(3, HORIZ_DIR, 2);
        sprintf(authorName, "Made BY Harshit Behal");  
        outtextxy(getmaxx() / 2 - 115, 450, authorName);  // Display author name centered at the bottom

        // Draw the line at the bottom of the screen (court boundary)
        bar(0, 443, getmaxx(), 443);

        // Check if the ball passes the left paddle (player A's side)
        if (ball.xAxis < l_bat.xAxis) {
            // Reset ball and paddles to the center if player A misses
            ball.xAxis = getmaxx() / 2;  // Reset ball to the center horizontally
            ball.yAxis = getmaxy() / 2;  // Reset ball to the center vertically
            r_bat.yAxis = getmaxy() / 2;  // Reset right bat (player B) to the center vertically
            l_bat.yAxis = getmaxy() / 2;  // Reset left bat (player A) to the center vertically
            r_score.sc++;  // Increment player B's score

            // Play a sound effect to indicate a point
            sound(1000);  
            delay(75);  
            nosound();  
        }

        // Check if the ball passes the right paddle (player B's side)
        if (ball.xAxis > r_bat.xAxis + r_bat.width) {
            // Reset ball and paddles to the center if player B misses
            ball.xAxis = getmaxx() / 2;  // Reset ball to the center horizontally
            ball.yAxis = getmaxy() / 2;  // Reset ball to the center vertically
            r_bat.yAxis = getmaxy() / 2;  // Reset right bat (player B) to the center vertically
            l_bat.yAxis = getmaxy() / 2;  // Reset left bat (player A) to the center vertically
            l_score.sc++;  // Increment player A's score

            // Play a sound effect to indicate a point
            sound(1000);
            delay(75);
            nosound();
        }

        // Check if the ball hits the top or bottom edge of the screen
        if (ball.yAxis < 0 || ball.yAxis > 434) {
            ball.ySpeed *= -1;  // Reverse the ball's vertical direction
        }

        // Update the ball's position based on its speed
        ball.xAxis = ball.xAxis + ball.xSpeed;  // Move the ball horizontally
        ball.yAxis = ball.yAxis + ball.ySpeed;  // Move the ball vertically
    }

    // Draw the left bat (player A) as a filled rectangle
    bar(l_bat.xAxis, l_bat.yAxis, l_bat.xAxis + l_bat.width, l_bat.yAxis + l_bat.length);

    // Draw the right bat (player B) as a filled rectangle
    bar(r_bat.xAxis, r_bat.yAxis, r_bat.xAxis + r_bat.width, r_bat.yAxis + r_bat.length);

    // Check for collision with the left bat
    if ((l_bat.yAxis + l_bat.length) > ball.yAxis &&  // Ball is within the vertical bounds of the left bat
        (ball.yAxis > l_bat.yAxis) &&                   // Ball is below the top edge of the left bat
        (l_bat.xAxis + l_bat.width + 4) > ball.xAxis) { // Ball is within the horizontal bounds of the left bat
        ball.xSpeed *= -1;  // Reverse the ball's horizontal direction
        setbkcolor(BLUE);   
        sound(200);         
        delay(50);          
        nosound();         
    }

    // Check for collision with the right bat
    if ((r_bat.yAxis + r_bat.length) > ball.yAxis &&  // Ball is within the vertical bounds of the right bat
        r_bat.yAxis < ball.yAxis &&                   // Ball is below the top edge of the right bat
        r_bat.xAxis - 4 < ball.xAxis) {               // Ball is within the horizontal bounds of the right bat
        ball.xSpeed *= -1;  // Reverse the ball's horizontal direction
        setbkcolor(RED);    
        sound(200);         
        delay(50);          
        nosound();         
    }

    if (mode == 1) {  // If playing against AI
        //aiMovement();
    }

    // Check if a key has been pressed
    if (kbhit()) {
        char c = getch();  // Get the pressed key

        // Control for the left bat (player A)
        if (c == 'z' && l_bat.yAxis + l_bat.length <= 440) {  // If 'z' is pressed and the left bat can move down
            l_bat.yAxis = l_bat.yAxis + l_bat.speed;  
        } else if (c == 'a' && l_bat.yAxis >= 0) {  // If 'a' is pressed and the left bat can move up
            l_bat.yAxis = l_bat.yAxis - l_bat.speed;  
        }

        // Control for the right bat (player B) - only if playing in two-player mode
        if (mode == 2) {
            if (c == 'm' && r_bat.yAxis + r_bat.length <= 440) {  // If 'm' is pressed and the right bat can move down
                r_bat.yAxis = r_bat.yAxis + r_bat.speed;  
            } else if (c == 'k' && r_bat.yAxis >= 0) {  // If 'k' is pressed and the right bat can move up
                r_bat.yAxis = r_bat.yAxis - r_bat.speed;  
            }
        }
    }
    
}