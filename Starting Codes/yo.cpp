#include<iostream>
using namespace std;

int bitset(int n)   {

int count = 0

while(n>0)  {

if(n&1 == 1){

    count++;
    n=n>>1;
    
}

}

return count;

}


int sumofBS(int a,int b)  {

    int ans = bitset(a)+bitset(b);

    return ans;

}



int main()  {

int a,b;
cin>> a >> b;

cout<<"answer is "<<sumofBS(a,b)<<endl;

return 0;

}