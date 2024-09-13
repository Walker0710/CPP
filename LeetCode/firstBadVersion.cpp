#include<iostream>

using namespace std;

bool isBadVersion(int version) {


}

int firstBadVersion(int n) {

    int s = 0;
    int e = n;

    int mid = s + (e-s)/2;

    while(e>s) {

        if(isBadVersion(mid)) {

            e = mid;
        }

        else {

            s = mid + 1;
        }

        mid = (e-s)/2 + s;
    }

    return s;
}