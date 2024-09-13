#include<iostream>

using namespace std;

char getMaxOccString(string s)  {

    int arr[26] = {0};

    for(int i = 0; i < s.size(); i++) {

        char ch = s[i];

        int number = 0;
        
        number = ch - 'a';

        arr[number] = arr[number] + 1;

    }

    int maxi = -1;
    int ans = 0;

    for(int i=0; i<26; i++)  {

        if(maxi < arr[i]) {

            ans = i;
            maxi = arr[i];
        
        }

    }

char final = ans + 'a';

return final;

}