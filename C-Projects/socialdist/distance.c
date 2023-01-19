#include <stdio.h>


int main(void){
    FILE *fpin;
    char *str;
    int amount;
    char filen[100];
    float n1, n2, distancearray[100];
    printf("Please enter file name ");
    scanf("%s", filen);

    if ((fpin = fopen(filen, "r")) == NULL){ /*We let the fpin pointer point to the file, and if it NULL, we return an error*/
        printf("Cannot open file\n");
        exit(0);
    }

    fscanf(fpin, "%d", &amount);
    printf("%d\n", amount);
    float points[amount][2];
    for(int i = 0; i<amount; i++){
        fscanf(fpin, "%f", &n1);
        fscanf(fpin, "%f", &n2);

        points[i][0] = n1;
        points[i][1] = n2;
    }
    //array print

    for (int i = 0; i < amount; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%f ", points[i][j]);
        }
        printf("\n");
    }
    //array for distance between points
    int p =0;
    for(int i =0; i< amount; i++){
        for(int j = i+1; j< amount; j++){
            float x1 = points[i][0];
            float y1 = points[i][1];
            float x2 = points[j][0];
            float y2 = points[i][1];
            float distance = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
            distancearray[p] = distance;
            p++;
        }
    }
    float lowest= distancearray[0];
    float total =0;
    for(int i =0; i<p; i++){
        if(distancearray[i]< lowest){
            lowest = distancearray[i];
        }
    }
    for(int i =0; i<p; i++){
        total = total + distancearray[i];
    }
    float mean = total/p;
    int satisfied = 1;
    for(int i =0; i<p; i++){
        if(distancearray[i] <=2){
            satisfied = 0;
        }
    }

    fclose(fpin);

    printf("There are %d points in the config given\n", amount);
    printf("The average distance between the points is %.2f meters\n", mean);
    printf("The min distance between the points is %.2f meters\n", lowest);
    if(satisfied){
        printf("The config satisfies the social distance guidelines\n");
    }else{
        printf("The config does not satisfy the social distance guidelines\n");
    }

}
