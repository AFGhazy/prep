#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestValsFromLabels(vector<int>& v, vector<int>& l, int num_wanted, int use_limit) {
        unordered_map<int,priority_queue<int, vector<int>, greater<int>>> m;
        for(int i = 0; i < l.size(); ++i) {
            m[l[i]].push(v[i]);
           if(m[l[i]].size() > use_limit) m[l[i]].pop();
        }
        
        priority_queue<int> pq;
        for(auto & p: m) {
            auto cur = p.second;
            while(cur.size()) pq.push(cur.top()), cur.pop();
        }
        int sum = 0;
        while(pq.size() && num_wanted--) {
            sum += pq.top(), pq.pop();
        }
        return sum;
    }
};