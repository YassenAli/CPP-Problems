// Purpose: Nim Game by Minimax.
// Author: Yassin Ali Mamdouh
// Date: 24 Dec 2023

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int evaluatePosition(const vector<int> &piles) {
    // Calculate XOR sum to determine potential winning positions
    int xorSum = 0;
    for (int pile : piles) {
        xorSum ^= pile;
    }
    return xorSum;
}

pair<int, int> minimax(const vector<int> &piles, bool isMaximizing) {
    if (evaluatePosition(piles) == 0) {
        // Losing position, return a move indicating a loss
        return make_pair(-1, 1); // Placeholder move for a loss
    }

    int bestScore = isMaximizing ? -1 : 1;
    int bestMove = -1;
    int bestTake = 1;

    for (int i = 0; i < piles.size(); i++) {
        for (int take = 1; take <= min(piles[i], 1); take++) { // Ensure valid take amount
            vector<int> newPiles = piles;
            newPiles[i] -= take;
            int score = minimax(newPiles, !isMaximizing).first;

            if (isMaximizing && score > bestScore) {
                bestScore = score;
                bestMove = i;
                bestTake = take;
            } else if (!isMaximizing && score < bestScore) {
                bestScore = score;
                bestMove = i;
                bestTake = take;
            }
        }
    }
    // Handle invalid bestMove or bestTake values
    if (bestMove < 0 || bestMove >= piles.size() || bestTake <= 0 || bestTake > piles[bestMove]) {
        for (int i = 0; i < piles.size(); ++i)
            if (piles[i] >= 1)
                return {i, 1};  // Return a default invalid move
    }
    return {bestMove, bestTake}; // Return the optimal move
}

bool gameOver(const vector<int> &piles) {
    return all_of(piles.begin(), piles.end(), [](int pile) { return pile == 0; });
}

int main() {
    vector<int> piles = {5, 8, 10}; // Initial piles (can be modified)
    bool isHumanTurn = true; // Computer starts first

    while (!gameOver(piles)) {
        cout << "Current piles: ";
        for (int pile : piles) {
            cout << pile << " ";
        }
        cout << endl;

        if (isHumanTurn) {
            // Get human's move with input validation
            int pile, take;
            do {
                cout << "Your turn: Choose a pile (1-" << piles.size() << ") and number of coins to take: ";
                cin >> pile >> take;
            } while (pile <= 0 || pile > piles.size() || take <= 0 || take > piles[pile - 1]);
            piles[pile - 1] -= take;
        } else {
            // Computer's turn using Minimax
            pair<int, int> bestMove = minimax(piles, true);
            int bestPile = bestMove.first;
            int take = bestMove.second;
            cout << "Computer takes " << take << " coins from pile " << bestPile + 1 << endl;
            piles[bestPile] -= take;
        }

        isHumanTurn = !isHumanTurn;
    }

    cout << "All piles are empty. " << (isHumanTurn ? "Human wins!" : "Computer wins!") << endl;
    return 0;
}
