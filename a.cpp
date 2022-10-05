class Solution
{
public:
    int findPar(int nod , vector<int> &parent)
    {
        if (nod == parent[nod])
        {
            return nod;
        }
        return parent[nod] = findPar(parent[nod], parent);
    }
    void uni(int u, int v, vector<int> &parent, vector<int> &rank)
    {
        u = findPar(u, parent);
        v = findPar(v, rank);
        if (rank[u] > rank[v])
        {
            parent[v] = u;
        }
        else if (rank[v] > rank[u])
        {
            parent[u] = v;
        }
        else
        {
            parent[v] = u;
            u++;
        }
    }
    // this is funtion for finding circle number
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        int m = isConnected[0].size();
        vector<int> parent(n);
        vector<int> rank(n, 0);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if ((isConnected[i][j] == 1) && (findPar(i, parent) != findPar(j, parent)))
                {
                    uni(i, j, parent, rank);
                }
            }
        }
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (parent[i] == i)
            {
                count++;
            }
        }
        return count;
    }
};
