#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define int long long
// #define vec(v) vector<int> v

// << ,

bool chk(string str)
{
    stack<char> s;
    for (auto x : str)
    {
        if (x == '(')
        {
            s.push(x);
        }
        else
        {
            if (s.empty())
            {
                return false;
            }
            else
            {
                s.pop();
            }
        }
    }
    return s.empty();
}

void solve()
{
    int n;
    cin >> n;

    string str;
    cin >> str;

    int open = 0;
    int close = 0;

    for (auto x : str)
    {
        open += (x == '(');
        close += (x == ')');
    }

    if (open != close)
    {
        cout << -1 << endl;
    }

    else
    {
        int cl = 0, op = 0;
        string tmp = str;
        reverse(tmp.begin(), tmp.end());

        if ((chk(str)) || (chk(tmp)))
        {
            cout << 1 << endl;
            for (int i = 0; i < n; i++)
            {
                cout << 1 << " ";
            }
            cout << endl;
        }

        else
        {
            for (int i = 0; i < n / 2; i++)
            {
                if (str[i] == '(')
                    op++;
            }

            for (int i = n / 2; i < n; i++)
            {
                if (str[i] == ')')
                    cl++;
            }

            int x = min(op, cl);
            op = 0;
            cout << 2 << endl;

            for (int i = 0; i < n / 2; i++)
            {
                if (str[i] == '(')
                {
                    op++;
                    if (op <= x)
                    {
                        cout << 1 << " ";
                    }
                    else
                    {
                        cout << 2 << " ";
                    }
                }
                else
                {
                    cout << 2 << " ";
                }
            }

            for (int i = n / 2; i < n; i++)
            {
                if (str[i] == ')')
                {
                    if (x > 0)
                    {
                        cout << 1 << " ";
                        x--;
                    }
                    else
                    {
                        cout << 2 << " ";
                    }
                }
                else
                {
                    cout << 2 << " ";
                }
            }
            cout << endl;
        }
    }
}

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
