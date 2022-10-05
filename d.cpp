
class Solution
{
public:
    void dfs(int src, int dst, int k, int count, int &ans, vector<int> &visited, vector<pair<int, int>> adj[])
    {
        if (count > ans)
            return;

        if (src == dst)
        {
            ans = min(ans, count);
            return;
        }
        if (k < 0)
        {
            return;
        }

        visited[src] = 1;

        for (auto it : adj[src])
        {
            if (!visited[it.first])
            {
                dfs(it.first, dst, k - 1, (count + it.second), ans, visited, adj);
            }
        }
        visited[src] = 0;
    }
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<pair<int, int>> adj[n];
        for (int i = 0; i < flights.size(); i++)
        {
            int u = flights[i][0];
            int v = flights[i][1];
            int wt = flights[i][2];
            adj[u].push_back({v, wt});
        }

        int ans = 1e9;
        int count = 0;
        vector<int> visited(n, 0);
        dfs(src, dst, k, count, ans, visited, adj);
        if (ans == 1e9)
            return -1;
        return ans;
    }
};
