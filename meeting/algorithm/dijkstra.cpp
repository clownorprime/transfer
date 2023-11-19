#include <iostream>
#include <vector>
#include <climits>

using namespace std;
void dijkstra(const vector<vector<int>> &dist, vector<int> &ans, int source) {
    int n = dist.size();
    vector<bool> visited(dist.size(), false);
    visited[source] = true;
    for (int i = 0; i < n; i++) {
        ans[i] = dist[source][i];
    }
    ans[source] = 0;
    while(true) {
        int minIndex = -1;
        int minVal = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && minVal > ans[i]) {
                minIndex = i;
                minVal = ans[i];
            }
        }
        cout << "minIndex = " << minIndex << endl;
        if (minIndex == -1) {
            return;
        }
        visited[minIndex] = true;
        for (int i = 0; i < n; i++) {
            // possible an int overflow.
            if (!visited[i] && dist[minIndex][i] != INT_MAX && ans[minIndex] + dist[minIndex][i] < ans[i]) {
                ans[i] = ans[minIndex] + dist[minIndex][i];
            }
        }
        cout << "minIndex = " << minIndex << endl;
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n, e, source;
    cin >> n >> e >> source;
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
    for (int i = 0; i < e; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        dist[from-1][to-1] = cost;
    }
    vector<int> ans(n, 0);
    dijkstra(dist, ans, source-1);
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}
