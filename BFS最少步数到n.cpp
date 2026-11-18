#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
int main() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }
    vector<int> dist(n + 1, -1);
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        vector<int> next_positions;
        if (current - 1 >= 1 && dist[current - 1] == -1) {
            next_positions.push_back(current - 1);
        }
        if (current + 1 <= n && dist[current + 1] == -1) {
            next_positions.push_back(current + 1);
        }
        if (2 * current <= n && dist[2 * current] == -1) {
            next_positions.push_back(2 * current);
        }
        for (int next_pos : next_positions) {
            dist[next_pos] = dist[current] + 1;
            if (next_pos == n) {
                cout << dist[next_pos] << endl;
                return 0;
            }
            q.push(next_pos);
        }
    }
    cout << dist[n] << endl;
    return 0;
}
