#include <stdio.h>

int main(void){
    FILE *fpin;
    char *str;
    int amount;

    if ((fpin = fopen("t.txt", "r")) == NULL){ /*We let the fpin pointer point to the file, and if it NULL, we return an error*/
        printf("Cannot open file\n");
        exit(0);
    }

    fscanf(fpin, "%d", &amount);
    int phone1[amount];
    int phone2[amount];

    for(int i = 0; i<amount; i++){
        fscanf(fpin, "%d", &phone1[i]);
    }
    for(int i = 0; i<amount; i++){
        fscanf(fpin, "%d", &phone2[i]);
    }

    //find A avg


}
