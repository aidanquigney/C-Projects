/*==================================================================
 *
 *               University College Dublin
 *          EEEN20010 - Computer Engineering I
 *
 * File Name	:	rootcalc.c
 *
 * Description	: 	A program to estimate the roots of a quadratic function using a brute force method
 *
 * Author		:	Aidan Quigney
 *
 * Date			:	22-09-22
 *
 *==================================================================*/

#include <stdio.h>
#include <math.h>

char repeat = 'y'; /*Tells the function to repeat or not*/

float floatabs(float x){/* An absolute value function that works for floats*/
    if(x<0){
        x = -1 * x;
    }
    return x;
}


int main(void){
    while(repeat == 'y' || repeat == 'Y'){
        int a, b, c; /* Coefficients, read from user input*/
        printf("************************************************\n");
        printf("Welcome to the quadratic root estimator.\nThis estimates the value of one root of \nf(x)=ax^2+bx+c.\n");
        printf("************************************************\nEnter the coefficients in the form 'a b c:'");
        scanf("%d %d %d", &a, &b, &c);

        float range_min = -100;/*The minimum x to be inputted to the function*/
        float range_max = 100;/*The maximum x to be inputted to the function*/
        float step = .1;/*Resolution of input values*/
        float closest_root = range_min;
        float closest_out;
        float output;

        if(((b*b) - 4*a*c) <0){ /* If the user inputs coefficients with complex roots*/
            printf("Complex Roots - cannot estimate with this program\n");
        }
        else{
            for(float i = range_min; i<= range_max; i= i+step){/*Loop through all inputs*/
                output = a*(i*i) + b*(i) +c;
                if(i == range_min){ /* For the first input, name it the closest input*/
                    closest_out= output;
                }
                else{
                    if(floatabs(output)< floatabs(closest_out)){ /*If the output is closer to zero that the last closest, reset closest output and closest root*/

                        closest_out = output;
                        closest_root = i;
                    }
                }
            }
            printf("There is a root at %.3f\n", closest_root); /*Print results*/


        }
        int askrepeat = 1;
        while(askrepeat){
            printf("Do you wish to try another quadratic [y/n]:");

            scanf(" %c", &repeat);/* Read repeat character, if it is 'Y' or 'y', the function will repeat*/
            if(repeat != 'Y' &&repeat != 'y' &&repeat != 'N' &&repeat != 'n'){
                printf("Whoops, character not 'y' or 'n'.\n");
            }
            else{
                askrepeat = 0;
            }
        }printf("\n");
    }
}
