/*----------------------------------------------------------------------------
-		         SE 185: Midterm Project   	               -
- List the names of all team members, their roles, and their participation
1- Student 1 - James Gaul Role: Quiz Creator and debugger - Participation: 100%													                                     -
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
-								Includes									                                   -
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define questionPoints 5
#define numQuestions 3

/*----------------------------------------------------------------------------
-	                            Functions Prototypes                                   -
-----------------------------------------------------------------------------*/
int quizNumber(void);
int takeQuiz(int quizNum);

int quizOne(void);
int quizTwo(void);
int quizThree(void);

int trueFalseQuestion(char questionText[200], int correctAnswer);
int multipleChoiceQuestion(char questionText[200], char correctAnswer, char answerArray[4][100]); 
int fillBlankQuestion(char questionText[200], char correctAnswer[20]);

/*----------------------------------------------------------------------------
-	                                Notes                                    -
-----------------------------------------------------------------------------*/

// Compile with gcc midtermProject.c -o proj

/*----------------------------------------------------------------------------
-								Implementation								                               -
-----------------------------------------------------------------------------*/
int main()
{
	int quizTotal, quizScore, quizAttempts, selectedQuiz, pointsPossible;
	int overallScore = 0, overallAttempts = 0, overallPoints = 0;
	
	double avgScore, overallAverage;
	char quizAgain;
	
	while (1){
		quizTotal = 0;
		quizAttempts = 0;
		avgScore = 0.0;
		selectedQuiz = quizNumber();
		while (1){
			quizScore = takeQuiz(selectedQuiz);
			quizAttempts++;
			quizTotal += quizScore;
			printf("\nYou scored %d out of %d!\n\n", quizScore, questionPoints*numQuestions);
			
			pointsPossible = quizAttempts * questionPoints * numQuestions;
			avgScore = ((double)quizTotal / pointsPossible)*100.0;
			/*
			printf("Total score: %d\n", quizTotal);
			printf("Possible Points: %d\n", pointsPossible);
			*/
			printf("Your average is %.2f%%\n\n", avgScore);
			
			if (quizScore == questionPoints*numQuestions){
				overallScore += quizTotal;
				overallAttempts += quizAttempts;
				break;
			}
			printf("You'll have to take the quiz again\n\n");
		}
		
		overallPoints = overallAttempts * questionPoints * numQuestions;
		overallAverage = (((double) overallScore) / overallPoints)* 100.0;
		
		printf("In total, you have scored %d points out of %d points possible.\n", overallScore, overallPoints);
		printf("Your average for all quizzes taken is %.2f%%\n", overallAverage);
		printf("Would you like to take another quiz? Enter y/n: ");
		scanf(" %c", &quizAgain);
		printf("\n");
		
		if (quizAgain == 'n'){
			break;
		}
	}
	printf("\nYour final average was %.2f%%\n", overallAverage);
	
	printf("\nGoodbye!");
    return 0;
}

/* Put your functions here, and be sure to put prototypes above. */
int quizNumber(){
	int userInput;
	int randomOutput;
	printf("Enter a lucky number between 1 and 9! ");
	scanf(" %d", &userInput);
	
	srand(userInput * 3);
	randomOutput = rand() % 3;
	printf("The random output is %d\n", randomOutput);
	return randomOutput;
}
int takeQuiz(int quizNum){
	int score = 0;
	switch (quizNum){
		case 0:
			score = quizOne();
			break;
		
		case 1:
			score = quizTwo();
			break;
		
		case 2:
			score = quizThree();
			break;
		
		default:
			printf("Error: quiz number %d does not exist.\n", quizNum);
			break;
	}
	return score;
}

int quizOne(void){
	int score = 0;
	char answerArray[4][100];
	
	//set the quiz name/number here:
	int quizNum = 1;
	char quizName[] = "Computer Coding with C";
	
	//Set the true/false question here
	char question1[200] = "the name C comes from an earlier coding language named B";
	
	int trueFalseAnswer = 1;
	
	//Set the multiple choice questions/answers here:
	char question2[200] = "What symbol does C use to group code into blocks (such as if statements, functions, and loops)";
	strcpy(answerArray[0], "A:Square Brackets []");
	strcpy(answerArray[1], "B:Parentheses ()");
	strcpy(answerArray[2], "C:Curly Braces {}");
	strcpy(answerArray[3], "D:Indentations ->");
	char multChoiceAnswer = 'c';
	
	//set the fill in the blank question here:
	char question3[200] = "What variable type stores floating point variables in eight bytes of data";
	char fillBlankAnswer[] = "double";
	
	
	printf("\n\nQuiz #%d: %s\n==============================\n\n", quizNum, quizName);
	
	//ask the true/false question
	score += trueFalseQuestion(question1, trueFalseAnswer) * questionPoints;
	printf("\n\n");
	//ask the multiple choice question
	score += multipleChoiceQuestion(question2, multChoiceAnswer, answerArray) * questionPoints;
	printf("\n\n");
	score += fillBlankQuestion(question3, fillBlankAnswer) * questionPoints;
	
	
	printf("\nQuiz complete\n");
	return score;
}

