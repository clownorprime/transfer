#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void solve(int num, vector<vector<char>> &vec, int start_row, int start_col, int copy_row, int copy_col);

int main()
{
    int num;
    cin >> num;
    int output_row = 3 * pow(2, num - 1);
    vector<vector<char>> vec(output_row, vector<char>(2 * output_row));
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[0].size(); j++) {
            vec[i][j] = ' ';
        }
    }
    vector<vector<char>> single(5, vector<char>(5));
    for (int i = 0; i < single.size(); i++) {
        for (int j = 0; j < single[0].size(); j++) {
            single[i][j] = ' ';
        }
    }
    single[0][2] = '*';
    single[1][1] = '*';
    single[1][3] = '*';
    single[2][0] = '*';
    single[2][2] = '*';
    single[2][4] = '*';

    int start_row = 0;
    int start_col = output_row - 2;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            vec[i + start_row][start_col + j] = single[i][j];
        }
    }
    solve(num, vec, start_row, start_col, 3, 5);
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[0].size(); j++) {
            cout << vec[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void solve(int num, vector<vector<char>> &vec, int start_row, int start_col, int copy_row, int copy_col) {
    if (num == 1) {
        return;
    }
    int copy_row0 = start_row + copy_row;
    int copy_col1 = start_col - copy_col / 2 - 1;
    int copy_col2 = start_col + copy_col / 2 + 1;
    for (int i = 0; i < copy_row; i++) {
        for (int j = 0; j < copy_col; j++) {
            vec[copy_row0 + i][copy_col1 + j] = vec[start_row + i][start_col + j];
            vec[copy_row0 + i][copy_col2 + j] = vec[start_row + i][start_col + j];
        }
    }
    solve(num - 1, vec, start_row, copy_col1, copy_row * 2, copy_col * 2 + 1);
}
