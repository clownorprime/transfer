#include <iostream>
#include <vector>

using namespace std;


void swap(int &a, int &b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void bubbleSort(vector<int> &data) {
    for (int i = data.size() - 1; i > 0; i--) {
        for (int j = data.size() - 1; j > data.size() - 1 - i; j--) {
            if (data[j] < data[j - 1]) {
                swap(data[j], data[j-1]);
            }
        }
    }
}


int main() {
    vector<int> data = {10, -5, 20, 3, 7, 70, -80, 0};
    bubbleSort(data);
    for (auto val : data) {
        cout << val << " ";
    }
    cout << endl;
}
