#include <iostream>
#include <set>

using namespace std;

int main() {
    multiset<int> mset;
    mset.insert(1);
    mset.insert(1);
    mset.insert(2);
    for (auto val : mset) {
        cout << val << endl;
    }
    cout << mset.count(1) << endl;
    mset.erase(1); 
    cout << mset.count(1) << endl;
}
