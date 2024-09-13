#include<iostream>

using namespace std;

int main() {

   int col;
   cin>>col;

   int row;
   cin>>row;

   int **arr = new int *[row];

   for(int i = 0; i<row; i++) {

      arr[i] = new int[col];
   }

   for(int i = 0; i<row; i++) {

      for(int j = 0; j<col; j++) m{

         cin>> arr[row][col];
      }
   }

   cout<<endl;

   for(int i = 0; i<row; i++) {

      for(int j = 0; j<col; j++) {

         cout<<arr[row][col] <<" ";
      }
      cout<<endl;
   }

   for(int i = 0; i<row; i++) {

      delete [] arr[i];
   }

   delete[] arr;
}