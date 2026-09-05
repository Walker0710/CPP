#include <bits/stdc++.h>

using namespace std;

// << ,

struct Booking
{
    int start;
    int end;
    int id;
};

//  Booking {

//     public:
//     int start;
//     int end;
//     int id;

//     Booking(int start, int end, int id) {
//         this->start = start;
//         this->end = end;
//         this->id = id;
//     }
// };

map<int, vector<int>> assign(vector<Booking> &input, int time) {
    sort(input.begin(), input.end(), [](const Booking &a, const Booking&b) {
        return a.start < b.start;
    });

    int count = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    map<int, vector<int>> idToBooking;

    for(int i = 0; i<input.size(); i++) {
        Booking curr = input[i];

        if(!pq.empty() && pq.top().first <= curr.start) {

            pair<int, int> court = pq.top();
            pq.pop();

            int ID = court.second;

            idToBooking[ID].push_back(curr.id);

            pq.push({curr.end + time, ID});
        }

        else {
            count++;
            int courtId = count;

            idToBooking[courtId].push_back(curr.id);
            
            pq.push({curr.end + time, courtId});
        }
    }

    return idToBooking;
}

int main() {

    // vector<Booking> input;

    // input.push_back(Booking(0, 10, 1));
    // input.push_back(Booking(12, 20, 2));
    // input.push_back(Booking(5, 13, 3));

    int time = 4;
    vector<Booking> input = {{0, 10, 1}, {0, 10, 2}, {8, 11, 3}, {11, 12, 4}};

    map<int, vector<int>> ans = assign(input, time);

    for(auto it : ans) {
        int id = it.first;

        vector<int> book = it.second;
        
        cout << id << "-> ";

        for(int i = 0; i<book.size(); i++) {
            cout << book[i] << ", ";
        }

        cout << endl;
    }

    return 0;
}