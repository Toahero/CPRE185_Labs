/*----------------------------------------------------------------------------
-		        SE 185: Lab 02 - Solving Simple Problems in C	    	 	 -
-	Name:	James Gaul																 -
- 	Section:	3															 -
-	NetID:		947125207														     -
-	Date:		02/02/24															 -
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
-								Includes									 -
-----------------------------------------------------------------------------*/
#include <stdio.h>

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    int integer_result;
    double decimal_result;

    integer_result = 77 / 5;
    printf("The value of 77/5 is %d, using integer math.\n", integer_result);
	//changed %lf to %d

    integer_result = 2 + 3;
    printf("The value of 2+3 is %d.\n", integer_result);
	//added ", integer_result" to the printf command

    decimal_result = 1.0 / 22.0;
    printf("The value 1.0/22.0 is %lf.\n", decimal_result);
	//changed %d to %lf

    return 0;
}
