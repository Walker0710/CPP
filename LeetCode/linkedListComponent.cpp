#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>

using namespace std;

class ListNode {

    public:
    int data;
    ListNode* next;

    //constructor
    ListNode(int d) {

        this -> data = d;
        this -> next = NULL;
    }
};

int numComponents(ListNode* head, vector<int>& nums) 
{
    sort(nums.begin(), nums.end());
    unordered_map<int, ListNode*> maping;
/*
    for(int i = 0; i<nums.size(); i++) 
    {
        ListNode* forMap = head;

        while(forMap -> data != nums[i] && forMap != NULL)  
        {
            forMap = forMap -> next;
        }

        maping[nums[i]] = forMap;
    }*/

    ListNode* forMap = head;

    while(forMap != NULL) {

        maping[forMap -> data] = forMap;
        forMap = forMap -> next;
    }

    int count = 0;

    for(int i = 0; i<nums.size(); i++) 
    {
        for(int j = i+1; j<nums.size(); j++) 
        {
            if(maping[nums[i]] -> next == maping[nums[j]] && maping[nums[i]] != NULL && maping[nums[j]] != NULL) 
            {
                count++;
            }
        }
    }

    return nums.size() - count;
}

//2nd and superior approch
int numComponents(ListNode* head, vector<int>& nums) 
{
    unordered_set<int> mark(nums.begin(), nums.end());

    int ans = 0;
    while(head != NULL) 
    {
        if(mark.count(head -> data)) {

            ans++;
            while(head && mark.count(head -> data)) {

                mark.erase(head -> data);
                head = head -> next;
            }
        }

        else {

            head = head -> next;
        }
    }

    return ans;
}

