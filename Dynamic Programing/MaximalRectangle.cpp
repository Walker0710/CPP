#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <map>
#include<stack>

using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n) {

    stack<int> s;
    s.push(-1);
    vector<int> ans;

    for(int i = n-1; i>=0; i--) {

        int curr = arr[i];

        while(s.top() != curr && arr[s.top()] >= curr)
        s.pop();

        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

vector<int> prevSmallerElement(vector<int> &arr, int n) {

    stack<int> s;
    s.push(-1);
    vector<int> ans;

    for(int i = 0; i<n; i++) {

        int curr = arr[i];

        while(s.top() != curr && arr[s.top()] >= curr)
        s.pop();

        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

int largestRectangleArea(vector<int> &height) {

    int n = height.size();
    vector<int> next(n);
    next = nextSmallerElement(height, n);

    vector<int> prev(n);
    prev = prevSmallerElement(height, n);
    int area = INT_MIN;

    for(int i = 0; i<n; i++) {

        int l = height[i];

        if(next[i] == -1)
        next[i] = n;

        int b = next[i] - prev[i] - 1;

        int newArea = l*b;
        area = max(area, newArea);
    }

    return area;
}


int maximalRectangle(vector<vector<char>>& matrix) {

    int maxi = INT_MIN;
    vector<int> histogram(matrix[0].size(), 0);

    for(int i = 0; i<matrix.size(); i++) {

        for(int j=0; j<histogram.size(); j++) {

            if(matrix[i][j] == '1')
            histogram[j]++;

            else 
            histogram[j] = 0;
        }
        maxi = max(maxi, largestRectangleArea(histogram));
    }

    return maxi;
}