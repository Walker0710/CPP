#include <iostream> 
#include <vector>
#include <time.h> 
#include <algorithm>

using namespace std;

int main() 
{ 
    clock_t t; 
    t = clock(); 
    vector<int> arr(1000);
    for(int i = 0; i<1000; i++) {
        arr[i] = i+1;
    }
    sort(arr.begin(), arr.end());
    t = clock() - t; 
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
 
    printf("Took %f seconds to execute \n", time_taken); 
    return 0; 
}