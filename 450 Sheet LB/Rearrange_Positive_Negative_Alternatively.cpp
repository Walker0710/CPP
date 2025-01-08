#include <bits/stdc++.h>

using namespace std;

// << ,

void rightRotate(vector<int> &arr, int start, int end)
{
    int temp = arr[end];
    
    for (int i = end; i > start; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[start] = temp;
}

void rearrange(vector<int> &arr)
{
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 0 && i % 2 == 1)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (arr[j] < 0)
                {
                    rightRotate(arr, i, j);
                    break;
                }
            }
        }

        else if (arr[i] < 0 && i % 2 == 0)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (arr[j] >= 0)
                {
                    rightRotate(arr, i, j);
                    break;
                }
            }
        }
    }
}