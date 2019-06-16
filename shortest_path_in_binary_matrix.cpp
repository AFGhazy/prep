#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& g) {
        int n = g.size();
        int dd[] = {1, 0, -1, 0, 1, -1, -1, 1, 1};
        queue<pair<int,int> > q;
        if(!g[0][0])
            q.push({0,0});
        int d = 0;
        while(!q.empty()) {
            int sz = q.size();
            d++;
            for(int i = 0; i < sz; ++i) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                
                if(x == n - 1 && y == n - 1) return d;
                
                for(int i = 0; i < 8; ++i) {
                    int dx = x + dd[i];
                    int dy = y + dd[i + 1];
                    if(dx < n && dy < n && dx >= 0 && dy >= 0) {
                        if(!g[dx][dy])
                            g[dx][dy] = 1, q.push({dx, dy});
                    }
                }
            }
        }
        return -1;
    }
};