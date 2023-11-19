#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double left, right, threshold;
    int target;

    target = 2;
    left = 1;
    right = 2;
    threshold = 0.00000000001;
    double middle = 0;
    while(left < right) {
        middle = (left + right) / 2;
        if (abs(target - middle * middle) < threshold) {
            break;
        }
        if (middle * middle > target) {
            right = middle;
        } else {
            left = middle;
        }
    }
    cout << fixed << setprecision(5) << middle << endl;
}
