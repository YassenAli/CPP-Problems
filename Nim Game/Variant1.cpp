// File: A3_S1_SheetPb2_20220381.cpp
// Purpose: Nim Game.  Variant one:
//          The player whose pile contains an even number of coins after the last one is taken wins the game.
// Author: Yassin Ali Mamdouh
// Section: S1
// ID: 20220381
// TA: Khaled Ebrahim
// Date: 7 Dec 2023

#include <iostream>

#define NO_GOOD_MOVE  0
#define MAX_MOVE 3
#define N_COINS 23
#define HUMAN 1
#define COMPUTER 0

using namespace std;

bool isBadPosition(int nCoins);

int findGoodMove(int nCoins) {
    for (int n = 1; n <= MAX_MOVE; n++) {
        int newCoins = nCoins - n;
        if (newCoins % 2 == 0 && isBadPosition(newCoins))
            return n;
    }
    return NO_GOOD_MOVE;
}

bool isBadPosition(int nCoins) {
    if (nCoins == 1)
        return true;
    return findGoodMove(nCoins) == NO_GOOD_MOVE;
}

int main() {
    int nCoins = N_COINS, n;
    int whoseTurn = HUMAN;
    int sum_human = 0, sum_computer = 0;
    cout << "Welcome to Nim. Variant 1.\nThe player whose pile contains an even number of coins after the last one is "
            "taken wins the game.\n We start with " << nCoins << endl;
    cout << "Each one picks 1 to " << MAX_MOVE << " coins.\n";

    while (nCoins > 1) {
        cout << "\nWe have " << nCoins << ".\n";
        cout << (whoseTurn ? "Human" : "Computer") << " plays: ";
        switch (whoseTurn) {
            case HUMAN:
                n = nCoins + 10;
                while (n < 1 || n > 3 || n > nCoins) {
                    cout << "Pls pick 1 or 2 or 3 coins and <= remaining coins {" << nCoins << "} : ";
                    cin >> n;
                }
                sum_human += n;
                break;
            case COMPUTER:
                n = findGoodMove(nCoins);
                if (!n)
                    n = 1;
                cout << "Computer takes " << n << " coins.\n";
                sum_computer += n;
        }
        nCoins -= n;
        whoseTurn = (whoseTurn + 1) % 2;
    }
    cout << "\nComputer's pile contain : " << sum_computer << endl << "Player's pile contain : " << sum_human;
    cout << "\n\n" << (((sum_human % 2 && sum_computer % 2) || (sum_human % 2 == 0 && sum_computer % 2 == 0))
                       ? "Drawn.\n No Winner\n" : (sum_human % 2 ? "Winner is : Computer \n" : "Winner is : Human \n"));
}
