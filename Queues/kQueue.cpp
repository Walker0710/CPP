#include<iostream>

using namespace std;

class kQueue {

    public:
    int n;
    int k;
    int *front;
    int *rear;
    int *arr;
    int freespot;
    int *next;

    public:
    kQueue(int n, int k) {

        this -> n = n;
        this -> k = k;
        front = new int[k];
        rear = new int[k];

        for(int i =0; i<k; i++) {

            front[i] = -1;
            rear[i] = -1;
        }

        next = new int[n];
        for(int i = 0; i<n; i++) {

            next[i] = i+1;
        }

        next[n-1] = -1;
        arr = new int[n];
        freespot = 0;
    }

    void enqueue(int data, int qn) {

        //overflow 
        if(freespot == -1) {

            cout<<"no empty space is empty"<<endl;
            return;
        }

        //find first free index
        int index = freespot;

        //update freespot
        freespot = next[index];

        //check weather first element or not 
        if(front[qn - 1] == -1) {

            front[qn - 1] = index;
        }

        else {

            //link new element to the previous element 
            next[rear[qn -1]] = index;
        }

        //update next 
        next[index] = -1;

        //update rear
        rear[qn -1] = index;

        //push data
        arr[index] = data;
    }

    int dequeue(int qn) {

        //underflow
        if(front[qn - 1] == -1) {

            cout<<"queue underflow"<<endl;
            return -1;
        }

        //find index to top
        int index = front[qn - 1];

        //front ko aage badho
        front[qn - 1] = next[index];

        //freeslot ko manage karo
        next[index] = freespot;
        freespot = index;

        return arr[index];   
    }

    
};

int main() {

    kQueue q(10, 3);


}