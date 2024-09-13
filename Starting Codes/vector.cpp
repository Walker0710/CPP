#include<iostream>
#include<vector>
using namespace std;

int main()  {

    vector<int> v;
    cout<<"size "<<v.capacity()<<endl;

    v.push_back(1);
    cout<<"size "<<v.capacity()<<endl;

    v.push_back(2);
    cout<<"size "<<v.capacity()<<endl;

    v.push_back(3);
    cout<<"size "<<v.capacity()<<endl;

    cout<<"element at 2nd index "<<v.at(2)<<endl;

    cout<<"front "<<v.front()<<endl;
    cout<<"back "<<v.back()<<endl;

    cout<<"before pop"<<endl;
    for(int i:v)  {

        cout<<i<<" ";
    }

    cout<<endl;

    v.pop_back();

    cout<<"afer pop"<<endl;
    for(int i:v)  {

        cout<<i<<" ";
    }

    cout<<"before clear size "<<v.size()<<endl;

    v.clear();
    cout<<"after clear size "<<v.size()<<endl;
}





