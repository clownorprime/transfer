#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    vector<vector<int>> path = 
    {
        {1}, {0, 2}, {1, 3}, {2, 4}, {3}
    };
    int node_num = path.size();
    int push_node = 0;
    vector<bool> visited(node_num, false);
    vector<int> degree(node_num, 0);
    for (int i = 0; i < node_num; i++) {
        degree[i] = path[i].size();
    }
    queue<int> myqueue;
    for (int i = 0; i < degree.size(); i++) {
        if (degree[i] <= 1) {
            visited[i] = true;
            myqueue.push(i);
            push_node++;
        }
    }
    while(!myqueue.empty()) {
        int node = myqueue.front();
        myqueue.pop();
        degree[node] = 0;
        vector<int> neighors = path[node];
        for (int i = 0; i < neighors.size(); i++) {
            int neighor = neighors[i];
            if (--degree[neighor] <= 1 && visited[neighor] == false) {
                myqueue.push(neighor);
                visited[neighor] = true;
                push_node++;
            }
        }
    }
    if (push_node == node_num) {
        cout << "there is no cycle in the graph" << endl;
    } else {
        cout << "there is a cycle in the graph" << endl;
    }
}
