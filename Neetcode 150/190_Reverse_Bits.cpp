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

uint32_t reverseBits(uint32_t n)
{
    uint32_t res = 0;

    for (int i = 0; i < 32; i++)
    {
        uint32_t bit = (n >> i) & 1; // giving bit of i th position
        res += (bit << (31 - i)); // takes the extracted bit and places it in the reversed position
    }

    return res;
}