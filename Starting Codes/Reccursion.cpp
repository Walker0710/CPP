#include<iostream>

using namespace std;

int fabb(int n) {

    if(n==0) {

        return 0;
    }

    if(n==1) {

        return 1;
    }

    int ans = fabb(n-1) + fabb(n-2);

    return ans;
}