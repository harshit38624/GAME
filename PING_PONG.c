#include <graphics.h> // Used for handling graphical operations like drawing shapes, lines, and images.
#include <stdio.h> // Standard input/output library used for handling I/O operations. 
#include <stdlib.h> // Provides functions for dynamic memory allocation (malloc, free), process control (exit), conversions, and other utilities like random number generation (rand).
#include <conio.h> // Console input/output library, mainly for Turbo C/C++ environments.
#include <dos.h> // Used for low-level system functions related to the Disk Operating System (DOS).
#include <time.h> // Time library used for handling time-related operations such as measuring time (clock), managing dates, and delays based on real-time values.

// Struct to represent the ball's properties and movements in the game
struct ball {
    int xAxis;
    int yAxis;
    int radius;
    int xSpeed;
    int ySpeed;
} ball;

// Struct to represent the paddle (bat) properties for both left and right players
struct bat {
    int xAxis;
    int yAxis;
    int length;
    int width;
    int speed;
} l_bat, r_bat;

// Struct to represent the score of the players
struct score {
    int sc;
} l_score, r_score;

char recentScores[3][100]; // Array to store recent scores from past games
char scoreText[15]; // Character array to store the text representation of the score
char authorName[25]; // Character array to store the name of the game's author
char gameTitle[50]; // Character array to store the title of the game
int scoreIndex = 0; // Integer to track the index of the current score in the recentScores array
int mode; // Integer to track the current game mode (e.g., single player, multiplayer)
int difficulty; // Integer to track the difficulty level of the game (e.g., easy, medium, hard)

// New global variables for FPS tracking
clock_t lastTime = 0;
int frameCount = 0;
float fps = 0.0f;

// Function declarations
int displayMenu();
int chooseDifficulty();
void initialize();
void aiMovement();
void updateFPS();

int main() {
    int gd = DETECT, gm; // 'gd' and 'gm' are variables to hold graphics drivers and mode. DETECT allows automatic detection of graphics driver.
    srand(time(NULL));  // Initialize random seed
    initgraph(&gd, &gm, "C:/TURBOC3/bgi");// Initialize the graphics mode by specifying the path to the BGI (Borland Graphics Interface) files in Turbo C++
    mode = displayMenu();// Display the main menu and store the chosen mode (1 for single-player, 2 for two-player)
    // If the player chooses single-player mode
    if (mode == 1) {
        difficulty = chooseDifficulty();// Display the difficulty selection menu and store the chosen difficulty level
    }
    initialize();
    closegraph(); // Close the graphics window and clean up resources
    return 0;
}

void updateFPS() {
    clock_t currentTime;
    float deltaTime;
    char fpsText[20];
    frameCount++;
    currentTime = clock();
    deltaTime = (float)(currentTime - lastTime) / CLOCKS_PER_SEC;

    if (deltaTime >= 1.0f) {
        fps = frameCount / deltaTime;
        frameCount = 0;
        lastTime = currentTime;
    }

    sprintf(fpsText, "FPS: %.1f", fps);
    setcolor(WHITE);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
    outtextxy(getmaxx() - textwidth(fpsText) - 10, 10, fpsText);
}

