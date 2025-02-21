#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define HIGH_SCORE_FILENAME "testScoreboard.txt"

typedef struct{
	char initials[3];
	int score;
}highScore;

void initHighScores();
void updateHighScores(int playerScore, highScore scoreArray[]);

void printHighScores(highScore scoreArray[]);
void readHighScores(highScore scoreArray[]);

void saveHighScores(highScore scoreArray[]);


int main(){
	
	initHighScores();
	
	highScore scoreBoard[10];
	
	printf("Loading file: %s", HIGH_SCORE_FILENAME);
	readHighScores(scoreBoard);
	printHighScores(scoreBoard);
	
	return 0;
}

void readHighScores(highScore scoreArray[]){
	FILE *fptr;
	
	char currentInitials[3];
	int currentScore;
	
	fptr = fopen(HIGH_SCORE_FILENAME, "r");
	
	for(int i = 0; i < 10; i++){
		fscanf(fptr, "%s %d", currentInitials, &currentScore);
		scoreArray[i].score = currentScore;
		strcpy(scoreArray[i].initials, currentInitials);
	}
	fflush(stdout);
	fclose(fptr);
}

void updateHighScores(int playerScore, highScore scoreArray[]){
	
	if(playerScore <= scoreArray[10-1].score){
		printf("You didn't get a high score.\n");
		return;
	}
	int i;
	char playerInitials[3] = "SUB";
	
	printf("You got a high score!\n");

	for(i = 10 - 1; i >= 0; i--){
		if(i < scoreArray[i].score){
			break;
		}			
	}
	
	for (int j = 10 - 1; j > i; j--){
		strcpy(scoreArray[j].initials, scoreArray[j-1].initials);
		scoreArray[j].score = scoreArray[j-1].score;
	}
	
	scoreArray[i].score = playerScore;
	strcpy(scoreArray[i].initials, playerInitials);
}

void printHighScores(highScore scoreArray[]){
	printf("\n   HIGH SCORES   \n\n");
	
	for(int i = 0; i < 10; i++){
		printf("%s %d\n", scoreArray[i].initials, scoreArray[i].score);
	}
	printf("------------------\n");
}

void saveHighScores(highScore scoreArray[]){
	FILE *fptr;
	
	fptr = fopen(HIGH_SCORE_FILENAME, "w");
	
	for(int i = 0; i < 10; i++){
		fprintf(fptr, "%s %d\n", scoreArray[i].initials, scoreArray[i].score);
	}
}

void initHighScores(){
	FILE *fptr;
	
	highScore blankScore;
	
	strcpy(blankScore.initials, "AAA");
	blankScore.score = 0;
	
	fptr = fopen(HIGH_SCORE_FILENAME, "w");
	
	for(int i = 0; i < 10; i++){
		fprintf(fptr, "%s %d\n", blankScore.initials, 10-i);
	}
	
	fclose(fptr);
}