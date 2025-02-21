/*----------------------------------------------------------------------------
-		        SE 185: Lab 02 - Solving Simple Problems in C	    	 	 -
-	Name:	James Gaul																 -
- 	Section:	3															 -
-	NetID:	947125207															     -
-	Date:	2/2/24																 -
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
-								Includes									 -
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    /* Put your code after this line */
	
	printf("James Gaul\n");
	printf("CprE 185\n");
	printf("2/2/24\n");
	printf("\n");
	
	//double testVar = 3.0 * 3;
	//printf("Test multiplication: %lf\n", testVar);

	int aResult = 6427 + 1725;
	
	printf("a. Using integers, 6427 + 1725 = %d\n", aResult);
	
	
	int bResult = (6971 * 3925) + 95;
	
	printf("b. Using integers, (6971 * 3925) + 95 = %d\n", bResult);
	
	double cResult = 79 + 12 / 5;
	
	printf("c. Using doubles, 79 + 12 / 5 = %lf\n", cResult);
	
	
	double dResult = 3640.0 / 107.9;
	
	printf("d. Using doubles, 3640.0 / 107.9 = %lf\n", dResult);
	
	int eResult = (22/3) * 3;
	
	printf("e. Using integers, (22/3) * 3 = %d\n", eResult);
	
	int fResult = 22 / (3 * 3);
	
	printf("f. Using integers, 22 / (3 * 3) = %d\n", fResult);

	double gResult = 22 / (3 * 3);
	
	printf("g. Using doubles, 22 / (3 * 3) = %lf\n", gResult);
	
	double hResult = 22 / 3* 3;
	
	printf("h. Using doubles, 22 / 3 * 3 = %lf\n", hResult);
	
	
	double iResult = (22 / 3) * 3.0;
	
	printf("i. Using doubles, (22 / 3) * 3.0 = %lf\n", iResult);
	
	
	int jResult = 22.0 / (3 * 3.0);
	
	printf("j. Using integers, 22.0/(3 * 3.0) = %d\n", jResult);
	
	double kResult = 22.0 / 3.0 * 3.0;
	
	printf("k. Using doubles, 22.0 / 3.0 * 3.0 = %lf\n", kResult);
	
	printf("\n\n");
	
	double circleCircumference = 23.567;
	
	double circleRadius = .5 * (circleCircumference / 3.1415927);
	
	double circleArea = 3.1415927 * (circleRadius * circleRadius);
	
	printf("A circle with circumference %lf has an area of %lf\n\n", circleCircumference, circleArea);
	
	int lengthFeet = 14;
	double lengthMeters = lengthFeet * .3048;
	
	printf("%d feet in length equals %lf meters\n\n", lengthFeet, lengthMeters);
	
	int degreesFarenheit = 76;
	double degreesCelsius = ((degreesFarenheit - 32.0) * 5.0)/9.0;
	
	printf("%d degrees Farenheit is equal in temperature to %lf degrees Celsius\n\n", degreesFarenheit, degreesCelsius);



    return 0;
}
