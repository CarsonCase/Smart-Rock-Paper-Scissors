/*
Simple rock paper scissors game, but with a little twist. It will weight it's guesses based off the users previous guesses!
Author: Carson Case
Date: 08/22/2020
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

char largest(int r, int p, int s){
    //is r > p?
    if(r>p){
        //if so, is it also greater than s?
        if(r>s){
            //guessed userIn is r. Paper beats rock
            return 'p';
        }
        //if not. S is largest
        else{
            //guessed userIn is 's'. Rock beats scissors
            return 'r';
        }
    }else{
        //if not then is p > s?
        if(p>s){
            //guessed userIn is 'paper'. Scissors beats paper
            return 's';
        }else{
            //if not then s is larger
            //guessed userIn is 's'. Rock beats scissors
            return 'r';
        }
    }
}
/*
Algorithm Function:
takes in all the past throws from the user and counts the number of rocks, papers and scissors thrown.
It then flavors a weighted random throw based off of the user's past moves. It multiplies a random number from 0-NUMBER OF ROUNDS + 1 with the count of that throw.
This does not recognize patters in relation to the computers throws however. For example a user might tend to use the same throw over and over until losing, then change it.
This does not look at that but it would be fun to add.
*/
char algorithm(char data[MAX], int c){
    //varables
    //starts at 1 count of each because otherwise it will never throw a counter to something not yet thrown by the user
    int r = 1;
    int p = 1;
    int s = 1;
    for(int i=0; i<c; i++){
        switch(data[i]){
            case('r'):
                r++;
                break;
            case('p'):
                p++;
                break;
            case('s'):
                s++;
                break;
        }
    }
    r = (rand()%(c+1))*r;
    p = (rand()%(c+1))*p;
    s = (rand()%(c+1))*s;
    return largest(r,p,s);
}

//Scoring function to return true if user won
int score_round(char user, char comp){
    if(user==comp){
        //draw
        return 0;
    }
    if((user == 'r' && comp == 's')||(user == 's' && comp == 'p')||(user == 'p' && comp == 'r')){
        //user wins
        return 1;
    }else{
        //computer wins
        return -1;
    }
}

int main(){
    //variables
    char pastData[MAX];
    int count = 0;
    int score = 0;
    //mainloop
    char userIn;
    printf("Welcome to Smart Rock-Paper-Scissors. Please enter r, p, or s to play (lowercase). To leave press any other key:\n");
    do{
        printf("Round #%d\nScore: %d\n",count+1,score);
        scanf(" %c",&userIn);
        char x = algorithm(pastData,count);
        pastData[count++] = userIn;
        printf("My choice: %c\n",x);
        score+=score_round(userIn,x);
    }while((userIn == 'r') || (userIn == 'p') || (userIn == 's'));

    return 0;
}