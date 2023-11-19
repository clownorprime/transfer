#include <iostream>
#include <algorithm>

using namespace std;

bool fun(int a, int b) {
    if ((a % 2 == 1) && (b % 2 == 0)) {
        return true;
    }
    if (a < b) { return true; }
    return false;
}
int main() {
    vector<int> data = {1,2,3,4,5,6,7,8,9};
    sort(data.begin(), data.end(), fun);
    for (auto val : data) {
        cout << val << " ";
    }
    cout << endl;
}

