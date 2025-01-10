#include <iostream>
#include "gameUITest.h"

using namespace std;

string a = "error";
char selection = 'Y';

string printGame(){
    cout << "Let's Play Rock, Paper, Scissors..." << endl;
    cout << "Choose either rock, paper, scissors: ";
    cin >> a;
    cout << endl;
    return a;
}

char printContinue(){
 cout << "Would you like to continue" <<endl;
    cout << "Select Y or N : ";
    cin >> selection;
    return selection;
}

void printResult(int r){

    if (r == 0){
        cout << "Congratualations, you won! " << endl;
        return;
    }
    if (r == 1){
        cout << "Unfortunately, You lost." << endl;
        return;
    }
    if (r == 2){
        cout << "So close, you tied! " << endl;
        return;
    }
    else {
        cout << "Error. Please Try Again." << endl;
        return;
    }
}