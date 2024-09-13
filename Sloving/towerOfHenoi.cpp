#include<iostream>

using namespace std;

void move(int n, int s, int e, int h) {

    //base case
    if(n == 3) {

        cout<<s<<" -> "<<e<<endl;
        cout<<s<<" -> "<<h<<endl;
        cout<<e<<" -> "<<h<<endl;
        cout<<s<<" -> "<<e<<endl;
        cout<<h<<" -> "<<s<<endl;
        cout<<h<<" -> "<<e<<endl;
        cout<<s<<" -> "<<e<<endl;
    }

    //recursive call
    move(n-1, s, h, e);

    cout<<s<<" -> "<<e<<endl;

    move(n-1, h, e, s);
}

int main() {

    int n;
    cout<<"enter the value of n"<<endl;
    cin>>n;

    move(n, 1, 3, 2);

    return 0;
}