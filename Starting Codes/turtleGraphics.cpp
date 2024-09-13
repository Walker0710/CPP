#include<iostream>

using namespace std;

void printing(int grid[][50]) {

    for(int i = 0; i<50; i++) {

        for(int j = 0; j<50; j++) {

            cout<<grid[i][j];
        }

        cout<<endl;
    }
}

void penUp(int grid [][50], int r, int c) {



    int b;
    cout<<"you are currently facing towards right side"<<endl;
    cout<<"which side you want to go"<<endl;
    cin>>b;

    






    
}

void penDown(int grid[][50]) {


}

int main() {

    int grid[50][50] = {0};

    cout<<"press 1 to pen up"<<endl;
    cout<<"press 2 to pen down"<<endl;
    cout<<"press 3 to turn up"<<endl;
    cout<<"press 4 to turn down"<<endl;
    cout<<"press 5 to turn right"<<endl;
    cout<<"press 6 to turn left"<<endl;
    cout<<"press 7 to move forward"<<endl;
    cout<<"press 8 to print the grid"<<endl;
    cout<<"press 9 to exit"<<endl;

    //current position variable
    int r = 0;
    int c = 0;

    int a = -1;

    while(a != 9) {

        cin>>n;

        switch (n)
        {
        case 1:
            penUp(grid[][50], r, c);
            break;
        
        default:
            break;
        }
    }



}