/*==================================================================
 *
 *               University College Dublin
 *          EEEN20010 - Computer Engineering I
 *
 * File Name	:	flight.c
 *
 * Description	: 	A program to display a data table stating how long it will take a plane to travel a certian distance in hours and minutes
 *
 * Author		:	Aidan Quigney
 *
 * Date			:	29-09-22
 *
 *==================================================================*/

#include <stdio.h>
#define mph 529

float speed = mph /  0.621371; /*Given 529 mph, divide by .621371 to get kmph*/



int main(void){
    /*Get user input values for lower limit, upper limit and step of the table. Make sure input is a number*/

    float lower, upper, step;
    printf("Enter the lower limit on distance in km:");
    if (!scanf("%f", &lower)){ /*Reads lower limit, Ensures that scanf has been given a valid input */
        printf("Invalid Input");
        exit(0); /* Exits the program is the input is invalid*/
    }
    printf("Enter the upper limit on distance in km:");
    if (!scanf("%f", &upper)){/*Reads upper limit, Ensures that scanf has been given a valid input */
        printf("Invalid Input");
        exit(0);
    }
    printf("Enter the step size in km:");
    if (!scanf("%f", &step)){/*Reads step, Ensures that scanf has been given a valid input */
        printf("Invalid Input");
        exit(0);
    }


    if(upper>lower&& step>0 && upper >0 && lower >0){ /* Only print the table if: upper limit is greater than lower limit, and all inputs are positive numbers */
        printf("\n===============================================\n");
        printf("| distance (km) |    hours     |    minutes   |\n");
        printf("|=============================================|\n");
        float flightime, nonroundint;
        int hours, minutes;
        for(float i= lower; i<= upper; i = i+ step){ /*for each line in the table, run the following calculation to get hours and minutes, and print result*/
            flightime = i/speed;
            hours = (int) flightime;
            nonroundint = (flightime - (hours)) * 60;
            if((nonroundint - ((int) nonroundint))>= .5){ /*add one to minutes if the fraction part is over .5 so it rounds correctly*/
                nonroundint ++;
            }

            minutes = (nonroundint);
            if(minutes == 60){ //Convert 60 minutes to 1 hour
                minutes = minutes -60;
                hours = hours +1;
            }
            printf("|%11.2f    |%8d      |%8d      |\n", i, hours, minutes); /* print with formatting*/
        }
        printf("===============================================");
    }else{ /*if input is invalid*/
        printf("One of these inputs are not not valid");
    }
}
