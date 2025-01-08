#include <bits/stdc++.h>

using namespace std;

// << ,

//noob
vector<int> factorial(int n)
{
    int yoo = 1;

    for(int i = 1; i<=n; i++) {
        yoo = yoo*i;
    }

    vector<int> ans;

    while(yoo != 0) {
        int toPush = yoo%10;
        yoo = yoo/10;

        ans.push_back(toPush);
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

//pro
vector<int> factorial(int n) {
    vector<int> result;
    result.push_back(1); 

    for (int i = 2; i <= n; i++) {
        int carry = 0;

        for (int j = result.size() - 1; j >= 0; j--) {
            int product = result[j] * i + carry;
            result[j] = product % 10; // Update the current digit
            carry = product / 10;    // Carry for the next digit
        }

        // Handle remaining carry
        while (carry > 0) {
            result.insert(result.begin(), carry % 10);
            carry /= 10;
        }
    }

    return result;
}
