#include<iostream>
#include<vector>

using namespace std;

int sum3closest(vector<int> &nums, int target) {

    for (int i = 1; i < nums.size(); i++)
    {

        for (int j = 0; j < nums.size() - i; j++)
        {

            if (nums[j] > nums[j + 1])
            {

                swap(nums[j], nums[j + 1]);
            }
        }
    }

    int low = 0;
    int high = nums.size() - 1;

    vector<int> ans;

    for (int i = 0; i < nums.size(); i++)
    {

        while (low < high)
        {

            if (nums[i] + nums[low] + nums[high] < target)
            {

                low++;

                if(nums[i] + nums[low] + nums[high] > target) {

                    ans.push_back(nums[i] + nums[high] + nums[low]);
                    ans.push_back(nums[i] + nums[high] + nums[low-1]);
                }
            }

            if (nums[i] + nums[low] + nums[high] > target)
            {

                high--;

                if(nums[i] + nums[low] + nums[high] < target) {

                    ans.push_back(nums[i] + nums[low] + nums[high]);
                    ans.push_back(nums[i] + nums[low] + nums[high+1]);
                }
            }
        }
    }

    int min = INT16_MAX;

        for(int i = 0; i < nums.size(); i++) {

            if(nums[i] < min) {

                min = nums[i];
            }
        }
 
    return min;
}

int main() {


}







































































