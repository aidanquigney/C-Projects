/*==================================================================
 *
 *               University College Dublin
 *          EEEN20010 - Computer Engineering I
 *
 * File Name	:	trig.c
 *
 * Description	: 	A program to display a data table of values of sin(x) where x is an element of a set of numbers specified by the user
 *
 * Author		:	Aidan Quigney
 *
 * Date			:	03-11-22
 *
 *==================================================================*/

#include <stdio.h>
#define PI 3.141592654

/* For this code to work a few basic functions to manipulate floats are needed...*/

float floatabs(float x){/* An absolute value function for floats*/
    if(x<0){
        x = -1 * x;
    }
    return x;
}

float simplify_angle(float x){ /*A function to simplify an angle to its smallest accurate representation*/
    int stay = 1; /*The program will continue to subtract 2*pi while stay =1 */
    if(x>=0){ /* For positive angles*/
        while(stay ==1){
            if(x >= 2* PI){
                x = x - 2 * PI;
            }
            else{
                stay =0; /*Break out of the loop*/
            }
        }
    } else{/* For negative angles*/
        while(stay ==1){
            if(x <= -2* PI){
                x = x + 2 * PI;
            }
            else{
                stay =0;
            }
        }
    }
    return x;
}

float power(float base, float pow){ /*A function to raise any base float to any power*/
    float total = 1;
    for(int i = 1; i<=pow; i++){ /*Multiply base by itself "pow" amount of times*/
        total = total* base;
    }
    return total;
}

float fact(float x){ /*A factorial function for floats*/
    float total =1;
    for(;x>0; x--){
        total = total*x;
    }
    return total;
}

float calcsin(float x, float tolerance){ /*A function to find the sine of a float with a certain degree of accuracy specified by the tolerance*/
    float n = 0, answer = 0, term;
    int stay =1; /*Continue repeating the program while stay =1*/
    x = simplify_angle(x); /*Simplify the angle*/

    do{
        term = (pow(-1, n) * (pow(x, (2*n) +1)))/fact((2*n) +1);
        if(floatabs(term) >= tolerance){ /* Only if the term is greater than the tolerance will it be added*/
            answer = answer+ term;
            n+=1;
        }
        else
            stay = 0;
    }while(stay ==1);


    return answer;
}

void printout(float x_values[], float sinx_values[], int length){ /*Printout function to print a table containing the sine values*/
    printf("===============================\n| x (radians) |    sin(x)     |\n|=============================|\n");
    for(int i =0; i<length; i++){
        printf("|%9.4f    |%9.4f      |\n",x_values[i], sinx_values[i]);
    }
    printf("===============================\n");
}

int main(void){
    /*Read the upper, lower and step values from the user*/
    float lower, upper, step;
    printf("Enter the lower limit on x:");
    scanf("%f",&lower);
    printf("Enter the upper limit on x:");
    scanf("%f",&upper);
    printf("Enter the step size:");
    scanf("%f",&step);

    /*Create two arrays of length 50*/
    float x_values[50];
    float sinx_values[50];
    int index =0;

    float xval = lower; /*begin by setting the first x value to the lower input */

    while(index <= (int) ((upper - lower)/step)){ /*iterates for every input specified by user inputted data*/
        x_values[index] = xval; /*Fill x_values array*/
        sinx_values[index] = calcsin(xval, .000001);/*Fill sinx_values array*/
        index = index +1; /*Increment the index*/
        xval = xval + step;/*Increment x by step*/
    }
    if(index> 50){ /*Exit the program is list is longer than 50*/
        printf("List should be shorter than 50");
        exit(0);
    }


    printout(x_values, sinx_values, index);/* Run the printout function on our 2 arrays, and specify the index as length( it represents the length because it was incremented by 1 at the end of the while loop)*/
}
