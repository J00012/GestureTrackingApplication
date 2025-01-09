#include <iostream>
using namespace std;
#include "rpsTest.h"
#include "gameUITest.h"

int outcome = -1;
string cho = "nothing";
int ans = -1;
char cont = 'Y';

int main() {
    while (cont == 'Y') {
        cho = printGame();
        ans = convertChoice(cho);
        
        outcome = runGame(ans);
        
        printResult(outcome);
        cont = printContinue();
    } 
    return 0;
}