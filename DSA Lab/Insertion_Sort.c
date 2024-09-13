#include <stdio.h>

// iterative way
void sort(int arr[], int n)
{
    for (int i = 1; i < n; ++i)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int arr[] = {5, 1, 3, 9, 7, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    sort(arr, n);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}



// recursive way
void sortRecursive(int arr[], int n)
{
    if (n <= 1)
        return;

    sortRecursive(arr, n - 1);

    int last = arr[n - 1];
    int j = n - 2;

    while (j >= 0 && arr[j] > last)
    {
        arr[j + 1] = arr[j];
        j--;
    }

    arr[j + 1] = last;
}

int main()
{
    int arr[] = {5, 1, 3, 9, 7, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    sortRecursive(arr, n);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
