#include<iostream>
#include<math.h>

using namespace std;

int myAtoi(string s) {

    string digi;
    int count = 0;
    int sum = 0;
    int j = 0;

    while(j<s.length()) {

        if(s[j] == ' ') {

            j++;
        }

        if(s[j] >= 'a' && s[j] <= 'z') {

            return sum;
        }

        else {

            break;
        }
    }

    for(int i = 0; i<s.length(); i++) {

        if(s[i] == '0' || s[i] == '1' ||s[i] == '2' ||s[i] == '3' ||s[i] == '4' ||s[i] == '5' ||s[i] == '6' ||s[i] == '7' ||s[i] == '8' ||s[i] == '9' || s[i] == '-') {

            digi.push_back(s[i]);

            if(s[i] == '-') {

                count++;
            }
        }
    }

    if(count == 0) {

        int power = 0;
        
        for(int i = digi.length() - 1; i>=0 ; i--) {

            if((digi[i] - '0')*pow(10, power) >= INT32_MAX) {

                return INT32_MAX;
            }

            int yo = (digi[i] - '0')*pow(10, power);

            sum = sum + yo;

            power++;
        }

        return sum;
    }

    else {

        int power = 0;
        
        for(int i = digi.length() - 1; i>= 1; i--) {

            if((digi[i] - '0')*pow(10, power) >= INT32_MAX) {

                return INT32_MIN;
            }

            int yo = (digi[i] - '0')*pow(10, power);

            sum = sum + yo;

            power++;
        }       

        return -(sum);
    }
}