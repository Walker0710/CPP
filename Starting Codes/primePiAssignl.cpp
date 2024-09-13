#include<iostream>
#include<math.h>

using namespace std;

bool prime(int n) {

    for(int i = 2; i<n; i++) {

        if(n%i == 0) {

           return 0;
        }
    }

    return 1;
}



int reverse(int n) {

    int ans = 0;

    int n;

    for(int i = 0; n; i++){

        int digit = n%10;

        ans = digit + 10*ans;

        n = n/10;

    }

    return ans;
}

bool palindrome(int n) {

    int done = reverse(n);

    if(n == done) {

        return 1;
    }

    else{

        return 0;
    }
}




int main () {

    int n1; 
    cout<<"enter the upper limit"<<endl;
    cin>>n1;

    int n2;
    cout<<"enter the lower limit"<<endl;
    cin>>n2;

    for(int n = n1; n >= n1 && n <= n2; n++) {

        if(prime) {

            if(palindrome) {

                cout<<n<<" is prime palindrome"<<endl;
            } 

            else{

                cout<<n<<" is prime but not palindrome"<<endl;
            }
        }

        else{

            cout<<n<<" not a prime palindrome"<<endl;
        }
    }



        



}