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

enum State {
    NOT_VISITED,
    IN_PROGRESS,
    DONE
};

class SolutionCanFinish {
public:
    bool isCyc(const int & u, vector<State> & vis, const vector<vector<int> > & g) {
        if(vis[u] == DONE) return false;
        if(vis[u] == IN_PROGRESS) return true;
        
        vis[u] = IN_PROGRESS;
        for(auto v: g[u]) if(isCyc(v, vis, g)) return true;
        vis[u] = DONE;
        
        return false;
    }
    
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<vector<int> > g(n);
        for(auto & v: p) {
            g[v[0]].push_back(v[1]);
        }
        vector<State> vis(n, NOT_VISITED);
        for(int i = 0; i < n; ++i) {
            if(isCyc(i, vis, g))
                return false;
        }
        return true;
    }
};

class SolutionFloodFill {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor, int oldColor = -1) {
        int n = image.size();
        if(n == 0) return image;
        int m = image[0].size();
        if(sr < 0 || sr >= n || sc < 0 || sc >= m) return image;
        
        if(newColor == image[sr][sc] || (oldColor != -1 && oldColor != image[sr][sc])) return image;
        
        
        
        if(oldColor == -1) oldColor = image[sr][sc];
        
        if(image[sr][sc] == oldColor) image[sr][sc] = newColor;
        
        floodFill(image, sr + 1, sc, newColor, oldColor);
        floodFill(image, sr - 1, sc, newColor, oldColor);
        floodFill(image, sr, sc + 1, newColor, oldColor);
        floodFill(image, sr, sc - 1, newColor, oldColor);
        
        return image;
    }
};

class SolutionFindShortest {
public:
    
    int findShortest(const int & sr, const int & sc, const int &dr, const int & dc, 
                        const vector<vector<int> > & f
                     ) {
        int d = 0;
        queue<pair<int,int> > q;
        int n = f.size();
        int m = f[0].size();
        vector<int> dir = {-1, 0, 1, 0, -1};
        vector<vector<bool > > vis(n, vector<bool>(m, 0));
        
        if(sr == dr && sc == dc) return d;
        
        q.push({sr,sc});
        vis[sr][sc] = true;
    
        while(!q.empty()) {
            
            int sz = q.size();
            ++d;
            
            while(sz--) {
            
                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                

                for(int i = 0; i < 4; ++i) {
                    int nr = r + dir[i];
                    int nc = c + dir[i + 1];
                    if(nr == dr && nc == dc) return d;
                    if(nr < 0 || nc < 0 || nr >= n || nc >= m || vis[nr][nc] || !f[nr][nc]) continue;
                    vis[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
            
        }
        return -1;
    }
    
    
    int cutOffTree(vector<vector<int>>& f) {
        int n = f.size();
        if(n == 0) return 0;
        int m = f[0].size();
        vector<pair<int,int> > p;
        
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(f[i][j] > 1) p.push_back({i, j});
            }
        }
        
        sort(p.begin(), p.end(), [&](const pair<int,int> & a, const pair<int,int> & b) -> bool {
            return f[a.first][a.second] < f[b.first][b.second];
        });
        
        
        int idx = 0;
        int sum = 0;
        pair<int, int> cur = {0,0};
        while(idx < p.size()) {
            auto pp = p[idx];
            int d = 0;
            int sp = findShortest(cur.first, cur.second, pp.first, pp.second, f);
            if(sp == -1) break;
            
            sum += sp;
            
//             cout << sum << " " << cur.first << " " << cur.second << endl;
            
            cur = p[idx++];
        }
        
        return idx == p.size() ? sum : -1;
    }
};


int main() {
    
}
