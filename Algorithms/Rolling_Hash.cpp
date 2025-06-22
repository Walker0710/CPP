#include <bits/stdc++.h>

using namespace std;

// << ,

bool isPrefix(const vector<long> &hash, int start1, int end1, int start2, int end2, long mod, const vector<long> &pow)
{
    int len1 = end1 - start1;
    int len2 = end2 - start2;

    if (len1 > len2)
    {
        return false;
    }

    long hash1 = (hash[end1] - (hash[start1] * pow[len1]) % mod + mod) % mod;
    long hash2 = (hash[start2 + len1] - (hash[start2] * pow[len1]) % mod + mod) % mod;

    return hash1 == hash2;
}

int beautifulSplits(vector<int> &nums)
{
    int n = nums.size();
    
    if (n < 3)
    {
        return 0; 
    }

    long mod = 1e9 + 7;
    long base = 31;

    vector<long> prefixHash(n + 1, 0); 
    vector<long> pow(n + 1, 1);        

    for (int i = 0; i < n; i++)
    {
        pow[i + 1] = (pow[i] * base) % mod;
        prefixHash[i + 1] = (prefixHash[i] * base + nums[i]) % mod;
    }

    int count = 0;

    for (int i = 1; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            bool valid = false;

            if (isPrefix(prefixHash, 0, i, i, j, mod, pow))
            {
                valid = true;
            }

            if (!valid && isPrefix(prefixHash, i, j, j, n, mod, pow))
            {
                valid = true;
            }

            if (valid)
            {
                count++;
            }
        }
    }

    return count;
}