#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

int stringToNum2(string s) {

    int sum = 0;
    int exp = s.length() - 1;

    for(int i = 0; i<s.length(); i++) {

        sum = sum + s[i]*pow(10, exp);
        exp--;
    }

    return sum;
}

int stringToNum(const string& s) {
    return stoi(s);  // Use stoi to convert string to integer
}

vector<int> stringToVector(const string& s) {
    int i = 0;
    vector<int> sumVec;

    while (i < s.length()) {
        string v1;

        while (i < s.length() && s[i] != '.') {
            v1.push_back(s[i]);
            i++;
        }

        sumVec.push_back(stringToNum(v1));
        if (i < s.length()) {
            i++;  // Increment i to move to the next character after '.'
        }
    }

    return sumVec;
}

int compareVersion(const string& version1, const string& version2) {
    vector<int> v1 = stringToVector(version1);
    vector<int> v2 = stringToVector(version2);

    int i = 0;

    for (; i < v1.size() && i < v2.size(); i++) {
        if (v1[i] > v2[i]) {
            return 1;
        } else if (v1[i] < v2[i]) {
            return -1;
        }
    }

    while (i < v1.size()) {
        if (v1[i] > 0) {
            return 1;
        }
        i++;
    }

    while (i < v2.size()) {
        if (v2[i] > 0) {
            return -1;
        }
        i++;
    }

    return 0;
}

int main() {
    // Example usage
    string version1 = "1.02";
    string version2 = "1.001";
    int result = compareVersion(version1, version2);
    cout << "Result: " << result << endl;

    return 0;
}
