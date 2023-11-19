#include <iostream>
#include <vector>

using namespace std;

void swap(int &a, int &b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void selectSort(vector<int> &data) {
    for (int i = 0; i < data.size(); i++) {
        int min_index = i;
        int min_val = data[i];
        for (int j = i; j < data.size(); j++) {
            if (min_val > data[j]) {
                min_index = j;
                min_val = data[j];
            }
        }
        swap(data[i], data[min_index]);
    }
}

int main() {
    vector<int> data = {10, -5, 20, 3, 7, 70, -80, 0};
    selectSort(data);
    for (auto val : data) {
        cout << val << " ";
    }
    cout << endl;
}
