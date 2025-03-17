#include <vector>
#include <climits>
#include <string>
#include <cctype>
#include <iostream>

using namespace std;

struct MinMax {
    int max_val;
    int min_val;
};

int maxExpressionValue(const string& expression) {
    vector<int> nums;
    vector<char> ops;
    int current_num = 0;
    for (char c : expression) {
        if (isdigit(c)) {
            current_num = current_num * 10 + (c - '0');
        } else {
            nums.push_back(current_num);
            ops.push_back(c);
            current_num = 0;
        }
    }
    nums.push_back(current_num);
    
    int n = nums.size();
    if (n == 0) return 0;
    
    vector<vector<MinMax>> dp(n, vector<MinMax>(n));
    
    for (int i = 0; i < n; ++i) {
        dp[i][i].max_val = nums[i];
        dp[i][i].min_val = nums[i];
    }
    
    for (int l = 2; l <= n; ++l) { // Length of the subexpression
        for (int i = 0; i <= n - l; ++i) {
            int j = i + l - 1;
            dp[i][j].max_val = INT_MIN;
            dp[i][j].min_val = INT_MAX;
            for (int k = i; k < j; ++k) {
                MinMax left = dp[i][k];
                MinMax right = dp[k+1][j];
                char op = ops[k];
                
                int current_max, current_min;
                if (op == '+') {
                    current_max = left.max_val + right.max_val;
                    current_min = left.min_val + right.min_val;
                } else { // '-'
                    current_max = left.max_val - right.min_val;
                    current_min = left.min_val - right.max_val;
                }
                
                if (current_max > dp[i][j].max_val) {
                    dp[i][j].max_val = current_max;
                }
                if (current_min < dp[i][j].min_val) {
                    dp[i][j].min_val = current_min;
                }
            }
        }
    }
    
    return dp[0][n-1].max_val;
}

int main() {
    string expression = "1+3-2-5+1-6+7";
    cout << maxExpressionValue(expression) << endl;
    return 0;
}