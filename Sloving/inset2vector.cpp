#include<iostream>    
#include<vector> 
using namespace std;
int main()
{  
	vector<int> vec {2,4,6,8};
	vector<int> vec2 {1,3,5,7};
	cout<<"Intially first vector: ";
	for(auto i=vec.begin(); i<vec.end(); i++)
	{
		cout<<" "<<*i;
	}
	cout<<"\nIntially second vector: ";
	for(auto i=vec2.begin(); i<vec2.end(); i++)
	{
		cout<<" "<<*i;
	}
	
	//Inserting vec2 at the beginning of the vec vector
	vec.insert(vec.begin(),vec2.begin(),vec2.end());
	
	cout<<"\n\nThe modified vector is: ";
	for(auto i=vec.begin(); i<vec.end(); i++)
	{
		cout<<" "<<*i;
	}
	return 0;
}