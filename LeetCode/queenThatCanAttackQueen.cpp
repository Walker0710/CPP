#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> qn(8,vector<int>(8,0)),ans;
        
        for(int i=0;i<queens.size();i++)
        {
            qn[queens[i][0]][queens[i][1]]=1;
        }
        //same col towards up
        for(int i=king[0]-1;i>=0;i--)
        {
            if(qn[i][king[1]])
            {
                ans.push_back({i,king[1]});
                break;
            }
        }
        //same col towards down
        for(int i=king[0]+1;i<8;i++)
        {
            if(qn[i][king[1]])
            {
                ans.push_back({i,king[1]});
                break;
            }
        }
        //same row towards left
        for(int i=king[1]-1;i>=0;i--)
        {
            if(qn[king[0]][i])
            {
                ans.push_back({king[0],i});
                break;
            }
        }
        //same row towards right
        for(int i=king[1]+1;i<8;i++)
        {
            if(qn[king[0]][i])
            {
                ans.push_back({king[0],i});
                break;
            }
        }
        //top left
        int j=king[1];
        for(int i=king[0];i>=0 && j>=0;i--)
        {
            if(qn[i][j])
                {
                    ans.push_back({i,j});
                    break;
                }
            j--;
        }
        //bottom right
        j=king[1];
        for(int i=king[0];i<8 && j<8;i++)
        {
            if(qn[i][j])
                {
                    ans.push_back({i,j});
                    break;
                }
            j++;
        }
        //top right
        j=king[1];
        for(int i=king[0];i>=0 && j<8;i--)
        {
            if(qn[i][j])
                {
                    ans.push_back({i,j});
                    break;
                }
            j++;
        }
        //bottom  left
        j=king[1];
        for(int i=king[0];i<8 && j>=0;i++)
        {
            if(qn[i][j])
                {
                    ans.push_back({i,j});
                    break;
                }
            j--;
        }
        
        return ans;
        
    }

//2nd approch
vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& k) {
    bool b[8][8] = {};
    for (auto& q : queens) b[q[0]][q[1]] = true;
    vector<vector<int>> res;
    for (auto i = -1; i <= 1; ++i)
        for (auto j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) continue;
            auto x = k[0] + i, y = k[1] + j;
            while (min(x, y) >= 0 && max(x, y) < 8) {
                if (b[x][y]) {
                    res.push_back({ x, y });
                    break;
                }
                x += i, y += j;
            }
        }
    return res;
}