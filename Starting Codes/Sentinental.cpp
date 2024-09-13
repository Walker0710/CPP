#include<iostream>

using namespace std;

int main() {

    int counter = 0;
    int total = 0;
    int grade;

    cout<<"enter the grades and -1 to end"<<endl;;
    cin>>grade;

    while(grade != -1) {

        total = total + grade;
        counter =  counter + 1;

        cout<<"enter the grades and -1 to end"<<endl;
        cin>>grade;
    }

    cout<<endl;

    float avg = (float)total/counter;

    cout<<"avg is "<<avg;
}