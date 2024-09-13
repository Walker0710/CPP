#include <iostream>

using namespace std;

int triplet(int arr[], int n)
{

    for (int i = 1; i < n; i++)
    {

        for (int j = 0; j < n - i; j++)
        {

            if (arr[j] > arr[j + 1])
            {

                swap(arr[j], arr[j + 1]);
            }
        }
    }

    int low = 0;
    int high = n - 1;

    for (int i = 0; i < n; i++)
    {

        while (low < high)
        {

            if (arr[i] + arr[low] + arr[high] == 0)
            {

                cout << endl<< arr[i] << " " << arr[low] << " " << arr[high];
                high--;
                low++;
            }

            if (arr[i] + arr[low] + arr[high] < 0)
            {

                low++;
            }

            if (arr[i] + arr[low] + arr[high] > 0)
            {

                high--;
            }
        }
    }
}

int main()
{

    int n;
    cin >> n;

    int yo[n];

    for (int i = 0; i < n; i++)
    {

        cin >> yo[i];
    }

    triplet(yo, 6);
}