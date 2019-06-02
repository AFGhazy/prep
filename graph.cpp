#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int cmp(const string & s, const string & t) {
        int cnt = 0;
        for(int i = 0; i < s.length(); ++i) cnt += (s[i] != t[i]);
        return cnt;
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        if(find(wordList.begin(), wordList.end(), beginWord) == wordList.end()) wordList.push_back(beginWord);
        unordered_map<string, vector<string> > g;
        for(int i = 0; i < wordList.size(); ++i) {
            for(int j = 0; j < wordList.size(); ++j) {
                if(cmp(wordList[i], wordList[j]) == 1) g[wordList[i]].push_back(wordList[j]);
            }
        }
        
        vector<vector<string> > ret;
        unordered_map<string,int> mp;
        queue<vector<string> > q;
        q.push({beginWord});
        while(!q.empty()) {
            vector<string> cur = q.front();
            q.pop();
            
            
            if(mp.count(cur.back()) && mp[cur.back()] != cur.size()) continue;
            
            if(cur.back() == endWord) {
                ret.push_back(cur);
            }
            
            mp[cur.back()] = cur.size();
            
            auto & b = g[cur.back()];
            
            for(auto & str: b) {
                cur.push_back(str);
                q.push(cur);
                cur.pop_back();
            }
        }
        return ret;
    }
};

int main() {
    
}