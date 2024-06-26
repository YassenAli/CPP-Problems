// Purpose: Drawing House
// Author: Yassin Ali Mamdouh
// Date: 24 Dec 2023

#include <bits/stdc++.h>

using namespace std;

// The four directions that we can spread the paint to (up, down, left, right)
const int di[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

void fillRegion(vector<vector<bool>> &pixels, int row, int col) {
    if (row < 0 || row >= pixels.size() || col < 0 || col >= pixels[0].size() || pixels[row][col]) {

        return;  // Out of bounds or already painted
    }

    pixels[row][col] = true;  // Paint the current pixel

    // Recursively fill adjacent pixels in four directions
    for (int i = 0; i < 4; ++i) {
        fillRegion(pixels, row + di[i], col + dy[i]);
    }
}

bool isDoor(int row, int col) {
    if (row >= 15 && row < 23 && col >= 7 && col <= 11)
        return true;
    return false;
}

bool isWindow(int row, int col) {
    if ((row >= 10 && row < 14) &&
        ((col >= 3 && col <= 6) || (col >= 12 && col <= 15))) {
        return true;
    }
    return false;
}

//bool isHouseInterior(int row, int col) {
//    return row >= 9 && row < pixels.size() - 1 && col >= 0 && col < pixels[0].size() &&
//           pixels[row][col] == false && !isDoor(row, col) && !isWindow(row, col);
//}
bool FillDoor(vector<vector<bool>> &pixels) {
    for (int row = 15; row < pixels.size(); ++row)
        for (int col = 7; col <= 11; ++col)
            pixels[row][col] = true;
}

bool FillWindow(vector<vector<bool>> &pixels) {
    for (int row = 10; row < 14; ++row)
        for (int col: {3, 4, 5, 6, 12, 13, 14, 15})
            pixels[row][col] = true;
}

void FillHouseInterior(vector<vector<bool>> &pixels) {
    // the dome
    for (int row = 1, col = 8; row < 9 && col >= 0; ++row, --col)
        for (int column = col; column <= pixels[row].size() - col - 1; ++column)
            pixels[row][column] = true;
    // rest of house without dome and windows and door
    for (int row = 9; row < pixels.size(); ++row) {
        for (int col = 0; col < 19; ++col)
            if (!isDoor(row, col) && !isWindow(row, col))
                pixels[row][col] = true;
    }
}

void FillDom(vector<vector<bool>> &pixels) {
    for (int row = 1, col = 8; row < 9 && col >= 0; ++row, --col)
        for (int column = col; column <= pixels[row].size() - col - 1; ++column)
            pixels[row][column] = true;
}

void House(vector<vector<bool>> &pixels) {
    for (auto &row: pixels)
        for (auto &&col: row)
            col = false;
    // Set all pixels on the edges of the house to true
    for (int row = 9; row < pixels.size(); ++row) {
        for (int col: {0, 18})
            pixels[row][col] = true;
    }
    // fill the last row
    for (auto &&col: pixels[pixels.size() - 1])
        col = true;

    // Set all pixels on the windows of the house to true
    for (int row = 10; row < 14; ++row) {
        for (int col: {3, 6, 12, 15})
            pixels[row][col] = true;
        if (row == 10 || row == 13) {
            for (int col = 3; col < 7; ++col)
                pixels[row][col] = true;
            for (int col = 12; col < 16; ++col)
                pixels[row][col] = true;
        }
    }
    // Set all pixels on the door of the house to true
    for (int row = 15; row < pixels.size(); ++row) {
        for (int col: {7, 11})
            pixels[row][col] = true;
        if (row == 15)
            for (int col = 8; col < 11; ++col)
                pixels[row][col] = true;
    }

    // Set all pixels on the dome of the house to true
    pixels[0][9] = true;
    for (int row = 1, col = 8; row < 9 && col >= 0; ++row, --col)
        pixels[row][col] = pixels[row][pixels[row].size() - col - 1] = true;
}

int main() {
    vector<vector<bool>> screen = {          // Represents pixels on the screen
            {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
            {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
            {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
            {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
            {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
            {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
            {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
            {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
            {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
            {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
            {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
            {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
            {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
            {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
            {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
            {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
            {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
            {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
            {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
            {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
            {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
            {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
            {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false}
    };
    House(screen);
    int clickRow = 0, clickCol = 15;           // Coordinates of the click
    fillRegion(screen, clickRow, clickCol);      // Fill the region starting from the click
    House(screen);
    cout << "Choose from Menu which area you want to paint :\n"
            "1. Door\n"
            "2. Windows\n"
            "3. Dom\n"
            "4. HouseInterior\n";
    int choice; cin>>choice;
    switch (choice) {
        case 1:
            FillDoor(screen);
            break;
        case 2:
            FillWindow(screen);
            break;
        case 3:
            FillDom(screen);
            break;
        case 4:
            FillHouseInterior(screen);
            break;
        default:
            cout<<"Invalid choice.\n";

    }
    // Print the filled screen
    for (const vector<bool> &row: screen) {
        for (bool pixel: row) {
            cout << (pixel ? '*' : ' ');
        }
        cout << endl;
    }
    return 0;
}