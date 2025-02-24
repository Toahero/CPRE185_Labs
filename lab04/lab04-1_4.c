/*----------------------------------------------------------------------------
-		                 SE 185: Lab 04 - Debugging Code	    	         -
-	Name: James Gaul																	 -
- 	Section: 3																 -
-	NetID: 947125207														     -
-	Date: 2/16/24																		 -
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
-								Includes									 -
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>

/*----------------------------------------------------------------------------
-	                                Notes                                    -
-----------------------------------------------------------------------------*/
// Compile with gcc lab04-1_4.c -o lab04-1_4
// Run with ./lab04-1_4
/* This program calculates the energy of one photon
 * of user-inputted wave-length of light */

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    //double speed_of_light!;
	double speed_of_light;
    //double wave-length;
	double waveLength;
    //double ~length_in_meters;
    double length_in_meters;
	//double plank const;
	double plankConst;
    //double 0energy;
	double energy;

    //plank const = 6.62606957 * pow(10, -34); // Planck's constant
    plankConst = 6.62606957 * pow(10, -34);
	//speed_of_light! = 2.99792458 * pow(10, 8); // Constant for the speed of light
	speed_of_light = 2.99792458 * pow(10, 8);
    //wave-length = 0;
	waveLength = 0;
    //~length_in_meters = 0;
	length_in_meters = 0;
	//0energy = 0;
	energy = 0;

    printf("Welcome! This program will give the energy, in Joules,\n");
    printf("of 1 photon with a certain wave-length.\n");
    printf("Please input a wave-length of light in nano-meters.\n");
    printf("Please do not enter a negative, or zero, wave-length.\n");

    //scanf("%lf", &wave-length);
	scanf("%lf", &waveLength);

    //if (wave-length > 0.0)
	if (waveLength > 0.0)
    {
        //~length_in_meters = wave-length / pow(10, 9); // Converting nano-meters to meters
        length_in_meters = waveLength / pow(10, 9);
		
		//0energy = (plank const * speed_of_light!) / ~length_in_meters; // Calculating the energy of 1 photon
        energy = (plankConst * speed_of_light);
		/*printf("A photon with a wave-length of %08.3lf nano-meters, carries "
               "\napproximately %030.25lf joules of energy.", wave-length, 0energy);
			 */
		printf("A photon with a wave-length of %08.3lf nano-meters, carries "
               "\napproximately %030.25lf joules of energy.", waveLength, energy);
    } else
    {
        printf("Sorry, you put in an invalid number.");
        printf("Please rerun the program and try again.");
    }

    return 0;
}
