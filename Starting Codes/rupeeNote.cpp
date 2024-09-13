#include<iostream>
#include<math.h>
using namespace std;


int main()  {

int n;
cout<<"enter the amount "<<endl;
cin>>n;

int note;
cout<<"which note "<<endl;
cin>>note;

int a = n/100;

int remain = n%100;
int b = remain/20;

int remain1 = remain%20;
int c = remain1/1;

switch(note)  {

case 100 : 
           cout<<"100 rupee note "<<a<<endl;
           break;

case 20 : 
          cout<<"20 rupee note "<<b<<endl;
          break;

case 1 : 
         cout <<"1 rupee note "<<c<<endl;
         break;

}

cout<<endl;

}