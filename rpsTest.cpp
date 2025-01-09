#include <iostream>
#include <cstdlib>
#include <ctime>
#include "rpsTest.h"

using namespace std;

int random = 0;
int result = -1;
string choice = "nothing";

int convertChoice(string s){
    if (s == "Rock"){
        return 1;}
    if (s == "Paper"){
        return 2;}
    if (s == "Scissors"){
        return 3;}
    return -1;
}

int winConditions(int c, int r){

    if (c == r){
        return 2;
    }
    else if(c == 1 && r == 3){
        return 0;
    }
    else if(c == 2 && r == 1){
        return 0;
    }
    else if(c == 3 && r == 2){
        return 0;
    }
    else{
        return 1;
    }
}

string convertNumber (int n){
    if (n == 1){
        return "Rock";}
    if (n == 2){
        return "Paper";}
    if (n == 3){
        return "Scissors";}
    else{
        return "error";
    }
}

int randNum(){
    std::srand(std::time(0)); 

    random = std::rand()% 3 + 1;

    cout<< "The computer chose " << convertNumber (random) <<endl;

    return random;
}



int runGame(int c){
    

    result = winConditions(c,randNum());

    return result;

}

