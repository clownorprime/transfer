#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int numCourses = 3;
    int push_node = 0;
    vector<vector<int>> prerequist = {{0, 1}, {1, 2}, {2, 0}};
    vector<vector<int>> matrix(numCourses, vector<int>(numCourses));
    for (int i = 0; i < numCourses; i++) {
        for (int j = 0; j < numCourses; j++) {
            matrix[i][j] = 0;
        }
    }
    vector<int> inDegree(numCourses, 0);
    for (int i = 0; i < prerequist.size(); i++) {
        vector<int> pre = prerequist[i];
        int first = pre[0], second = pre[1];
        matrix[second][first] = 1;
        inDegree[first]++;
    }
    queue<int> myqueue;
    vector<bool> visited(numCourses, false);
    for (int i = 0; i < inDegree.size(); i++) {
        if (inDegree[i] == 0) {
            visited[i] = true;
            myqueue.push(i);
        }
    }
    while(!myqueue.empty()) {
        int node = myqueue.front();
        myqueue.pop();
        push_node++;
        vector<int> out = matrix[node];
        for (int i = 0; i < out.size(); i++) {
            if (out[i] == 1 && --inDegree[i] == 0 && !visited[i]) {
                visited[i] = true;
                myqueue.push(i);
            }
        }
    }
    cout << "push_node = " << push_node << endl;
    if (numCourses != push_node) {
        cout << "there is a cycle in the graph" << endl;
    } else {
        cout << "there is no cycle in the graph" << endl;
    }
}
