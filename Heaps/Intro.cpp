#include<iostream>

using namespace std;

class heap{

    public:
    int arr[100];
    int size;

    heap() {

        arr[0] = -1;
        size = 0;
    }

    void insert(int val) {

        size = size + 1;
        int index = size;
        arr[index] = val;

        while(index > 1) {                                            //Node -> i th index. 1. left child -> 2*i th index. 2. right chile -> 2*i + 1 th index. 3. parent -> i/2 th index  for 1 based indexing
                                                                      //for 0 based indexing left = 2*i + 1, right 2*i + 2
            int parent = index/2;                                     //For complete binary tree leaf node lies between (n/2 + 1) -> nth node, here n is total no.s of nodes

            if(arr[parent] < arr[index]) {

                swap(arr[parent], arr[index]);
                index = parent;
            }

            else {

                return ;
            }
        }
    }

    void print() {

        for(int i = 1; i<=size; i++) {

            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    void deleteHeap() {

        if(size == 0) {

            cout<<"nothing to delete"<<endl;
            return ;
        }

        arr[1] = arr[size];
        size--;

        int i = 1;                        
        while(i<size) {

            int leftIndex = 2*i;
            int rightIndex = 2*i + 1;

            if(leftIndex < size && arr[i] < arr[leftIndex]) {

                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            } 

            else if (rightIndex < size && arr[i] < arr[rightIndex]) {

                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }

            else {

                return ;
            }
        }
    }
};

void heapify(int arr[], int n, int i) {

    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;

    if(left < n && arr[largest] < arr[left]) {

        largest = left;
    }

    if(right < n && arr[largest] < arr[right]) {

        largest = right;
    } 

    if(largest != i) {

        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

int main() {

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;

    for(int i = n/2; i>0; i--) {

        heapify(arr, n, i);
    }

    cout<<"printing the array now"<<endl;

    for(int i = 0; i<=n; i++) {

        cout<<arr[i]<<" ";
    }

    cout<<endl;

    return 0;

    
}
    