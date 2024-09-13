#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std; 

//using vactor
class MapSum {
public:
    vector<pair<string, int>> map;

    MapSum() {
        
    }
    
    void insert(string key, int val) {

        bool flag = false;

        for(auto i:map) {
            if(i.first == key) {
                i.second = val;
                flag = true;
            }
        }

        if(!flag) 
        map.push_back({key, val});    
    }
    
    int sum(string prefix) {
        int preSize = prefix.length();
        int ans = 0;

        for(auto i:map) {
            string key = i.first;
            int val = i.second;

            if(key.substr(0, preSize) == prefix) {
                ans += val;
            }
        }
        return ans;
    }
};

//using map
class MapSum {
public:
    unordered_map<string, int> map;

    MapSum() {
        
    }
    
    void insert(string key, int val) {
        map[key] = val;
    }
    
    int sum(string prefix) {
        int ans = 0;
        int preSize = prefix.length();

        for (auto& [key, val] : map) {
            if (key.substr(0, preSize) == prefix) {
                ans += val;
            }
        }
        return ans;
    }
};

//using trie
class TrieNode{
    public:
    TrieNode* children[26];
    int prefsum;
    TrieNode(){
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        prefsum=0;
    }
};
class MapSum {
public:
TrieNode* root = new TrieNode();
void put(string s,int val){
    TrieNode* node = root;
    for(int i=0;i<s.size();i++){
        if(node->children[s[i]-'a']==NULL){
            node->children[s[i]-'a']= new TrieNode();
        }
        node = node->children[s[i]-'a'];
        node->prefsum += val;
    }
}
unordered_map<string,int> mp;
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        int add =0;
        if(mp.count(key)>0){
            int prev = mp[key];
            if(prev==val)return ;
            if(prev>val){
                add = val-prev;
            }else add= val-prev;
            put(key,add);
            mp[key]= val;
        }else{
            put(key,val);
            mp[key]=val;
        }
    }
    
    int sum(string s) {
        int ans =0;
        TrieNode* node = root;
        for(int i=0;i<s.size();i++){
            if(node->children[s[i]-'a']==NULL)return 0;
            else{
                node = node->children[s[i]-'a'];
                ans = node->prefsum;
            }
        }
        return ans;
    }
};
