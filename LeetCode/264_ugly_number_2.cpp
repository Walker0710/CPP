#include <iostream>
#include <cmath>
#include <unordered_set>
#include <set>

using namespace std;

// brut force
bool isUgly(int n)
{
    if (n <= 0)
        return false;

    while (n % 2 == 0)
        n /= 2;

    while (n % 3 == 0)
        n /= 3;

    while (n % 5 == 0)
        n /= 5;

    return n == 1;
}

int nthUglyNumber(int n)
{
    int count = 1;

    int i = 1;

    while (count != n)
    {

        i++;

        if (isUgly(i))
            count++;
    }

    return i;
}

// trying to optimize
bool isUgly(int num, unordered_set<int> &mem)
{
    if (num == 1)
        return true;

    if (num <= 0)
        return false;

    if (mem.find(num) != mem.end())
        return true;

    if (num % 2 == 0 && isUgly(num / 2, mem))
        return true;
    if (num % 3 == 0 && isUgly(num / 3, mem))
        return true;
    if (num % 5 == 0 && isUgly(num / 5, mem))
        return true;

    return false;
}

int nthUglyNumber(int n)
{

    int count = 1;
    unordered_set<int> mem;

    int i = 1;
    while (count != n)
    {
        i++;

        if (isUgly(i, mem))
        {
            count++;
            mem.insert(i);
        }
    }
    return i;
}

//
int nthUglyNumber(int n)
{
    set<long> rec;
    long nthNum = 1;
    rec.insert(nthNum);
    
    for (int i = 0; i < n; i++)
    {
        nthNum = *rec.begin();
        rec.erase(nthNum);
        rec.insert(nthNum * 2);
        rec.insert(nthNum * 3);
        rec.insert(nthNum * 5);
    }

    return nthNum;
}


