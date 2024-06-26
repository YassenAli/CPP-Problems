// Purpose: Maze
//              returns all possible solutions and returns the shortest path
// Author: Yassin Ali Mamdouh
// Date: 7 Dec 2023

#include <bits/stdc++.h>

using namespace std;

#define N 10
#define INF 1e9

int dx[] = {1, -1, 0, 0,}; // down, up, right, left
int dy[] = {0, 0, 1, -1};
char dir[] = {'D', 'U', 'R', 'L'};
vector<string> allPaths;
string shortestPath;
int minLen = INF;

bool isValid(int new_row, int new_col, char board[N][N], bool visited[N][N]) {
    return (new_row >= 0 && new_row < N && new_col >= 0 && new_col < N && board[new_row][new_col] == 'o' &&
            !visited[new_row][new_col]);
}

void solveMaze(char board[N][N], int row, int col, bool visited[N][N], string path) {

    cout << "\n\nrow : " << row << " column : " << col << endl;

    if ((row == N - 1) && (col == N - 1)) {
        allPaths.push_back(path);
        if (path.size() < minLen) {
            shortestPath = path;
            minLen = path.size();
        }
        return ;
    }
    visited[row][col] = true;

    for (int i = 0; i < 4; ++i) {
        int new_row = row + dx[i];
        int new_col = col + dy[i];
        if (isValid(new_row, new_col, board, visited))
            solveMaze(board, new_row, new_col, visited, path + dir[i]);
    }

    // undo
    visited[row][col] = false; // backtrack
}
int main() {
    char board[N][N] = {
            {'o', '1', '1', 'o', '1', 'o', 'o', 'o', '1', 'o'},
            {'o', 'o', '1', 'o', 'o', 'o', '1', 'o', 'o', 'o'},
            {'1', 'o', '1', '1', 'o', '1', '1', 'o', 'o', 'o'},
            {'o', 'o', 'o', 'o', 'o', '1', '1', '1', '1', 'o'},
            {'o', '1', '1', 'o', '1', '1', '1', 'o', '1', 'o'},
            {'o', '1', '1', 'o', 'o', 'o', '1', 'o', 'o', 'o'},
            {'o', '1', '1', 'o', 'o', 'o', '1', 'o', '1', '1'},
            {'o', '1', '1', 'o', 'o', '1', '1', 'o', 'o', 'o'},
            {'o', '1', '1', 'o', 'o', '1', '1', '1', '1', 'o'},
            {'o', '1', '1', 'o', 'o', '1', '1', 'o', 'o', 'o'},
    };

    bool visited[N][N] = {false};

    solveMaze(board, 0, 0, visited, "");

    cout << "All Paths : \n";
    int i = 0;
    for (const string &path: allPaths)
        cout << "Path " << ++i << " is :" << path << '\n';

    cout << "\nShortest Path is : " << shortestPath;

    return 0;
}