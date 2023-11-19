#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

bool solve(vector<vector<char>> data, int row, int col, string s) {
    vector<bool> visited(6, false);
    string s;
    multiset<char> mset;
    for (int i = row; i < row+3; i++) {
        for (int j = col; j < col+3; j++) {
            char c = data[i][j];
            help(c, s, visited);
        }
    }
    for (int i = 0; i < visited.size(); i++) {
        if (visited[i] == false) {
            return false;
        }
    }
    return true;
}
int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<char>> data(m, vector<char>(n));
    string str;
    for (int i = 0; i < m; i++) {
        cin >> str;;
        for (int j = 0; j < n; j++) {
            data[i][j] = str[j];
        }
    }
    multiset<char> mset;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            mset.insert(data[i][j]);
        }
    }
    vector<bool> visited(6, false);
    for (auto val : mset) {
        for (int i = 0; i < s.size(); i++) {
            if (val == s[i]) {
                if (val == 'i') {
                    if (visited[i]) {
                        visited[5] = true;
                    }
                }
            } 
        }
    }
    string s("xiaomi");
    vector<bool> visited(6, false);
    int ans = 0;
    for (int i = 0; i <= m-3; i++) {
        for (int j = 0; j <= n-3; j++) {
            if (solve(data, i, j, s)) {
                ans++;
            }
        }
    }
    cout << ans << endl;
}
