/*==================================================================
 *
 *               University College Dublin
 *          EEEN20010 - Computer Engineering I
 *
 * File Name	:	flightcal.c
 *
 * Description	: 	A program to determine how long a flight will take in hours and minutes based on a given distance input
 *
 * Author		:	Aidan Quigney
 *
 * Date			:	22-09-22
 *
 *==================================================================*/
#include <stdio.h> 

#define mph 529

float speed = mph /  0.621371; /*Given 529 mph, divide by .621371 to get kmph*/
float distance; //user input

int main(void){
    printf("Enter the distance travelled by the aeroplane in kilometers: \n");
    scanf("%f", &distance); /*read distance float from user input*/
    float flightime = distance/speed; /*hours float */
    int hours = (int) flightime; /*removes any fraction portion of hours to find rounded down hours*/
    float nonroundint = (flightime - (hours)) * 60;
    if((nonroundint - ((int) nonroundint))>= .5){ /*add one to minutes if the fraction part is over .5 so it rounds correctly*/
        nonroundint ++;
    }
    int minutes = (nonroundint);
    printf("The aeroplane's flight time is %d hours and %d minutes.", hours, minutes); //return answer
}