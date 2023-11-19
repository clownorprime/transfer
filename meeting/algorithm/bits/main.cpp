#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void solve2(int n, vector<int>& vec) {
    int order = 0;
    while(n / pow(10, order) > 9) {
        order++;
    }
    while(n) {
        int num = n / pow(10, order);
        for (int i = 0; i < vec.size(); i++) {
            vec[i] += (order * pow(10, order - 1));
        }
        for (int i = 1; i < num; i++) {
            vec[i] += pow(10, order);
            vec[i]++;
        }
        n = n - num * pow(10, order);
        vec[num] += n;
    }
}

int getZero(int order) {
    int base = order * pow(10, order - 1);
    int remain = order;
    while(order >= 1) {
        base = base - pow(10, order - 1);
    }
    base += remain;
    return base;
}
void solve1(int n, vector<int>& vec) {
    for (int i = 1; i <= n; i++) {
        int val = i;
        string s = to_string(val);
        for (int i = 0; i < s.size(); i++) {
            int index = s[i] - '0';
            vec[index]++;
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> vec1(10, 0), vec2(10, 0);
    solve1(n, vec1);
    cout << "vec1:";
    for (int i = 0; i < vec1.size(); i++) {
        cout << vec1[i] << " ";
    }
    cout << endl;
    solve2(n, vec2);
    cout << "vec2: ";
    for (int i = 0; i < vec2.size(); i++) {
        cout << vec2[i] << " ";
    }
    cout << endl;
}
