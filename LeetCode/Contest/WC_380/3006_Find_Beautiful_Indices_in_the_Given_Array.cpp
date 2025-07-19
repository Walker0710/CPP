#include <bits/stdc++.h>

using namespace std;

// << ,

class Solution {
public:
    void computeLPSArray(string& pat, int M, vector<int>& lps) {
        int len = 0;
        lps[0] = 0;
        int i = 1;
        while (i < M) {
            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    vector<int> KMPSearch(string& pat, string& txt) {
        int M = pat.length();
        int N = txt.length();

        vector<int> lps(M, 0);
        vector<int> result;

        computeLPSArray(pat, M, lps);

        int i = 0;
        int j = 0;
        while ((N - i) >= (M - j)) {
            if (pat[j] == txt[i]) {
                j++;
                i++;
            }

            if (j == M) {
                result.push_back(i - j);
                j = lps[j - 1];
            } else if (i < N && pat[j] != txt[i]) {
                if (j != 0)
                    j = lps[j - 1];
                else
                    i = i + 1;
            }
        }
        return result;
    }

    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> one = KMPSearch(a, s);
        vector<int> two = KMPSearch(b, s);
        vector<int> ans;

        sort(two.begin(), two.end());  

        for (int i = 0; i < one.size(); i++) {
            int ai = one[i];
            
            auto it = lower_bound(two.begin(), two.end(), ai - k);

            while (it != two.end() && *it <= ai + k) {
                ans.push_back(ai);
                break;
            }
        }

        return ans;
    }
};
