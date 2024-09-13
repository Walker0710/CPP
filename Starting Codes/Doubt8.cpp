#include<iostream>
#include<vector>

using namespace std;

int main() {

    char name[20];

    cout<<"enter the name "<<endl;
    cin>>name;

    cout<<"your name is "<<endl<<name<<endl;

    cout<<"length"<<GetLength(name)<<endl;


}





int GetLength(char name[]) {

    int count = 0;

    for(int i=0; name[i] != '/0'; i++) {

        count++;
    }

    return count;
}

