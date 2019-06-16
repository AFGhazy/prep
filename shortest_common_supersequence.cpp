#include<bits/stdc++.h>
using namespace std;


class Solution {
    const int INF = 1000 * 1000 * 10;
public:
    int solve(const string & s, 
              const string & t, 
              vector<vector<int> > & dp,
             const int & i,
             const int & j,
             vector<vector<int> > & bkTrack) {
        
        if(i == s.size() || j == t.size()) {
            if(i < s.size()) return s.size() - i;
            return t.size() - j;
        }
        
        int & ret = dp[i][j];
        
        if(ret != -1) return ret;
        
        ret = INF;
        if(s[i] == t[j]) {
            ret = 1 + solve(s, t, dp, i + 1, j + 1, bkTrack);
            bkTrack[i][j] = 2;
        }
        int s1 = 1 + solve(s, t, dp, i + 1, j, bkTrack);
        int s2 = 1 + solve(s, t, dp, i, j + 1, bkTrack);
    
        if(ret > s1) {
            ret = s1;
            bkTrack[i][j] = 0;
        }
        if(ret > s2) {
            ret = s2;
            bkTrack[i][j] = 1;
        }
        return ret;
    }
    
    string rebuild(vector<vector<int> > & bk, const string & s, const string & t) {
        string ret = "";
        int i = 0, j = 0;
        while(i < s.size() && j < t.size()) {
            if(bk[i][j] == 2) {
                ret += string(1, s[i]);
                j++;
                i++;
            } else if(!bk[i][j]) {
                ret += string(1, s[i]);
                i++;
            } else {
                ret += string(1, t[j]);
                j++;
            }
        }

        ret += s.substr(i, s.size() - i);
        ret += t.substr(j, t.size() - j);
        
        return ret;
    }
    
    string shortestCommonSupersequence(string str1, string str2) {
        vector<vector<int> > dp(str1.size(), vector<int>(str2.size(), -1));
        vector<vector<int> > bk(str1.size(), vector<int>(str2.size(), -1));
        solve(str1, str2, dp, 0, 0, bk);
        return rebuild(bk, str1, str2);
    }
};