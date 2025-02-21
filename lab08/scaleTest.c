/*----------------------------------------------------------------------------
-		        Quiz 3 - Question 1	    	 	 -
-	Name:	James Gaul																 -
- 	Section:	3															 -
-	NetID:	947125207															     -
-	Date:	2/13/24																 -
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
-								Includes									 -
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
   
int scaleMagForScreen(double rad);

int main() {
	
	while(1){
		double input;
		int output;
	
		printf("\nEnter an input float: ");
		scanf(" %lf", &input);
	
		output = scaleMagForScreen(input);
	
		printf("\nThe output value is: %d\n", output);
	}
	
	
	return 0;
}

int scaleMagForScreen(double rad){
	
	//This needs a lot of work
	
	
	double radians = ((rad + 1) * PI);
	
	int degrees = radians * (180.0 / PI);
	
	return degrees;
}