#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    auto f = [](int a) { return a * a; };
    cout << f(5) << endl;
}

