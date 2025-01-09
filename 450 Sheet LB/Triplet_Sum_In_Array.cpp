#include <bits/stdc++.h>

using namespace std;

// << ,

bool hasTripletSum(vector<int> &arr, int target)
{
    sort(arr.begin(), arr.end());
    int n = arr.size();

    for (int i = 0; i < n - 2; i++)
    {
        if (i == 0 || (i > 0 && arr[i] != arr[i - 1]))
        {
            int s = i + 1;
            int e = n - 1;
            int yoo = target - arr[i];

            while (e > s)
            {
                if (arr[s] + arr[e] == yoo)
                {
                    return true;
                }

                else if (arr[s] + arr[e] > yoo)
                {
                    e--;
                }

                else
                {
                    s++;
                }
            }
        }
    }

    return false;
}
