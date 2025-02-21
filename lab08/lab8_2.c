/*-----------------------------------------------------------------------------
-					  		SE 185 Lab 08
-             Developed for 185-Rursch by T.Tran and K.Wang
-	Name: James Gaul
- 	Section: 3
-	NetID: 947125207
-	Date: 4/22/24
-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
-								Includes
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>
#include <ncurses/ncurses.h>
#include <unistd.h>


/*-----------------------------------------------------------------------------
-								Defines
-----------------------------------------------------------------------------*/
/* Mathmatical constants */
#define PI 3.14159

/* 	Screen geometry
    Use ROWS and COLUMNS for the screen height and width (set by system)
    MAXIMUMS */
#define COLUMNS 100
#define ROWS 80

/* 	Character definitions taken from the ASCII table */
#define AVATAR 'A'
#define WALL '*'
#define EMPTY_SPACE ' '

/*	Number of samples taken to form an moving average for the gyroscope data
    Feel free to tweak this. */
#define NUM_SAMPLES 10

#define MOVE_FREQUENCY 30


/*-----------------------------------------------------------------------------
-								Static Data
-----------------------------------------------------------------------------*/
/* 2D character array which the maze is mapped into */
char MAZE[COLUMNS][ROWS];


/*-----------------------------------------------------------------------------
-								Prototypes
-----------------------------------------------------------------------------*/
/*	POST: Generates a random maze structure into MAZE[][]
    You will want to use the rand() function and maybe use the output %100.
    You will have to use the argument to the command line to determine how
    difficult the maze is (how many maze characters are on the screen). */
void generate_maze(int difficulty);

/*	PRE: MAZE[][] has been initialized by generate_maze()
    POST: Draws the maze to the screen */
void draw_maze(void);

/*	PRE: 0 < x < COLUMNS, 0 < y < ROWS, 0 < use < 255
    POST: Draws character use to the screen and position x,y */
void draw_character(int x, int y, char use);

/*	PRE: -1.0 < mag < 1.0
    POST: Returns tilt magnitude scaled to -1.0 -> 1.0
    You may want to reuse the roll function written in previous labs. */
double calc_roll(double mag);

/* 	Updates the buffer with the new_item and returns the computed
    moving average of the updated buffer */
double m_avg(double buffer[], int avg_size, double new_item);


//Function copied from lab7
int scaleMagForScreen(double rad);

//Self made functions

void read_input( int* time, double* g_x, double* g_y, double* g_z);

/*-----------------------------------------------------------------------------
-								Implementation
-----------------------------------------------------------------------------*/
/*	Main - Run with './ds4rd.exe -t -g -b' piped into STDIN */
void main(int argc, char* argv[])
{
	int time, i;
	double rawX, rawY, rawZ;
	double avgX, avgY, avgZ;
	
	double yBuffer[NUM_SAMPLES];

	int xMovement;
	int yMovement = 1;
	
	int xCoord;
	int yCoord;
	
  if (argc != 2 )
  {  
      printw("You must enter the difficulty level on the command line.");
      refresh();
      return;
  }
  else
  {
    /* 	Setup screen for Ncurses
        The initscr functionis used to setup the Ncurses environment
        The refreash function needs to be called to refresh the outputs
        to the screen */
    initscr();
    refresh();

    /* WEEK 2 Generate the Maze */

    /* Read gyroscope data and fill the buffer before continuing */
	
	
	for(i = 0; i < NUM_SAMPLES; i++){
		read_input(&time, &rawX, &rawY, &rawZ);
		yBuffer[i] = rawY;
		refresh();
	}

    /* Event loop */
    do
    {

        /* Read data, update average */
		read_input(&time, &rawX, &rawY, &rawZ);
		avgY = m_avg(yBuffer, NUM_SAMPLES, rawY);

        /* Is it time to move?  if so, then move avatar */
		if(time % MOVE_FREQUENCY == 0){
			xMovement = scaleMagForScreen(avgY);
			
			xCoord += xMovement;
			yCoord += yMovement;
			draw_character(xCoord, yCoord, AVATAR);
		}

    } while(1); // Change this to end game at right time

    /* Print the win message */


    /* This function is used to cleanup the Ncurses environment.
    Without it, the characters printed to the screen will persist
    even after the progam terminates */
    endwin();

  }

    printf("YOU WIN!\n");
}




/* 	PRE: 0 < x < COLUMNS, 0 < y < ROWS, 0 < use < 255
    POST: Draws character use to the screen and position x,y
    THIS CODE FUNCTIONS FOR PLACING THE AVATAR AS PROVIDED.
    DO NOT NEED TO CHANGE THIS FUNCTION. */
void draw_character(int x, int y, char use)
{
    mvaddch(y,x,use);
    refresh();
}

/*
	These are functions copied in from previous programs
*/
double m_avg(double buffer[], int avg_size, double new_item)
{
	int i;
	double sum = 0;
	
	for(i = avg_size - 1; i > 0; i--){
		buffer[i] = buffer[i-1];
	}
	buffer[0] = new_item;
	
	for(i = 0; i < avg_size; i++){
		sum += buffer[i];
	}
	
	return (sum / avg_size);
}

int scaleMagForScreen(double rad){
	
	//This needs a lot of work
	
	double offset = 1.0;
	double scale = 10;
	
	double adjustedVal = rad + offset;
	
	if(adjustedVal < 1.0){
		adjustedVal -= 2.0;
	}
	
	int scaledVal = adjustedVal * scale;
	
	return scaledVal;
}

void read_input(int* time, double* g_x, double* g_y, double* g_z){
	scanf("%d, %lf, %lf, %lf\n",  time, g_x, g_y, g_z);
	fflush(stdout);
}