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
        cout << " Congratualations, you won! " << endl;
    }
    if (r == 1){
        cout << "So close, but you tied. " << endl;
    }
    if (r == 2){
        cout << "Unfortunately, You lost. " << endl;
    }
    else {
        cout << "Error. Please Try Again." << endl;
    }
}