#include<iostream>

using namespace std;

int main() {

    float s;
    cout<<"Enter the starting temp"<<endl;
    cin>>s;

    float e;
    cout<<"Enter the ending temp"<<endl;
    cin>>e;

    for(float i = s; i>=s && i<=e; i++) {

        float celsius = (i - 32.0)*(5.0/9.0);

        cout<<i<<" fahrenheit in celcius is "<<celsius;

        float kelvin = celsius + 273;

        cout<<" and in kelvin is "<<kelvin;

        cout<<endl;
    }
}

