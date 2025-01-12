#include <bits/stdc++.h>

using namespace std;

// << ,

double medianOf2(vector<int> &a, vector<int> &b)
{
    if(a.size() > b.size()) {
        return medianOf2(b, a);
    }

    int x = a.size();
    int y = b.size();

    int low = 0;
    int high = x;

    while(low <= high) {
        int partX = (low + high)/2;
        int partY = (x + y + 1)/2 - partX;

        int maxLeftX = (partX == 0) ? INT_MIN : a[partX -1];
        int minRightX = (partX == x) ? INT_MAX : a[partX];

        int maxLeftY = (partY == 0) ? INT_MIN : b[partY -1];
        int minRightY = (partY == y) ? INT_MAX : b[partY];

        if(maxLeftX <= minRightY && maxLeftY <= minRightX) {
            if((x + y)%2 == 0) {
                return (double)(max(maxLeftX, maxLeftY) + min(minRightX, minRightY))/2;
            }

            else {
                return (double)max(maxLeftX, maxLeftY);
            }
        }

        else if(maxLeftX > minRightY) {
            high = partX - 1;
        }

        else {
            low = partX + 1;
        }
    }
}