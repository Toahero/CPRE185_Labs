/*----------------------------------------------------------------------------
-		    SE 185: Lab 06 - Bop-It!	    	 
-	Name:	James Gaul																 
- 	Section: 3															 
-	NetID:	947125207															     
-	Date:	3/01/24																 
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
-								Includes									 -
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*----------------------------------------------------------------------------
-	                            Prototypes                                   -
-----------------------------------------------------------------------------*/
void waitForButtonPress();

void waitForButtonRelease();

void delayFor(int milliseconds);

void requestButtonPress(int requestedButton);

int gameRound(int targetButton, int timeLimit);

int checkButton(int targetButton, int button0, int button1, int button2, int button3);

/*----------------------------------------------------------------------------
-	                                Notes                                    -
-----------------------------------------------------------------------------*/
// Compile with gcc lab03-2.c -o lab03-2
// Run with ./ds4rd.exe -d 054c:05c4 -D DS4_BT -b | ./lab03-2

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
	int roundTime = 5000;
	
	printf("Press any button to start!\n");
	waitForButtonPress();
	delayFor(1000);

	int continueGame = 1;
	int gameScore = 0;
	
	int targetButton;
	
	while (continueGame == 1){
		targetButton = (rand() % 4);
		
		continueGame = gameRound(targetButton, roundTime);
		
		if (continueGame == 1){
			gameScore++;
			roundTime -= (roundTime / 10);
		}
		
	}
	printf("Game Over!\n");
	printf("You had %d correct inputs!", gameScore);
	
    return 0;
}

/* Put your functions here, and be sure to put prototypes above. */



void waitForButtonPress(){
	int button0, button1, button2, button3, buttonCount;
	while (1){
		scanf("%*d, %d,%d,%d,%d", &button0, &button1, &button2, &button3);
		buttonCount = button0 + button1 + button2 + button3;
		if (buttonCount > 0){
			break;
		}
	}
}

void delayFor(int milliseconds){
	int startTime, currentTime;
	scanf("%d, %*d,%*d,%*d,%*d", &currentTime);
	startTime = currentTime;
	
	while((currentTime - startTime) < milliseconds){
		scanf("%d, %*d,%*d,%*d,%*d", &currentTime);
	}
}

int gameRound(int targetButton, int timeLimit){
	
	int currentTime, triangleB, circleB, crossB, squareB, buttonCount;
	int buttonPressed = 0;
	
	
	scanf("%d, %d,%d,%d,%d", &currentTime, &triangleB, &circleB, &crossB, &squareB);

	int timeCutoff = currentTime + timeLimit;
	
	requestButtonPress(targetButton);
	printf("you have %d milliseconds to respond!\n", timeLimit);
	
	
	while((currentTime < timeCutoff)){
		
		scanf("%d, %d,%d,%d,%d", &currentTime, &triangleB, &circleB, &crossB, &squareB);
		
		buttonPressed = checkButton(targetButton, triangleB, circleB, crossB, squareB);
		
		if(buttonPressed == 1){
			printf("Correct!\n");
			delayFor(100);
			return 1;
		}
		if(buttonPressed == 2){
			printf("Wrong one!\n");
			delayFor(100);
			return 0;
		}
	}
	
	printf("Out of time!\n");
	delayFor(50);
	return 0;
	
}

int checkButton(int targetButton, int button0, int button1, int button2, int button3){
	
	if(targetButton == 0){ //the triangle button is the goal
		
		if((button0 == 1) && (button1 + button2 + button3 == 0)){
			return 1;
		}
		else if(button1 + button2 + button3 > 0){
			return 2;
		}
		else{
			return 0;
		}
	}
	
	if(targetButton == 1){ //the circle button is the goal
		if((button1 == 1) && (button0 + button2 + button3 == 0)){
			return 1;
		}
		else if(button0 + button2 + button3 > 0){
			return 2;
		}
		else{
			return 0;
		}
	}
	
	if(targetButton == 2){ //the cross button is the goal
		if((button2 == 1) && (button0 + button1 + button3 == 0)){
			return 1;
		}
		else if(button0 + button1 + button3 > 0){
			return 2;
		}
		else{
			return 0;
		}
	}
	
	if(targetButton == 3){ //the square button is the goal
		if((button3 == 1) && (button0 + button1 + button2 == 0)){
			return 1;
		}
		else if(button0 + button1 + button2 > 0){
			return 2;
		}
		else{
			return 0;
		}
	}
	
	printf("Invalid target button %d", targetButton);
	return 0;
}

void requestButtonPress(int requestedButton){
	switch(requestedButton){
		case 0:
			printf("Press the Triangle, ");
			break;
			
		case 1:
			printf("Press the Circle, ");
			break;
			
		case 2:
			printf("Press the Cross, ");
			break;
			
		case 3:
			printf("Press the Square, ");
			break;
			
		default:
			printf("Error, invalid input of %d\n", requestedButton);
	}	
}