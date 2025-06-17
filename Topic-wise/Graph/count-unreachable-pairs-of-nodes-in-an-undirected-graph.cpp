#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void Helper(vector<vector<int>> &adj_list, int x, vector<bool> &visited,
                int &cnt)
    {
        visited[x] = true;
        cnt++;
        for (int i = 0; i < adj_list[x].size(); i++)
        {
            if (!visited[adj_list[x][i]])
                Helper(adj_list, adj_list[x][i], visited, cnt);
        }
    }

public:
    long long countPairs(int n, vector<vector<int>> &edges)
    {
        long long ans = 0;
        int edg_size = edges.size();
        vector<vector<int>> adj_mat(n);
        for (int i = 0; i < edg_size; i++)
        {
            adj_mat[edges[i][0]].push_back(edges[i][1]);
            adj_mat[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> visited(n, false);
        vector<int> temp;
        for (int i = 0; i < n; i++)
        {
            int cnt = 0;
            if (!visited[i])
            {
                Helper(adj_mat, i, visited, cnt);
            }
            temp.push_back(cnt);
        }
        int tem_size = temp.size();
        vector<int> suffix_sum(tem_size, 0);
        int sum = 0;
        for (int i = tem_size - 1; i > 0; i--)
        {
            sum += temp[i];
            suffix_sum[i - 1] = sum;
        }
        
        // used suffix sum to calculate the product which reduces the t.c from O(n^2){when using two loops} to O(2*n)
        for (int i = 0; i < tem_size; i++)
        {
            ans += (1LL * temp[i] * suffix_sum[i]);
        }

        return ans;
    }
};

int main()
{
    int n = 7 ;
    vector<vector<int>> edges ={{0,2},{0,5},{2,4},{1,6},{5,4}} ;
    Solution s;
    cout<<"Total such pairs are : "<<s.countPairs(n , edges)<<endl;

    return 0;
}