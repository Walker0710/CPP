#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <limits.h>
#include <map>
#include <unordered_set>

using namespace std;

// << ,


void solve()
{
    long long n, k, x;
    cin >> n >> k >> x;

    vector<long long> a(n);
    for (long long i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    vector<long long> gaps;

    for (long long i = 1; i < n; i++)
    {
        long long diff = a[i] - a[i - 1];
        if (diff > x)
        {
            gaps.push_back(diff);
        }
    }

    sort(gaps.begin(), gaps.end());

    int groups = gaps.size() + 1;

    for (long long i = 0; i < gaps.size() && k > 0; i++)
    {
        long long needed_students = (gaps[i] - 1) / x; 
        if (needed_students <= k)
        {
            k -= needed_students;
            groups--;
        }
        else
        {
            break; 
        }
    }

    cout << groups << endl;
}

int main()
{
    solve();
    return 0;
}


//yoo 

// << ,

void solve()
{
    long long n, k, x;
    cin >> n >> k >> x;

    vector<long long> a(n);
    for (long long i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    vector<long long> gaps(n-1);

    for (long long i = 0; i < n-1; i++)
    {
        long long diff = a[i+1] - a[i];
        if (diff <= x)
        {
            gaps[i] = 0;
        }

        else {
            long long value = diff - x;
            gaps[i] = value/x + (value%x != 0);
        }
    }

    sort(gaps.begin(), gaps.end());

    long long groups = n;

    for (long long i = 0; i < gaps.size(); i++)
    {
        if (gaps[i] <= k)
        {
            k -= gaps[i];
            groups--;
        }
    }

    cout << groups << endl;
}

int main()
{
    solve();
    return 0;
}

