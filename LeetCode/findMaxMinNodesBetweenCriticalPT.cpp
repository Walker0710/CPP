#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class ListNode {

    public:
    int val;
    ListNode* next;

    //constructor
    ListNode(int d) {

        this -> val = d;
        this -> next = NULL;
    }
};

int small(int x, int y, int z) {

  int smallest = 99999;

  if (x < smallest)
    smallest=x;
  if (y < smallest)
    smallest=y;
  if(z < smallest)
    smallest=z;

  return smallest;
}

int great(int x, int y, int z) {

  int smallest = 99999;

  if (x > smallest)
    smallest=x;
  if (y > smallest)
    smallest=y;
  if(z > smallest)
    smallest=z;

  return smallest;
}

vector<int> nodesBetweenCriticalPoints(ListNode* head) {

    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* forw = NULL;
    
    vector<int> max;
    vector<int> min;
    vector<int> ans;

    if(head == NULL || head -> next == NULL) {

        return {-1,-1};
    }

    int counter = 1;

    while(curr != NULL) {

        prev = curr;
        curr = curr -> next;
        if(curr != NULL)
        forw = curr -> next;
        counter++;

        if(prev && curr && forw && prev -> val > curr -> val && forw -> val > curr -> val) {

            min.push_back(counter);
        }

        if(prev && curr && forw && prev -> val < curr -> val && forw -> val < curr -> val) {

            max.push_back(counter);
        }
    }

    if(max.size() == 0 || min.size() == 0) {

        return {-1, -1};
    }

    int ansMax;

    if(max[0] > min[0]) {

        if(max[max.size() - 1] > min[min.size() - 1]) {

            ansMax = max[max.size() - 1] - min[0];
        }

        else {

            ansMax = min[min.size() - 1] - min[0];
        }
    }

    else {

        if(max[max.size() - 1] > min[min.size() - 1]) {

            ansMax = max[max.size() - 1] - max[0];
        }

        else {

            ansMax = min[min.size() - 1] - max[0];
        }        
    }

    int ansMin;

    if(max[0] > min[0]) {

        if(max[1] > min[1]) {

            ansMin = min[1] - max[0];
        }

        else {

            ansMin = max[1] - max[0];
        }
    }

    else {

        if(max[1] > min[1]) {

            ansMin = min[1] - min[0];
        }

        else {

            ansMin = max[1] - min[0];
        }        
    }

    

    /*

    for(int i = 0; i<max.size(); i++) {

        for(int j = 0; j<min.size(); j++) {

            int yo = max[i] - min[j];
            distance.push_back(abs(yo));
        }
    }

    int mini2 = INT32_MAX;
    int maxi2 = INT32_MIN;

    for(int i = 0; i<min.size(); i++) {

        for(int j = i+1; j<min.size(); j++) {

            int yo = min[j] - min[i];
            if(yo > maxi2) {

                maxi2 = yo;
            }

            if(yo < mini2) {

                mini2 = yo;
            }
        }
    }

    int mini3 = INT32_MAX;
    int maxi3 = INT32_MIN;

    for(int i = 0; i<max.size(); i++) {

        for(int j = i+1; j<max.size(); j++) {

            int yo = max[j] - max[i];
            if(yo > maxi3) {

                maxi3 = yo;
            }

            if(yo < mini3) {

                mini3 = yo;
            }
        }
    }

    int mini1 = *min_element(distance.begin(), distance.end());
    int maxi1 = *max_element(distance.begin(), distance.end());

    int ansMin = small(mini1, mini2, mini3);
    int ansMax = great(maxi1, maxi2, maxi3);*/

    ans.push_back(ansMin);
    ans.push_back(ansMax);

    return ans;
}

    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        vector<int> ans={-1,-1};

        ListNode* prev=head;

        if(!prev)
        return ans;

        ListNode* curr=prev->next;

        if(!curr)
        return ans;

        ListNode* next=curr->next;

        if(!next) 
        return ans;

        int first=-1;
        int last=-1;
        int mind = INT32_MAX;
        int i=1;

        while(next){

            bool iscp=((curr->val>prev->val && curr->val>next->val)||(curr->val<prev->val&&curr->val<next->val))?true:false;

            if(iscp&&first==-1){
                first=i;
                last=i;
            }

            else if(iscp){

                mind=min(mind,i-last);
                last=i;
            }

            i++;
            prev=curr;
            curr=next;
            next=next->next;
        }

        if(first==last)
        return ans;

        else
        {
            ans[0]=mind;
            ans[1]=last-first;
        }

        return ans;
    }