#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

/**
 * The helpers is a small library with some utility that can be recalled multiple time for 
 * a better render of the program
 * I've decided to make an aside file to keep the main program as much clean as possible
 */

//function to clear the terminal
void clear(){
    system("clear");
}

//function to make a random choice between 0 and 2 which rapresent the AI choice 
int randomChoice(){
    time_t t;
    int rnd;
    srand((unsigned) time(&t));
    rnd = rand() % 3;
    return rnd;
}

//Function dedicated at the ascii rendering of the 2 choices
void renderChoice(char choice[1],char aiChoice[3]){
    char line1[50] = "";
    char line2[50] = "";
    char line3[50] = "";
    char line4[50] = "";
    char line5[50] = "";
    char line6[50] = "";
    char line7[50] = "";
        if(strcasecmp(choice,"r") == 0){
            strcat(line1,"    _______       ");
            strcat(line2,"---'   ____)      ");
            strcat(line3,"      (_____)     ");
            strcat(line4,"      (_____)     ");
            strcat(line5,"      (____)      ");
            strcat(line6,"---.__(___)       ");
            strcat(line7,"            ROCK  ");
        }else if(strcasecmp(choice,"p") == 0){
            strcat(line1,"     _______      ");
            strcat(line2,"---'    ____)____ ");
            strcat(line3,"           ______)");
            strcat(line4,"          _______)");
            strcat(line5,"         _______) ");
            strcat(line6,"---.__________)   ");
            strcat(line7,"           PAPER  ");
        }else if(strcasecmp(choice,"s") == 0){
            strcat(line1,"    _______       ");
            strcat(line2,"---'   ____)____  ");
            strcat(line3,"          ______) ");
            strcat(line4,"      __________) ");
            strcat(line5,"      (____)      ");
            strcat(line6,"---.__(___)       ");
            strcat(line7,"         SCISSOR  ");
        }
        strcat(line1,"    ");
        strcat(line2,"    ");
        strcat(line3,"    ");
        strcat(line4,"    ");
        strcat(line5,"    ");
        strcat(line6,"    ");
        strcat(line7," VS ");
        if(aiChoice == 0){
            strcat(line1,"       _______ ");
            strcat(line2,"      (____   '---");
            strcat(line3,"     (_____)");
            strcat(line4,"     (_____)");
            strcat(line5,"      (____)");
            strcat(line6,"        (___)__.---");
            strcat(line7,"  ROCK");
        }else if(aiChoice == 1){
            strcat(line1,"          _______");
            strcat(line2,"     ____(____   '----");
            strcat(line3,"    (______");
            strcat(line4,"    (_______");
            strcat(line5,"     (_______");
            strcat(line6,"        (_________.---");
            strcat(line7,"  PAPER");
        }else if( aiChoice == 2){
            strcat(line1,"           _______");
            strcat(line2,"      ____(____   '---");
            strcat(line3,"     (______");
            strcat(line4,"    (__________");
            strcat(line5,"          (____)");
            strcat(line6,"           (___)__.---");
            strcat(line7,"  SCISSORS");
        }
    printf(" %s\n",line1);
    printf(" %s\n",line2);
    printf(" %s\n",line3);
    printf(" %s\n",line4);
    printf(" %s\n",line5);
    printf(" %s\n",line6);
    printf(" %s\n",line7);
    renderWinner(choice, aiChoice);
}

void renderWinner(char* game, int aiChoice){
    int translatedChoice = NULL;
    char winnerName[10] = "";
    if(strcasecmp(game,"r") == 0){
        translatedChoice = 0;
    }else if(strcasecmp(game,"p") == 0){
        translatedChoice = 1;
    }else if(strcasecmp(game,"s") == 0){
        translatedChoice = 2;
    }
    if(translatedChoice == aiChoice)
        strcpy(winnerName,"No one");
    switch(translatedChoice){
        case 0:
            if(aiChoice == 1){
                strcpy(winnerName,"PC");
            }else if(aiChoice == 2){
                strcpy(winnerName,"Player");
            }
            break;
        case 1:
            if(aiChoice == 0){
                strcpy(winnerName,"Player");
            }else if(aiChoice == 2){
                strcpy(winnerName,"PC");
            }
            break;
        case 2:
            if(aiChoice == 0){
                strcpy(winnerName,"PC");
            }else if(aiChoice == 1){
                strcpy(winnerName,"Player");
            }
            break;
    }
    printf("Win this turn: %s \n",winnerName);
}
