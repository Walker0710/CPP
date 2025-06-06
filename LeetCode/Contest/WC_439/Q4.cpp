#include <bits/stdc++.h>

using namespace std;

// << ,

string generateString(string str1, string str2)
{
    int n = str1.size(), m = str2.size();
    string res(n + m - 1, 'a');
    vector<bool> fixed(n + m - 1);

    for (int i = 0; i < n; i++)
    {
        if (str1[i] == 'T')
        {
            for (int j = 0; j < m; j++)
            {
                res[i + j] = str2[j];
                fixed[i + j] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (str1[i] == 'F')
        {
            bool same = 1;
            for (int j = 0; j < m; j++)
            {
                if (res[i + j] != str2[j])
                {
                    same = 0;
                    break;
                }
            }

            if (same)
            {
                for (int j = m - 1; j >= 0; j--)
                {
                    if (!fixed[i + j])
                    {
                        res[i + j] = 'b';
                        break;
                    }
                }
            }
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        bool same = 1;
        for (int j = 0; j < m; j++)
        {

            if (res[i + j] != str2[j])
            {
                same = 0;
                break;
            }
        }

        if ((str1[i] == 'T' && !same) || (str1[i] == 'F' && same))
            return "";
    }

    return res;
}