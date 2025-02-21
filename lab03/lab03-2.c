/*----------------------------------------------------------------------------
-		    SE 185: Lab 03 - Introduction to the DS4 and Functions	    	 -
-	Name:	James Gaul																 -
- 	Section:	3															 -
-	NetID:	947125207															     -
-	Date:	2/09/24																 -
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
-								Includes									 -
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>

/*----------------------------------------------------------------------------
-	                            Prototypes                                   -
-----------------------------------------------------------------------------*/


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
	int triangleB;
	int circleB;
	int crossB;
	int squareB;
	int buttonCount;

    while (1)
    {
		scanf("%d,%d,%d,%d", &triangleB, &circleB, &crossB, &squareB);
		
		buttonCount = triangleB + circleB + crossB + squareB;
		printf("Currently there are %d buttons pressed\n", buttonCount);
		//fflush(stdout);

    }

    return 0;
}

/* Put your functions here, and be sure to put prototypes above. */

