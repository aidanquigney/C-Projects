/*==================================================================
 *
 *               University College Dublin
 *          EEEN20010 - Computer Engineering I
 *
 * File Name	:	root.c
 *
 * Description	: 	A program to estimate the roots of a cubic using a bisector method.
 *
 * Author		:	Aidan Quigney
 *
 * Date			:	13-10-22
 *
 *==================================================================*/

#include <stdio.h>

float cubic(float a,float b,float c,float d, float input){ /*Function outputs the cubic value given input and coefficients*/
    return (a*(input * input * input)) + (b*(input * input)) + (c*input) + d;

}

int main(void){
    char userin;
    do{
        float a,b,c,d;
        /*This block of code prints to the terminal, and reads user input*/
        printf("************************************************\n");
        printf("Welcome to the cubic root estimator.\n");
        printf("This estimates the value of one root of\n");
        printf("f(x)=ax^3+bx^2+cx+d.");
        printf("************************************************\n");
        printf("Enter the coefficients in the form 'a b c d': ");
        scanf("%f %f %f %f", &a, &b, &c, &d);

        /*Set the lower and upper limits of x to find the root in*/
        float lower = -1;
        float upper= 1;


        /*Sets the lower and upper output, and an int which is 1 or 0 if the output is positive or negative respectively*/
        float lowerout = cubic(a,b,c,d, lower);
        int lowerpos = (lowerout>0);
        float upperout = cubic(a,b,c,d, upper);
        int upperpos = (upperout>0);

        float bisector;
        float bisectorout;
        int bisectorpos;

        /*Increases the range until the lower and upper output are different signs (so the root is somewhere in the middle)*/
        while (lowerpos == upperpos){
            lower = lower - 5;
            upper = upper +5;
            lowerout =cubic(a,b,c,d, lower);
            upperout =cubic(a,b,c,d, upper);
            upperpos = (upperout>0);
            lowerpos = (lowerout>0);
        }



        for(int i =0; i<= 1000; i++){ /* Repeat the process below 1000 times*/

            bisector = (upper + lower)/2; /*Find the bisector input (x value)*/
            bisectorout = cubic(a,b,c,d, bisector);/*bisector ouput (y value)*/
            bisectorpos = (bisectorout>0); /* Like earlier, this is 1 is output is positve or 0 if negative*/
            lowerpos = (lowerout>0);
            upperpos = (upperout>0);
            /*This block checks to see if the bisector should be the new lower or upper input to home in on the root*/
            if(bisectorpos == 1){
                if(upperpos ==1){
                    upper = bisector;
                    upperout = bisectorout;
                }
                else if(lowerpos ==1){
                    lower = bisector;
                    lowerout = bisectorout;
                }
                else{
                    printf("broken");
                    return(0);
                }
            }else if(bisectorpos ==0){
                if(upperpos ==1){
                    lower = bisector;
                    lowerout = bisectorout;
                }
                else if(lowerpos ==1){
                    upper = bisector;
                    upperout = bisectorout;
                }
                else{
                    printf("broken");
                    return(0);
                }
            }
        }
        /*Print the root (aka the bisector)*/
        printf("There is a root at: %f\n", bisector);
        printf("Do you wish to try another cubic [y/n]: ");
        /*Read the character to see if the user wants to try another cubic*/
        getchar(); /*Swallow new line*/
        userin = getchar();

    }while(userin == 'y' || userin =='Y');

}
