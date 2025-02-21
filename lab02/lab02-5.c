/*----------------------------------------------------------------------------
-		        SE 185: Lab 02 - Solving Simple Problems in C	    	 	 -
-	Name:	James Gaul																 -
- 	Section:	3															 -
-	NetID:	947125207															     -
-	Date:	02/02/24																 -
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
-								Includes									 -
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>   // Google this header file to learn more! :)

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    double a, b, c;
    double result;
	double aSquared;
	double bSquared;

    /* Put your code after this line */
	double sumOfSquares;
	
	printf("enter the first side length: ");
	scanf(" %lf", &a);
	
	printf("enter the second side length ");
	scanf(" %lf", &b);
	
	aSquared = pow(a, 2.0);
	bSquared = pow(b, 2.0);
	
	sumOfSquares = aSquared + bSquared;


    /* This next line will calculate the square root of whatever value is
     * inside the parenthesis and assigns it to the variable filler. */
    result = sqrt(sumOfSquares);
	printf("The third side length is %lf", result);

    return 0;
}
