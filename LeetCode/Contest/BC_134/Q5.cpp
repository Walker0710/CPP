#include <bits/stdc++.h>

using namespace std;

// << ,

bool isPossi(int mid, int k, vector<int> &arr)
{
    int cnt = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        cnt = cnt + min(arr[i], mid);
    }

    if (cnt >= mid * k)
    {
        return true;
    }

    return false;
}

int solve(vector<int> &arr, int k)
{
    int st = 0;
    int en = 1e9;
    int ans = 0;

    while (st <= en)
    {
        int mid = (st + en) / 2;

        if (isPossi(mid, k, arr))
        {
            ans = mid;
            st = mid + 1;
        }
        else
        {
            en = mid - 1;
        }
    }

    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    int k = 4;

    int yoo = solve(arr, k);
    cout << yoo << endl;

    return 0;
}