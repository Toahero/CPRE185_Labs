/*----------------------------------------------------------------------------
-		    SE 185: Lab 03 - Introduction to the DS4 and Functions	    	 -
-	Name:	James Gaul																 -
- 	Section:	3															 -
-	NetID:	947125207															     -
-	Date:	2/9/24																 -
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
-								Includes									 -
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>

/*----------------------------------------------------------------------------
-	                            Prototypes                                   -
-----------------------------------------------------------------------------*/
double magnitude(double x, double y, double z);
int minutes(int time);
int seconds(int time);
int milliseconds(int time);

/*----------------------------------------------------------------------------
-	                                Notes                                    -
-----------------------------------------------------------------------------*/
// Compile with gcc lab03-1.c -o lab03-1
// Run with ./ds4rd.exe -d 054c:05c4 -D DS4_BT -t -a | ./lab03-1

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    /* DO NOT MODIFY THESE VARIABLE DECLARATIONS */
    int t;
    double ax, ay, az;
	double runTime;

    while (1)
    {
        scanf("%d, %lf, %lf, %lf", &t, &ax, &ay, &az);

        /* CODE SECTION 0 */
	   runTime = t /1000.0;
       printf("Echoing output: %0.3f, %0.4f, %0.4f, %0.4f\n", runTime, ax, ay, az);


        /* 	CODE SECTION 1 */
         //printf("At %d ms, the acceleration's magnitude was: %lf\n", t, magnitude(ax, ay, az));


        /* 	CODE SECTION 2 */
        
            //printf("At %d minutes, %d seconds, and %d milliseconds it was: %lf\n",
            //minutes(t), seconds(t), milliseconds(t), magnitude(ax, ay, az));
        
    }

    return 0;
}

/* Put your functions here */

/**
 * Calculates and returns the magnitude of three given values.
 *
 * @param x - The x-axis scanned values from the DS4 controller.
 * @param y - The y-axis scanned values from the DS4 controller.
 * @param z - The z-axis scanned values from the DS4 controller.
 * @return - The magnitude of the given values.
 */
double magnitude(double x, double y, double z)
{
    // Step 8, uncomment and modify the next line
	
    return sqrt(pow(2, x) + pow (2, y) + pow(2, z));
}
int minutes(int time){
	int minuteVal = time/60000;
	
	return minuteVal;
}

int seconds(int time){
	int remainder = time % 60000;
	
	return remainder / 1000;
}

int milliseconds(int time){
	int remainder = time % 60000;
	return remainder % 1000;
}

