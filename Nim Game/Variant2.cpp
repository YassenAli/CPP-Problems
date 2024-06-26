// File: A3_S1_SheetPb2_20220381.cpp
// Purpose: Nim Game.  Variant Two:
//          Each player takes 1, 2 or 3 coins from any pile he likes. The player that takes the last coin loses.
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

bool isBadPosition(int nCoins) {
    return (nCoins == 1 || nCoins == 5);
}

int findGoodMove(int nCoins) {
    for (int n = 1; n <= MAX_MOVE; n++)
        if (isBadPosition(nCoins - n))
            return n;
    return NO_GOOD_MOVE;
}

int main() {
    int piles[3] = {5, 8, 10}; // Initial number of coins in each pile
    int nCoins = N_COINS;
    int whoseTurn = HUMAN;
    cout << "Welcome to Nim. Variant 2.\nEach player takes 1, 2 or 3 coins from any pile he likes."
            " The player that takes the last coin loses.\n We start with " << nCoins << endl;
    cout << "Each one picks 1 to " << MAX_MOVE << " coins.\n";

    while (piles[0] > 0 || piles[1] > 0 || piles[2] > 0) {
        int pile_number, n;
        cout << "\nWe have " << nCoins << " in the three piles.\n";
        cout << (whoseTurn ? "Human" : "Computer") << " plays: ";
        switch (whoseTurn) {
            case HUMAN:
                cout << "Please choose a Pile Number to pick from it.\n";
                cout << "Current piles:\n";
                for (int i = 0; i < 3; i++) {
                    cout << "Pile " << i + 1 << " contain : " << piles[i] << endl;
                }
                cout << "Choose a pile and the number of coins to take: ";
                cin >> pile_number >> n;
                while (n > piles[pile_number] || n < 1 || n > 3) {
                    cout << "Invalid Input.\nPlease Choose right Number";
                    cin >> n >> pile_number;
                }
                break;
            case COMPUTER:
                n = findGoodMove(nCoins);
                pile_number = -1;
                for (int i = 0; i < 3; i++) {
                    n = findGoodMove(piles[i]);
                    if (n != NO_GOOD_MOVE) {
                        pile_number = i + 1;
                        break;
                    }
                }
                if (pile_number == -1) {
                    if(piles[pile_number+1] > 0) pile_number = 1;
                    else if(piles[pile_number+2] > 0) pile_number = 2;
                    else pile_number = 3;
                    n = 1;
                }
                cout << "Current piles:\n";
                for (int i = 0; i < 3; i++) {
                    cout << "Pile " << i + 1 << " contain : " << piles[i] << endl;
                }
                cout << "Computer chooses pile " << pile_number << " and takes " << n << " coins.\n";
                break;
        }
        piles[pile_number-1] -= n;
        nCoins -= n;
        whoseTurn = (whoseTurn + 1) % 2;
    }
    cout << "\n\nWinner is : " << (whoseTurn ? "Computer \n" : "Human \n");
    return 0;
}