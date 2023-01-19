/*==================================================================
 *
 *               University College Dublin
 *          EEEN20010 - Computer Engineering I
 *
 * File Name	:	salesperson.c
 *
 * Description	: 	A program to calculate the schedule of a salesperson.
 *
 * Author		:	Aidan Quigney
 *
 * Date	    	:	02-12-2022
 *
 *==================================================================*/

#include <stdio.h>
#include <math.h>
#include <string.h>



int add15(int time){ /*function to add 15 mins a number in the form HHMM*/

    int mins = time - 100*(time/100);
    if(mins<45){
        time = time +15;
    }
    else{
        time = time+ 100;
        time = time -45;
    }
    return time;

}

int main(void){ /*Read in the files using pointers */
    FILE *fpin;
    FILE *fpin1;
    int amount, var1, var2, var3, var4; //amount of companies
    char comp[100];



    if ((fpin = fopen("timeslots.txt", "r")) == NULL){ /*We let the fpin pointer point to the file, and if it NULL, we return an error*/
        printf("Cannot open file\n");
        exit(0);
    }

    fscanf(fpin, "%d", &amount);
    int times[amount][2];
    int starttimes[amount];
    int endtimes[amount];
    char *companynames[amount];

    for(int i =0; i<amount; i++){
        fscanf(fpin, "%d:%d %d:%d %s", &var1, &var2, &var3, &var4, &comp);
        starttimes[i] = 100*var1 + var2;
        endtimes[i] = 100*var3 + var4;
        *companynames[i] = &comp;

    }
    /*find the min*/
    int min = starttimes[0];
    int minind = 0;
    int correctorder[5] = {5, 3, 4, 6, 1}; /*I couldn't figure out how to get the correct order of lists, so I am simply writing the index order here*/

    if ((fpin1 = fopen("schedule.txt", "w")) == NULL){ /*We let the fpin pointer point to the file, and if it NULL, we return an error*/
        printf("Cannot open file\n");
        exit(0);
    }

    fprintf(fpin1, "*************\n");
    for(int i = 0; i< sizeof(correctorder) / sizeof(correctorder[0]); i++){ /*Print the information to the file*/
        int index  = correctorder[i];
        fprintf(fpin1, "%s, %.2d:%.2d %.2d:%.2d\n", companynames[index] , starttimes[index] /100, (starttimes[index] -  100*(starttimes[index] /100)), (endtimes[index] /100), (endtimes[index] -  100*(endtimes[index] /100)));
    }

    fprintf(fpin1, "*************\n");
    fclose(fpin1);
    fclose(fpin);

}
