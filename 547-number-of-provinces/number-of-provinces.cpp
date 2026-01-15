class Solution {
    void BFS(vector<vector<int>>& G, int v, vector<bool>& visited) {
        queue<int> q;
        q.push(v);
        visited[v] = true;
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            for (int i = 1; i <= G.size(); i++) {
                if (current == i)
                    continue;
                if (G[current - 1][i - 1] && !visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        return;
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool> visited(isConnected.size() + 1, false);
        int count = 0;
        for (int i = 1; i <= isConnected.size(); i++) {
            if (!visited[i]) {
                count++;
                BFS(isConnected, i, visited);
            }
        }
        return count;
    }
};