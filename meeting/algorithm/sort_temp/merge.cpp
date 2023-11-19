#include <iostream>
#include <vector>

using namespace std;

void merge_sort_aux(vector<int>& data, vector<int> aux, int left, int right) {
    if (left >= right) {
        return;
    }
    int begin1, begin2;
    int end1, end2;
    begin1 = left, begin2 = (left + right) / 2 + 1;
    end1 = (left + right) / 2, end2 = right;
    merge_sort_aux(data, aux, begin1, end1);
    merge_sort_aux(data, aux, begin2, end2);
    int index = left;
    while(begin1 <= end1 && begin2 <= end2) {
        if (data[begin1] < data[begin2]) {
            aux[index++] = data[begin1++];
        } else {
            aux[index++] = data[begin2++];
        }
    }
    if (begin1 <= end1) {
        while(begin1 <= end1) {
            aux[index++] = data[begin1++];
        }
    } else {
        while(begin2 <= end2) {
            aux[index++] = data[begin2++];
        }
    }
    cout << "left = " << left << " right = " << right << endl;
    for (int i = left; i <= right; i++) {
        cout << aux[i] << " ";
        data[i] = aux[i];
    }
    cout << endl;
}

void mergeSort(vector<int> &data) {
    vector<int> aux(data.size(), -1);
    merge_sort_aux(data, aux, 0, data.size() - 1);
}

int main() {
    vector<int> data = {10, -5, 20, 3, 7, 70, -80, 0};
    mergeSort(data);
}
