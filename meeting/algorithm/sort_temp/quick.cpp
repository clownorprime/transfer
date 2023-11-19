#include <iostream>
#include <vector>

using namespace std;

void quick_sort_aux(vector<int> &data, int left, int right) {
    if (left >= right) {
        return;
    }
    int pivot = data[left];
    int left_index = left;
    int right_index = right;
    vector<int> aux(right - left + 1, -1);
    for (int i = left + 1; i <= right; i++) {
        if (data[i] < pivot) {
            aux[left_index++] = data[i];
        } else {
            aux[right_index--] = data[i];
        }
    }
    aux[left_index] = pivot;
    for (int i = left; i <= right; i++) {
        data[i] = aux[i];
    }
    quick_sort_aux(data, left, left_index - 1);
    quick_sort_aux(data, left_index + 1, right);
}

void quickSort(vector<int> &data) {
    quick_sort_aux(data, 0, data.size() - 1);
}

int main() {
    vector<int> data = {10, -5, 20, 3, 7, 70, -80, 0};
    quickSort(data);
    for (auto val : data) {
        cout << val << " ";
    }
    cout << endl;
}
