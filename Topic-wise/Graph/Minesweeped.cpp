#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<char>> updateBoard(vector<vector<char>> &board, vector<int> &click)
    {
        int n = board.size(), m = board[0].size();
        int x = click[0], y = click[1];

        if (board[x][y] == 'M')
        {
            board[x][y] = 'X';
            return board;
        }

        queue<pair<int, int>> q;
        q.push({x, y});

        // this part i mostly forget to use : this is best for the direction search in matrix kinda problem
        int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

        while (!q.empty())
        {
            auto [cx, cy] = q.front();
            q.pop();

            int mines = 0;
            for (int d = 0; d < 8; d++)
            {
                int nx = cx + dx[d], ny = cy + dy[d];
                if (nx >= 0 && ny >= 0 && nx < n && ny < m && board[nx][ny] == 'M')
                    mines++;
            }

            if (mines > 0)
            {
                board[cx][cy] = mines + '0';
            }
            else
            {
                board[cx][cy] = 'B';
                for (int d = 0; d < 8; d++)
                {
                    int nx = cx + dx[d], ny = cy + dy[d];
                    if (nx >= 0 && ny >= 0 && nx < n && ny < m && board[nx][ny] == 'E')
                    {
                        board[nx][ny] = 'B'; // if don't put this statement here than code with give TLE as it will stuck in infinite loop.
                        q.push({nx, ny});
                    }
                }
            }
        }

        return board;
    }
};

void Print(vector<vector<char>>&board){
    int n = board.size() , m = board[0].size() ;
    for (int i = 0; i < n; i++)
    {
        for(int j = 0 ; j<m ;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    
}

int main()
{
    vector<vector<char>> board = {{'E','E','E'},{'E','E','M'},{'E','M','E'}} ;
    cout<<"Before : "<<endl;
    Print(board) ;
    vector<int>click = {0,0} ;
    Solution s ;
    vector<vector<char>>ans = s.updateBoard(board, click);
    cout<<"After : "<<endl;
    Print(ans) ;
    cout<<endl;
    
    return 0;
}