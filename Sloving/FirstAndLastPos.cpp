#include<iostream>
#include<vector>

using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {

    int n = nums.size();
    int s = 0;
    int e = n-1;

    int mid = (s+e)/2;
    int first;
    int last;

    while(s<e) {

        if(nums[mid] == target) {

            if(nums[mid - 1] != target) {

                first = mid;
            }
        }

        if(nums[mid] > target) {

            e = mid - 1;
        }

        if(nums[mid] < target) {

            s = mid + 1;
        }

        mid = (s+e)/2;
    }

    while(s<e) {

        if(nums[mid] == target) {

            if(nums[mid + 1] != target) {

                last = mid;
            }
        }

        if(nums[mid] > target) {

            e = mid - 1;
        }

        if(nums[mid] < target) {

            s = mid + 1;
        }

        mid = (s+e)/2;
    }

    return {first, last};
}

int main() {

    vector<int> arr = {5,7,8,10};
}





    int n = nums.size();
    int s = 0;
    int e = n-1;

    int mid = (s+e)/2;
    int first;
    int last;

    while(s<=e) {

        if(nums[mid] == target) {

            if(mid == 0 || nums[mid - 1] != target) {

                first = last = mid;
                break;
            }
        }

        if(nums[mid] > target) {

            e = mid - 1;
        }

        if(nums[mid] < target) {

            s = mid + 1;
        }

        mid = (s+e)/2;
    }

    s = 0;
    e = n-1;

    while(s<=e) {

        if(nums[mid] == target) {

            if(nums[mid + 1] != target || mid == n) {

                last = mid;
                break;
            }
        }

        if(nums[mid] > target) {

            e = mid - 1;
        }

        if(nums[mid] < target) {

            s = mid + 1;
        }

        mid = (s+e)/2;
    }

    return {first, last};
        
    }