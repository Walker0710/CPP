#include<iostream>
#include<vector>

using namespace std;

int anyArea(vector<int> &height, int i, int j) {

    int ans = (j - i)*min(height[i], height[j]);

    return ans;
}

int maxArea(vector<int> &height) {

    int maxArea = 0;

    for(int i = 0; i<height.size(); i++) {

        for(int j = i+1; j<height.size(); j++) {

            int area = anyArea(height, i , j);

            if(area > maxArea) {

                maxArea = area;
            }
        }
    }

    return maxArea;
}

int main() {

    vector<int> arr = {1,8,6,2,5,4,8,3,7};

    int max = maxArea(arr);

    cout<<endl<<max<<endl;
}