/*----------------------------------------------------------------------------
-		        SE 185: Lab 02 - Solving Simple Problems in C	    	 	 -
-	Name: James Gaul																 -
- 	Section: 3														 -
-	NetID: 947125207												     -
-	Date: 2/23/24															 -
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
-								Includes									 -
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*-----------------------------------------------------------------------------
-                                Prototypes                                   -
------------------------------------------------------------------------------*/

int getSideUp(double x, double y, double z);
int close_to(double input, double value, double margin);

void printSideUp(int direction);

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    /* Put your code after this line */
	double accelX, accelY, accelZ, gyroX, gyroY, gyroZ;
	int bTriangle, bCircle, bCross, bSquare;
	
	int direction, prevDirection;
	
	prevDirection = 0;
	
	printf("Press the triangle button to exit:\n");
	bTriangle = 0;
	
	while (bTriangle == 0)
    {
		
		scanf("%lf, %lf, %lf, %lf, %lf, %lf,%d,%d,%d,%d", &accelX, &accelY, &accelZ, &gyroX, &gyroY, &gyroZ, &bTriangle, &bCircle, &bCross, &bSquare);
		
		//printf("GyroY = %lf\n", gyroY);
		
		direction = getSideUp(gyroX, gyroY, gyroZ);
		
		if((direction != prevDirection) && (direction != 0)){
			printSideUp(direction);
			prevDirection = direction;
		}
		
    }
	printf("Program has finished.\n");


    return 0;
}

void printSideUp(int direction){
	//printf("PrintSideUp running\n");
	switch(direction){
		
		case 1: printf("Up\n");
		break;
		
		case 2: printf("Down\n");
		break;
		
		case 3: printf("Right\n");
		break;
		
		case 4: printf("Left\n");
		break;
		
		case 5: printf("Front\n");
		break;
		
		case 6: printf("Back\n");
		break;
	}
	
}

int getSideUp(double x, double y, double z){
	//printf("getSideUp running\n");
	double tol = 0.2;
	
	int sideUp;
	
	if(close_to(y, 1.0, tol)){
		sideUp = 1;
	}
	else if (close_to(y, -1.0, tol)){
		sideUp = 2;
	}
	else if (close_to(x, 0.9, tol)){
		sideUp = 3;
	}
	else if (close_to(x, -0.9, tol)){
		sideUp = 4;
	}
	else if (close_to(z, -0.9, tol)){
		sideUp = 5;
	}
	else if (close_to(z, 0.9, tol)){
		sideUp = 6;
	}
	
	else{
		sideUp = 0;
	}
	
	return sideUp;
}

int close_to(double input, double value, double margin){
	if(fabs(value - input) <= margin){
		return 1;
	}
	else{
		return 0;
	}
}
