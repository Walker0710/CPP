#include<iostream>

using namespace std;

int lcm(int a, int b) {

    int lcm;

    int max;

    if(a < b) {

        max = b;
    }

    else {

        max = a;
    }

    while(1) {

        if((max%a == 0) && (max%b == 0)) {

            lcm = max;
            break;
        }

        max++;
    }

    return lcm;
}

int hcf(int a, int b) {

    int hcf;

    for(int i = 1; i<=a && i<=b; i++) {

        if(a%i == 0 && b%i == 0) {

            hcf = i;
        }
    }

    return hcf;
}

int main() {

    int a;
    int b;

    cin>>a>>b;

    int ans = hcf(a,b);

    cout<<ans;
}

