#include<iostream>
#include<math.h>

using namespace std;

int main() {

int  n;
cin>>n;

int ans = 0;

for(int i =0; n; i++) {

    int bit = n&1;
    
    if(bit == 1){

        ans = ans;
    }

    if(bit == 0) {

        ans = ans + pow(10,i);
    }

    n = n>>1;

}

cout<<"ans is "<<ans;
}