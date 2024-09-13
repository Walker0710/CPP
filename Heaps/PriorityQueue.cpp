#include<iostream>
#include<queue>

using namespace std;

int main() {

    //max heap
    priority_queue<int> pq;
    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);

    pq.pop();
    pq.top();
    pq.size();
    bool emp = pq.empty();

    //min Heap
    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(4);
    minHeap.push(2);
    minHeap.push(5);
    minHeap.push(3);

    minHeap.pop();
    minHeap.top();
    minHeap.size();
    bool emp = minHeap.empty();
}