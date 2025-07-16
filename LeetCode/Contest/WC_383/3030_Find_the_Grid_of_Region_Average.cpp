#include <bits/stdc++.h>

using namespace std;

// << ,

vector<int> xm{-1, +1, 0, 0};
vector<int> ym{0, 0, -1, +1};

bool check(int x1, int x2, int y1, int y2, int diff, vector<vector<int>>& g)
{
    int xn, yn;
    
    for(int i=x1; i<=x2; ++i)
    {
        for(int j=y1; j<=y2; ++j)
        {
            for(int k = 0; k<4; ++k)
            {
                xn = i + xm[k];
                yn = j + ym[k];
                
                if(xn>=x1 && xn<=x2 && yn>=y1 && yn<=y2)
                {
                    int v1 = g[xn][yn];
                    int v2 = g[i][j];
                    
                    if(abs(v1 - v2) > diff)
                        return false;
                }
            }
        } 
    }

    return true;
}

int find(int x1, int x2, int y1, int y2, vector<vector<int>>& g)
{
    int res = 0;
    
    for(int i=x1; i<=x2; ++i)
    {
        for(int j=y1; j<=y2; ++j)
        {
            res+=g[i][j];
        }
    }    

    res = res/9;
    return res;
}



class Solution {
public:
    vector<vector<int>> resultGrid(vector<vector<int>>& g, int k) {
        
        int m = g.size(); int n = g[0].size();
        map< pair<int, int>, vector<int>>mp;
        
        vector<int> em;
        
        for(int i=0; i<m; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                mp[{i,j}] = em;
            }
        }
        
        
        for(int x1=0, x2=2; x2<m; ++x1, ++x2)    
        {
            for(int y1=0, y2=2; y2<n; ++y1, ++y2)
            {
                if(check(x1, x2, y1, y2, k, g)) 
                {
                    int avg = find(x1, x2, y1, y2, g); 
                    
                    for(int i=x1; i<=x2; ++i)
                    {
                        for(int j=y1; j<=y2; ++j)
                        {
                            mp[{i, j}].push_back(avg);
                        }
                    }
                
                }
            
            }
        }
        
        vector<int> t1(n, 0);
        vector<vector<int>> res(m, t1);
        vector<int> curr;
        
        for(auto i = mp.begin(); i!=mp.end(); ++i)
        {
            int x = i->first.first;
            int y = i->first.second;
            
            curr = i->second;
            int sum = 0;
            
            for(int j=0; j<curr.size(); ++j)
                sum+=curr[j];
            
            if(curr.size() == 0)
                res[x][y] = g[x][y];
            
            else
            {
                sum = sum/curr.size();
                res[x][y] = sum;
            }                  
        }
        return res;    
    }
};