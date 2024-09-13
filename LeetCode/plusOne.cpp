#include<iostream>
#include<vector>

using namespace std;
    
    vector<int> plusOne(vector<int>& digits) {

            int n = digits.size();
    int carry = 1; // Initialize the carry to 1 since we want to increment by one

    for (int i = n - 1; i >= 0; --i) {
        int sum = digits[i] + carry;
        digits[i] = sum % 10; // Update the current digit
        carry = sum / 10;      // Update the carry

        // If there is no more carry, we can stop the loop
        if (carry == 0) {
            break;
        }
    }

    // If there is still a carry, insert a new digit at the beginning
    if (carry > 0) {
        digits.insert(digits.begin(), carry);
    }

    return digits;
        
    }