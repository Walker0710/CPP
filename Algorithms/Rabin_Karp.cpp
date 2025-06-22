#include <bits/stdc++.h>

using namespace std;

// << ,

// Rabin-Karp Algorithm

#define d 256
const int q = 101;

vector<int> search(string pattern, string text)
{
    int m = pattern.length();
    int n = text.length();

    int i, j;
    
    int p = 0; // hash value for pattern
    int t = 0; // hash value for text
    int h = 1;
    
    vector<int> result;
    
    // The value of h would be "pow(d, m-1) % q"
    for (i = 0; i < m - 1; i++)
        h = (h * d) % q;

    // Calculate the hash value of pattern and first window of text
    for (i = 0; i < m; i++)
    {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // Slide the pattern over text one by one
    for (i = 0; i <= n - m; i++)
    {
        // Check the hash values of current window of text and pattern
        if (p == t)
        {
            // Check for characters one by one
            for (j = 0; j < m; j++)
            {
                if (text[i + j] != pattern[j])
                    break;
            }

            if (j == m)
                result.push_back(i); // Pattern found at index i
        }

        // Calculate hash value for next window of text
        if (i < n - m)
        {
            t = (d * (t - text[i] * h) + text[i + m]) % q;

            // We might get negative value of t, convert it to positive
            if (t < 0)
                t = (t + q);
        }
    }
    return result;
}

int main()
{
    string text = "ABCCDDAEFGABCD";
    string pattern = "ABCD";
    vector<int> occurrences = search(pattern, text);

    for (int index : occurrences)
        cout << "Pattern found at index: " << index << endl;

    return 0;
}
