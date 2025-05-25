#include <bits/stdc++.h>

using namespace std;

// << ,

uint32_t reverseBits(uint32_t n)
{
    string binary = "";
    for (int i = 0; i < 32; i++)
    {
        if (n & (1 << i))
        {
            binary += '1';
        }
        else
        {
            binary += '0';
        }
    }

    uint32_t res = 0;
    for (int i = 0; i < 32; i++)
    {
        if (binary[31 - i] == '1')
        {
            res |= (1 << i);
        }
    }

    return res;
}