int displayMenu() {
    char choice;
    cleardevice(); // Clears the screen
    
    // Set the text style and display the menu options
    settextstyle(3, HORIZ_DIR, 3); // Font size 3, horizontal direction
    outtextxy(100, 100, "Choose Mode:");
    outtextxy(100, 150, "1. Play against AI");
    outtextxy(100, 200, "2. Play with a friend");
    
    choice = getch(); // Capture the user's input
    
    if (choice == '1') {
        return 1;  // Single-player mode (against AI)
    } else if (choice == '2') {
        return 2;  // Two-player mode (against a friend)
    } else {
        // If an invalid input is given, show "Invalid input" and re-display the menu
        outtextxy(100, 250, "Invalid input. Please choose again.");
        delay(1000);  // Wait for a second
        displayMenu();    
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
    
    choice = getch();// Wait for the user to press a key
    
    // Check if the user pressed a valid option (1, 2, or 3)
    if (choice >= '1' && choice <= '3') {
        return choice - '0';
    } else {
        outtextxy(100, 350, "Invalid input. Please choose again.");
        delay(1000);  // Wait for a second
        return chooseDifficulty();  // If invalid input, call the function again to prompt the user for a valid input
    }
}

void aiMovement() {
    int randomError = rand() % 100;  // Random number between 0 and 99
    int distanceThreshold = 70;  // Distance threshold for when AI should start reacting

    // If the ball is within the AI's range (near the right bat)
    if (abs(ball.xAxis - r_bat.xAxis) < distanceThreshold) {
        switch (difficulty) {
            case 1:  // Easy
                if (randomError <= 80) return;  // 80% chance of making a mistake
                break;
            case 2:  // Medium
                if (randomError <= 60) return;  // 60% chance of making a mistake
                break;
            case 3:  // Hard
                if (randomError <= 40) return;  // 40% chance of making a mistake
                break;
        }
    }

    // Move the AI paddle to follow the ball
    // If the ball is above the AI paddle, move the paddle up
    if (ball.yAxis < r_bat.yAxis + (r_bat.length / 2)) {
        if (r_bat.yAxis > 0) r_bat.yAxis -= r_bat.speed;  // Move up
    }
    // If the ball is below the AI paddle, move the paddle down 
    else if (ball.yAxis > r_bat.yAxis + (r_bat.length / 2)) {
        if (r_bat.yAxis + r_bat.length < 440) r_bat.yAxis += r_bat.speed;  // Move down
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
    settextstyle(8, HORIZ_DIR, 6);
    sprintf(gameTitle, "PING PONG GAME");
    outtextxy(60, (getmaxy() / 2) - 75, gameTitle);
    delay(2000);

    while (1) {

        cleardevice();


        // Display the scores of both players
        settextstyle(0, HORIZ_DIR, 1);
        sprintf(scoreText, "A - %d", l_score.sc);
        outtextxy(10, 450, scoreText);
        sprintf(scoreText, "B - %d", r_score.sc);
        outtextxy(560, 450, scoreText);

        // Display author information at the bottom center of the screen
        settextstyle(3, HORIZ_DIR, 2);
        sprintf(authorName, "Made BY Harshit Behal");
        outtextxy(getmaxx() / 2 - 115, 450, authorName);

        // Draw the line at the bottom of the screen (court boundary)
        bar(0, 443, getmaxx(), 443);

        // Check if the ball passes the left paddle (player A's side)
        if (ball.xAxis < l_bat.xAxis) {
            // Reset ball and paddles to the center if player A misses
            ball.xAxis = getmaxx() / 2;  // Reset ball to the center horizontally
            ball.yAxis = getmaxy() / 2;  // Reset ball to the center vertically
            r_bat.yAxis = getmaxy() / 2;  // Reset right bat (player B) to the center vertically
            l_bat.yAxis = getmaxy() / 2;  // Reset left bat (player A) to the center vertically
            r_score.sc++;

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
            l_score.sc++;
            // Play a sound effect to indicate a point            
            sound(1000);
            delay(75);
            nosound();
        }

        // Check if the ball hits the top or bottom edge of the screen
        if (ball.yAxis < 0 || ball.yAxis > 434) {
            ball.ySpeed *= -1; // Reverse the ball's vertical direction
        }

        // Update the ball's position based on its speed
        ball.xAxis = ball.xAxis + ball.xSpeed; // Move the ball horizontally
        ball.yAxis = ball.yAxis + ball.ySpeed;// Move the ball vertically

        setcolor(WHITE);
        setfillstyle(SOLID_FILL, WHITE);
        circle(ball.xAxis, ball.yAxis, ball.radius);
        floodfill(ball.xAxis, ball.yAxis, WHITE);

        bar(l_bat.xAxis, l_bat.yAxis, l_bat.xAxis + l_bat.width, l_bat.yAxis + l_bat.length);
        bar(r_bat.xAxis, r_bat.yAxis, r_bat.xAxis + r_bat.width, r_bat.yAxis + r_bat.length);

        // Check for collision with the left bat
        if ((l_bat.yAxis + l_bat.length) > ball.yAxis && (ball.yAxis > l_bat.yAxis) && (l_bat.xAxis + l_bat.width + 4) > ball.xAxis) {
            ball.xSpeed *= -1; // Reverse the ball's horizontal direction
            setbkcolor(BLUE);
            sound(200);
            delay(50);
            nosound();
        }

        // Check for collision with the right bat
        if ((r_bat.yAxis + r_bat.length) > ball.yAxis && r_bat.yAxis < ball.yAxis && r_bat.xAxis - 4 < ball.xAxis) {
            ball.xSpeed *= -1; // Reverse the ball's horizontal direction
            setbkcolor(RED);
            sound(200);
            delay(50);
            nosound();
        }

        updateFPS();
        
        if (mode == 1) {  // If playing against AI
            aiMovement();
        }

        // Check if a key has been pressed
        if (kbhit()) {
            char c = getch();

            // Control for the left bat
            if (c == 'z' && l_bat.yAxis + l_bat.length <= 440) {  // 'z' key
                l_bat.yAxis = l_bat.yAxis + l_bat.speed;
            } else if (c == 'a' && l_bat.yAxis >= 0) {  // 'a' key
                l_bat.yAxis = l_bat.yAxis - l_bat.speed;
            }


            // Control for the right bat (only in two-player mode)
            if (mode == 2) {
                if (c == 'm' && r_bat.yAxis + r_bat.length <= 440) {  // 'm' key
                    r_bat.yAxis = r_bat.yAxis + r_bat.speed;
                } else if (c == 'k' && r_bat.yAxis >= 0) {  // 'j' key
                    r_bat.yAxis = r_bat.yAxis - r_bat.speed;
                }
            }


            // Check for quit
            if (c == 'q') {
                FILE *file;
                file = fopen("Q.txt", "a");
                if (file != NULL) {
                    fprintf(file, "\nA - %d \t B - %d", l_score.sc, r_score.sc);
                    fclose(file);
                }
                exit(0);
            }
        }

        delay(50);

        // Check if either player has reached the winning score (5 points)
        if (l_score.sc == 5 || r_score.sc == 5) {
            FILE *file;
            
            // Open the file in append mode to record the final score
            file = fopen("Q.txt", "a");
            if (file != NULL) {
                fprintf(file, "\nA - %d \t B - %d", l_score.sc, r_score.sc);
                fclose(file);  // Close the file after writing
            }

            // Open the file in read mode to retrieve recent scores
            file = fopen("Q.txt", "r");
            if (file != NULL) {
                // Move the file pointer to near the end of the file
                fseek(file, -43, SEEK_END);
                scoreIndex = 0;
                // Read the last 3 scores (or less if the file has fewer lines)
                while (!feof(file) && scoreIndex < 3) {
                    fgets(recentScores[scoreIndex], 100, file);
                    scoreIndex++;
                }
                fclose(file);  // Close the file after reading
            }

            // Clear the screen to display the "Game Over" message
            cleardevice();
            setbkcolor(8);  
            settextstyle(8, HORIZ_DIR, 9);  
            outtextxy(40, 50, "GAME OVER"); 

            // Display options for the user to play again or quit
            settextstyle(3, HORIZ_DIR, 2);  
            outtextxy(40, 250, "PLAY AGAIN (p)");  
            outtextxy(520, 250, "QUIT (q)"); 

            // Display recent scores
            settextstyle(4, HORIZ_DIR, 5); 
            outtextxy(240, 310, "SCORES");  
            settextstyle(5, HORIZ_DIR, 4);  
            outtextxy(200, 350, recentScores[0]); 
            outtextxy(200, 380, recentScores[1]);  
            outtextxy(200, 410, recentScores[2]);  

            // Wait for user input to either play again or quit
            while (1) {
                if (kbhit()) {
                    int c = getch();
                    if (c == 'p') {
                        initialize();  // Restart the game
                    } else if (c == 'q') {
                        exit(0);  // Exit the game
                    }
                }
            }
        }
    }
}