int quizTwo(void){
	int score = 0;
	char answerArray[4][100];
	
	//set the quiz name/number here:
	int quizNum = 2;
	char quizName[] = "Iowa State CprE";
	
	//Set the true/false question here
	char question1[200] = "Coover Hall was constructed in 1999";
	int trueFalseAnswer = 0;
	
	//Set the multiple choice questions/answers here:
	char question2[200] = "Which statement is commonly displayed in a programming student's first code";
	strcpy(answerArray[0], "A:Hello World!");
	strcpy(answerArray[1], "B:The Quick Brown Fox...");
	strcpy(answerArray[2], "C:It is a period of civil wars in the galaxy...");
	strcpy(answerArray[3], "D:Friends, Romans, Countrymen, lend me your ears...");
	char multChoiceAnswer = 'a';
	
	//set the fill in the blank question here:
	char question3[200] = "what insect is displayed outside Coover Hall at ISU";
	char fillBlankAnswer[] = "moth";
	
	
	printf("\n\nQuiz #%d: %s\n==============================\n\n", quizNum, quizName);
	
	//ask the true/false question
	score += trueFalseQuestion(question1, trueFalseAnswer)*5;
	printf("\n\n");
	//ask the multiple choice question
	score += multipleChoiceQuestion(question2, multChoiceAnswer, answerArray)*5;
	printf("\n\n");
	score += fillBlankQuestion(question3, fillBlankAnswer)*5;
	
	printf("\nQuiz complete\n");
	return score;
}

int quizThree(void){
	int score = 0;
	char answerArray[4][100];
	
	//set the quiz name/number here:
	int quizNum = 3;
	char quizName[] = "Iowa State Campus";
	
	//Set the true/false question here
	char question1[200] = "When build, the Marston water tower was the second steel water tower west of the Missippi";
	int trueFalseAnswer = 0;
	
	//Set the multiple choice questions/answers here:
	char question2[200] = "What year was Iowa State founded?";
	strcpy(answerArray[0], "A: 1822");
	strcpy(answerArray[1], "B: 1858");
	strcpy(answerArray[2], "C: 1901");
	strcpy(answerArray[3], "D: 1950");
	char multChoiceAnswer = 'b';
	
	//set the fill in the blank question here:
	char question3[200] = "What is the last name of the Four Seasons Fountain's sculptor?";
	char fillBlankAnswer[] = "peterson";
	
	
	printf("\n\nQuiz #%d: %s\n==============================\n\n", quizNum, quizName);
	
	//ask the true/false question
	score += trueFalseQuestion(question1, trueFalseAnswer)*5;
	printf("\n\n");
	//ask the multiple choice question
	score += multipleChoiceQuestion(question2, multChoiceAnswer, answerArray)*5;
	printf("\n\n");
	score += fillBlankQuestion(question3, fillBlankAnswer)*5;
	
	printf("\nQuiz complete\n");
	return score;
}

int trueFalseQuestion(char questionText[200], int correctAnswer){
	char userInput;
	printf("Is the following statement true (enter 't') or false (enter 'f')?\n\n");
	printf("True or false: %s\n", questionText);
	scanf(" %c", &userInput);
	printf("\n");
	if((correctAnswer == 0) && ((userInput == 'f') || (userInput == 'F'))){
		printf("Correct!\n");
		return 1;
	}
	else if((correctAnswer == 1) && ((userInput == 't') || (userInput == 'T'))){
		printf("Correct!\n");
		return 1;
	}
	else{
		printf("Incorrect.\n");
		return 0;
	}
	
}

int multipleChoiceQuestion(char questionText[200], char correctAnswer, char answerArray[4][100]){
	char userAnswer;
	
	printf("Indicate the correct answer with: 'a' 'b' 'c' or 'd'\n\n");
	printf("%s?\n", questionText);
	
	for(int i = 0; i < 4; i++){
		printf("%s\n", answerArray[i]);
	}
	
	scanf(" %c", &userAnswer);
	printf("\n");
	userAnswer = tolower(userAnswer);
	
	if (userAnswer == correctAnswer){
		printf("Correct!\n");
		return 1;
	}
	else{
		printf("Incorrect.\n");
		return 0;
	}	
}

int fillBlankQuestion(char questionText[200], char correctAnswer[20]){
	char userAnswer[20];
	printf("Type in the answer to the question:\n\n");
	printf("%s?\n", questionText);
	
	scanf(" %s", userAnswer);
	
	for (int i = 0; i < strlen(userAnswer); i++){
		userAnswer[i] = tolower(userAnswer[i]);
	}
	
	if (strcmp(userAnswer, correctAnswer) == 0){
		printf("Correct!");
		return 1;
	}
	else{
		printf("Incorrect.");
		return 0;
	}
}