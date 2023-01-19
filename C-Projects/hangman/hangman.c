/*==================================================================
 *
 *               University College Dublin
 *          EEEN20010 - Computer Engineering I
 *
 * File Name	:	hangman.c
 *
 * Description	: 	A program to simulate the game of hangman.
 *
 * Author		:	Aidan Quigney
 *
 * Date	    	:	22-11-2022
 *
 *==================================================================*/

#include <stdio.h>
#include <string.h>
#define MAXLINE 256

char wordorletter(){ /*This function will read and return a w or an l from the keyboard*/
    char read;
    printf("Would you like to guess the word[w] or guess a letter [l]:");
    getchar(); /*This line is necessary to eat the newline */
    read = getchar();
    return read;
}


void hangman(){ /* The whole game is stored in this function*/
    char userfile[20]; /*string to hold the filename containing the word*/
    printf("Give the filename with the unknown word: ");
    scanf("%s", userfile);/*Read filename from keyboard*/

    FILE *fpin;
    char *str;
    char word[MAXLINE];
    int turns = 10;

    if ((fpin = fopen(userfile, "r")) == NULL){ /*We let the fpin pointer point to the file, and if it NULL, we return an error*/
        printf("Cannot open file\n");
        exit(0);
    }
    if(str = fgets(word, MAXLINE, fpin) == NULL){ /*We let the word in the file become the "word" variable, and if fgets returns NULL, we return an error*/
        printf("Fail");
        exit(0);
    }

    printf("Ready to Start!\n");
    int length = strlen(word); /*Length holds the lenght of the word*/
    char blurred[length];/*make the blurred string*/

    for(int i =0; i<length; i++){ /*Creates a blurred string, the same length as the word*/
        blurred[i] = '*';
    }
    blurred[length] = '\0';/*End the string*/

    printf("The word is: %s\n\n", blurred);
    printf("Number of turns remaining: %d\n", turns);

    while(turns>0){ /*We will do whats in the loop until there are no turns left*/
        char choice = wordorletter(); /*Returns a 'w' or 'l'*/
        if (choice == 'l'){ /* If the person picks 'l'*/
            int goodchoice =0; /* This variable is 0 when the users letter is a bad choice, and 1 when it is a good choice*/
            printf("What letter have you chosen?:");
            getchar(); /* Eat the newline*/
            char l =getchar();
            printf("***********************************************\n");
            for(int i=0; i<length; i++){ /* For each letter in the word*/
                if(word[i] == l && blurred[i] != l){/* If the word contains l, and it is not a letter that was already revealed, let goodchoice =1*/
                    goodchoice = 1;
                    blurred[i] = word[i]; /* Unblur that character*/
                }
            }
            if(strcmp(blurred, word) == 0){ /* If the blurred word is equal to the word, print congratulations and exit*/
                printf("Congratulations, the words was %s!\n", word);
                return;
            }
            if(goodchoice == 1){/*If the person guess a correct letter...*/
                printf("Good choice!\n");
                printf("The word is: %s\n", blurred);
                printf("Number of turns remaining %d\n", turns);

            }else{ /* If the person guesses a wrong letter*/
                printf("Bad choice\n");
                printf("The word is: %s\n", blurred);
                turns = turns -1;
                printf("Number of turns remaining %d\n", turns);
            }
        }
        else if(choice == 'w'){ /*If the person wants to guess the word*/
            char guess[20];
            printf("What is your guessed word?:");
            scanf("%s", guess); /* Read the guess from keyboard*/
            if(strcmp(word, guess) ==0){ /* If the word is equal to the guess, print "congrats" and exit */
                printf("Congratulations!\n\n***********************************************\n");
                return;
            }
            else{ /* If the word doesn't equal the guess, print "sorry" and exit*/
                printf("Sorry, the word was: %s\n", word);
                return;
            }


        }else{ /* If the character from the user isn't an l or a w, get a new character*/
            printf("Character must be 'w' or 'l'\n");
        }
    }if(turns==0){ /* if the player is out of turns, exit */
        printf("Out of turns, the words was %s\n", word);
        return;
    }

}

int main(void){
    do{ /* While the user inputs a 'y', keep playing the game*/
        hangman();
        printf("Do you want to play again [y/n]: ");
        getchar();
    }while(getchar() =='y');
}
