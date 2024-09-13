#include<iostream>

using namespace std;


int sumOfRow(int arr[3][4]) {

    for(int i=0; i<3; i++) {
        
        int sum = 0;

       

        for(int j=0; j<4; j++) {

            sum = sum + arr[i][j];

          
        }

         cout<<"sum of row no. "<<i+1<<" is "<<sum<<endl;


    }
}

int main()  {

    int arr[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};

    sumOfRow(arr);

    return 0;
}