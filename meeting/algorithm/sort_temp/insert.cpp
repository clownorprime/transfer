#include <iostream>
#include <vector>

using namespace std;


void swap(int &a, int &b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}
void insertSort(vector<int> &data) {
    for (int j = 1; j < data.size(); j++) {
        int start_index = j - 1;
        int current_val = data[j];
        while(start_index >= 0 && data[start_index] > current_val) {
            data[start_index + 1] = data[start_index];
            start_index--;
        }
        data[start_index + 1] = current_val;
    }
}

int main() {
    vector<int> data = {10, -5, 20, 3, 7, 70, -80, 0};
    insertSort(data);
    for (auto val : data) {
        cout << val << " ";
    }
    cout << endl;
}
