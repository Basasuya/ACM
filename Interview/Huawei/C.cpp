#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// box size
const int n = 3;
// row size
const int N = 9;

int rows[N + 5][N + 5];
int columns[N + 5][N + 5];
int boxes[N + 5][N + 5];

int board[N + 5][N + 5];

bool sudokuSolved = false;

bool couldPlace(int d, int row, int col) {
    int idx = (row / n ) * n + col / n;
    return rows[row][d] + columns[col][d] + boxes[idx][d] == 0;
}

void placeNumber(int d, int row, int col) {
    int idx = (row / n ) * n + col / n;

    rows[row][d]++;
    columns[col][d]++;
    boxes[idx][d]++;
    board[row][col] = d;
}

void removeNumber(int d, int row, int col) {
    int idx = (row / n ) * n + col / n;
    rows[row][d]--;
    columns[col][d]--;
    boxes[idx][d]--;
    board[row][col] = 0;
}

void backtrack(int row, int col);

void placeNextNumbers(int row, int col) {
    if ((col == N - 1) && (row == N - 1)) {
        sudokuSolved = true;
    } else {
        if (col == N - 1) backtrack(row + 1, 0);
        else backtrack(row, col + 1);
    }
}

void backtrack(int row, int col) {
    if (board[row][col] == 0) {
        for (int d = 1; d < 10; d++) {
            if (couldPlace(d, row, col)) {
                placeNumber(d, row, col);
                placeNextNumbers(row, col);
                if (!sudokuSolved) removeNumber(d, row, col);
            }
        }
    } else placeNextNumbers(row, col);
}


int main() {
    for(int i = 0; i < N; ++i) {
        scanf("{%1d,%1d,%1d,%1d,%1d,%1d,%1d,%1d,%1d}", &board[i][0], &board[i][1], &board[i][2], &board[i][3], &board[i][4], &board[i][5], &board[i][6], &board[i][7], &board[i][8]);
    }


    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char num = board[i][j];
            if (num != 0) {
                placeNumber(num, i, j);
            }
        }
    }

    for(int i = 0; i < N; ++i) {
        printf("{%d,%d,%d,%d,%d,%d,%d,%d,%d}\n", board[i][0], board[i][1], board[i][2], board[i][3], board[i][4], board[i][5], board[i][6], board[i][7], board[i][8]);
    }

    backtrack(0, 0);
}


/*


{5,0,0,6,0,2,0,0,0}
{0,0,8,0,7,0,2,0,0}
{7,0,0,8,1,0,5,4,6}
{3,4,0,0,8,0,0,0,0}
{0,0,9,0,0,7,0,1,4}
{1,5,6,0,2,0,0,0,3}
{4,0,2,0,9,6,0,0,7}
{9,0,0,0,0,3,0,0,1}


*/