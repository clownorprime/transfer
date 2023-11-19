#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool isFirstType(char c) {
    return c == 'a' || c == 'c' || c == 'e';
}
bool isSecondType(char c) {
    return c ==  'b' || c == 'd' || c == 'f';
}

char getLastElement(const vector<char> &v) {
    int size = v.size();
    if (size == 0) {
        cerr << "vector size is 0";
    }
    return v[size-1];
}
int main() {
    string s;
    cin >> s;
    vector<char> v1, v2;
    for (auto c : s) {
        if (isFirstType(c)) {
            if (v1.size() == 0) {
                v1.push_back(c);
            } else if (getLastElement(v1) <= c) {
                v1.push_back(c);
            } else {
                int p = upper_bound(v1.begin(), v1.end(), c) - v1.begin();
                v1[p] = c;
            }
        } else if (isSecondType(c)) {
            if (v2.size() == 0) {
                v2.push_back(c);
            } else if (getLastElement(v2) <= c) {
                v2.push_back(c);
            } else {
                int p = upper_bound(v2.begin(), v2.end(), c) - v2.begin();
                v2[p] = c;
            }
        }
    }
    for (auto val : v1) {
        cout << val << " ";
    }
    cout << endl;
    for (auto val : v2) {
        cout << val << " ";
    }
    cout << endl;
}
