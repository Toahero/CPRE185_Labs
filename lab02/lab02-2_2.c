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
	
	int x, y, z;
	
	printf("Enter a width: ");
	scanf(" %d", &x);
	printf("Enter a length: ");
	scanf(" %d", &y);
	printf("Enter a height: ");
	scanf(" %d", &z);
	printf("\n");
	printf("A %d by %d by %d rectangular prism's volume is %d\n", x, y, z, x*y*z);




    return 0;
}
