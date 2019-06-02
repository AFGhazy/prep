#include<bits/stdc++.h>
using namespace std;

class SolutionFindLadders {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, const vector<string>& wordList) {
        unordered_set<string> wl(wordList.begin(), wordList.end());
        unordered_map<string, vector<string> > g;
        for(auto & s: wordList) {
            cout << s << endl;
            for(int i = 0; i < s.length(); ++i) {
                cout << i << endl;
                for(char c = 'a'; c <= 'z'; ++c) {
                    string tmp = s; tmp[i] = c;
                    cout << s << " " << tmp << endl;
                    if(c != s[i] && wl.count(tmp)) g[s].push_back(tmp);
                }
            }
        }
        
        vector<vector<string> > ret;
        return ret;
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

class SolutionFindLadders2 {
public:
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        if(find(wordList.begin(), wordList.end(), beginWord) == wordList.end()) wordList.push_back(beginWord);
        unordered_map<string, vector<int> > g;
        
        for(int k = 0; k < wordList.size(); ++k) {
            for(int i = 0; i < wordList[k].length(); ++i) {
                string tmp = wordList[k];
                tmp[i] = 'X';
                g[tmp].push_back(k);
            }
        }
        
        vector<vector<int> > ret;
        unordered_map<int,int> mp;
        queue<vector<int> > q;
        q.push({find(wordList.begin(), wordList.end(), beginWord) - wordList.begin()});
        
        while(!q.empty()) {
            vector<int> cur = q.front();
            q.pop();
            
            
            if(mp.count(cur.back()) && mp[cur.back()] != cur.size()) continue;
            
            if(wordList[cur.back()] == endWord) {
                ret.push_back(cur);
            }
            
            mp[cur.back()] = cur.size();
            
            int b = cur.back();
            
            for(int i = 0; i < wordList[b].size(); ++i) {
                string tmp = wordList[b];
                tmp[i] = 'X';
                for(auto s: g[tmp]) {
                    if(s != b) {
                        cur.push_back(s);
                        q.push(cur);
                        cur.pop_back();
                    }
                }
            }
        }
        vector<vector<string > > retS;
        for(int i = 0; i < ret.size(); ++i) {
            retS.push_back(vector<string>());
            for(int j = 0; j < ret[i].size(); ++j) {
                retS[i].push_back(wordList[ret[i][j]]);
            }
        }
        
        return retS;
    }
};

class SolutionLadderLength {
public:
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        if(find(wordList.begin(), wordList.end(), beginWord) == wordList.end()) wordList.push_back(beginWord);
        unordered_map<string, vector<int> > g;
        
        for(int k = 0; k < wordList.size(); ++k) {
            for(int i = 0; i < wordList[k].length(); ++i) {
                string tmp = wordList[k];
                tmp[i] = 'X';
                g[tmp].push_back(k);
            }
        }
        
        unordered_map<int,int> mp;
        queue<vector<int> > q;
        q.push({find(wordList.begin(), wordList.end(), beginWord) - wordList.begin()});
        
        while(!q.empty()) {
            vector<int> cur = q.front();
            q.pop();
            
            
            if(mp.count(cur.back()) && mp[cur.back()] != cur.size()) continue;
            
            if(wordList[cur.back()] == endWord) {
                return cur.size();
            }
            
            mp[cur.back()] = cur.size();
            
            int b = cur.back();
            
            for(int i = 0; i < wordList[b].size(); ++i) {
                string tmp = wordList[b];
                tmp[i] = 'X';
                for(auto s: g[tmp]) {
                    if(s != b) {
                        cur.push_back(s);
                        q.push(cur);
                        cur.pop_back();
                    }
                }
            }
        }
        
        return 0;
    }
};

class SolutionNumberOfIslands {
public:
    void fill(vector<vector<char>> & grid, int i, int j) {
    int h = grid.size(), w = grid[0].size();

    if(i < 0 || j < 0 || i == h || j == w || grid[i][j] == '0') return;

    grid[i][j] = '0';

    fill(grid, i + 1, j);
    fill(grid, i - 1, j);
    fill(grid, i, j + 1);
    fill(grid, i, j - 1);
}

int numIslands(vector<vector<char>>& grid) {
    if(grid.size() == 0) return 0;
    
    int h = grid.size(), w = grid[0].size(), count = 0;
    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) {
            if(grid[i][j] - '0') {
                count++, fill(grid, i, j);
            }
        }
    }
    return count;
}
};


int main() {
    vector<vector<string > > sol = SolutionFindLadders().findLadders("hit","cog",{"hot","dot","dog","lot","log","cog"});

}
