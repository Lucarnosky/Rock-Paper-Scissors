#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <stdbool.h>
#include "helpers.c"

void printHeader(){
    char choice[6] = "";
    system("clear");
    printf("Welcome to Lock Garnock's Rock Paper and Scissors\n");
    printf("On stake there is more then a simple win / lose situation\n");
    printf("If you dare to continue, type start\n");
    printf("Everything else will make you as a coward and make you exit\n");
    printf("Make you choice\n");
    scanf("%5[^:]",&choice);
    if(strcasecmp(choice,"start") == 0){

        clear();
        startTurn();
    }
}

void startTurn(){
    char game[1] = "";
    int aiChoice = randomChoice();
    bool validChoice = true;
    printf("I've already made my choice of play\n");
    printf("Your turn!\n");
    scanf(" %1[^:]",&game);
    if(strcasecmp(game,"r") != 0 && strcasecmp(game,"s")  != 0 && strcasecmp(game,"p") != 0 ){
        validChoice = false;
    }
    if(validChoice == true){
        renderChoice(game,aiChoice);
    }
    startTurn();
}

int main(){
    startTurn();
    return 0;
}