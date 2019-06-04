#include<bits/stdc++.h>
using namespace std;

class LRUCache {
public:
    const int capacity;
    list<pair<int,int>> l;
    unordered_map<int, list<pair<int,int > >::iterator> m;
    
    int remove(list<pair<int,int > >::iterator it) {
        int key = it->first;
        int val = it->second;
        l.erase(it);
        m.erase(key);
        return val;
    }
    
    void add(const int & key, const int & value) {
        l.push_back({key, value});
        m[key] = --(l.end());
    }
    
    LRUCache(int capacity) : capacity(capacity) {}
    
    int get(int key) {
        if(!m.count(key)) return -1;
        
        int value = remove(m[key]);
        add(key, value);
        return value;
    }
    
    void put(int key, int value) {
        if(m.count(key)) remove(m[key]);
        if(l.size() == capacity) remove(l.begin());
        
        add(key, value);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */




class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> s;
    stack<int> mn;
    
    MinStack() {
        
    }
    
    void push(int x) {
        if(mn.empty() || mn.top() >= x) mn.push(x);
        s.push(x);
    }
    
    void pop() {
        if(mn.size() && mn.top() == s.top()) mn.pop();
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return mn.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> fHalf;
    priority_queue<int, vector<int>, greater<int> > sHalf;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(fHalf.size() && fHalf.top() >= num) fHalf.push(num);
        else sHalf.push(num);
        
        int n = fHalf.size(), m = sHalf.size();
        if(m && n < m) fHalf.push(sHalf.top()), sHalf.pop();
        else if(n && m < n - 1) sHalf.push(fHalf.top()), fHalf.pop();
    }
    
    double findMedian() {
        int n = fHalf.size() + sHalf.size();
        
        double ret = fHalf.top();
        if(n & 1) {
            return ret;
        } else {
            return (ret + sHalf.top()) / 2;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Codec {
public:
    
    string vToS(TreeNode * cur) {
        if(!cur) return "-";
        return to_string(cur->val);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode * > q;
        q.push(root);
        string s = "";
        while(!q.empty()) {
            int sz = q.size();
            string t = "";
            bool nullLvl = true;
            for(int i = 0; i < sz; ++i) {
                if(t.size()) t += ",";
                TreeNode * cur = q.front(); t += vToS(cur);
                q.pop();
                if(cur) {
                    q.push(cur->left), q.push(cur->right);
                    nullLvl &= (!cur->left && !cur->right);
                }
            }
            s = s + (s.empty() ? "" : ",") + t;
        }
        cout << s << endl;
        return s;
    }
    
    TreeNode * sToN(string s) {
        return s == "-" ? NULL : new TreeNode(atoi(s.c_str()));
    }
    
    TreeNode * construct(const vector<string> & v) {
        vector<TreeNode *> pre;
        TreeNode * root = sToN(v[0]);
        pre.push_back(root);
        int idx = 1;
        while(idx < v.size()) {
            vector<TreeNode *> cur;
            for(auto n: pre) {
                n->left = sToN(v[idx++]);
                n->right = sToN(v[idx++]);
                if(n->left) cur.push_back(n->left);
                if(n->right) cur.push_back(n->right);
            }
            swap(pre, cur);
        }
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        regex re(",");
        vector<string> v {
            sregex_token_iterator(data.begin(), data.end(), re, -1),
            sregex_token_iterator()
        };
        
        return construct(v);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

class TicTacToe {
public:
    static const int P_N = 2;
    static const int B_SIZE = 3;
    
    vector<int> rows[P_N];
    vector<int> cols[P_N];
    int dig[P_N];
    int adig[P_N];
    int n;
    
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        for(int i = 0; i < P_N; ++i) 
            rows[i] = vector<int>(n, 0),
            cols[i] = vector<int>(n, 0),
            dig[i] = adig[i] = 0;
        this->n = n;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        --player;
        rows[player][row]++;
        cols[player][col]++;
        dig[player] += (row == col);
        adig[player] += (row + col == n - 1);
        
        if(rows[player][row] == n || cols[player][col] == n || dig[player] == n || adig[player] == n) return player + 1;
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */

constexpr int SIZE = (1 << 7);

struct Trie {
    int freq;
    Trie * next[SIZE];
    map<string, int> res;
    
    Trie() {
        freq = 0;
        memset(next, 0, sizeof next);
    }
    
    int insert(const string & s, const int & idx, const int & df) {
        if(idx == s.length()) { 
            res[s] += df;
            return res[s];
        }
        if(!next[s[idx]]) next[s[idx]] = new Trie();
        
        int freq = next[s[idx]]->insert(s, idx + 1, df);
        res[s] = freq;
        return freq;
    }
    
    vector<string> explore(const string & s, const int & idx = 0) {
        if(idx == s.length()) {
            vector<string> v;
            auto cmp = [](const pair<int, string> & a, const pair<int, string> & b) -> bool {
                if(a.first == b.first) return a.second > b.second;
                return a.first < b.first;
            };
            priority_queue<pair<int, string>, vector<pair<int, string> >, decltype(cmp) > pq(cmp);
            for(auto p: res) {
                pq.push({p.second, p.first});
            }
            int sz = min(3, (int)pq.size());
            for(int i = 0; i < sz; ++i) {
                v.push_back(pq.top().second);
                pq.pop();
            }
            
            return v;
        }
        
        if(!next[s[idx]]) return {};
        
        return next[s[idx]]->explore(s, idx + 1);
    }
};

class AutocompleteSystem {
public:
    string cur;
    Trie * root;
    
    AutocompleteSystem(vector<string>& s, vector<int>& times) {
        root = new Trie();
        cur = "";
        for(int i = 0; i < s.size(); ++i) {
            root->insert(s[i], 0, times[i]);
        }
    }
    
    vector<string> input(char c) {
        if(c == '#') {
            root->insert(cur, 0, 1);
            cur = "";
            return {};
        } else {
            cur += string(1, c);
            return root->explore(cur);
        }
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */

class FreqStack {
public:
    priority_queue<tuple<int,int,int>> s;
    map<int,int> mp;
    int ts;
    
    
    FreqStack() {
        ts = 0;
    }
    
    void push(int x) {
        mp[x]++;
        s.push({mp[x], ts++, x});
    }
    
    int pop() {
        int val = get<2>(s.top());
        s.pop();
        mp[val]--;
        return val;
    }
};

class FreqStackOpt {
public:
    unordered_map<int, int> freq;
    unordered_map<int, stack<int> > s;
    int mxFreq;
    
    
    FreqStackOpt() {
        mxFreq = 0;
    }
    
    void push(int x) {
        mxFreq = max(++freq[x], mxFreq);
        s[freq[x]].push(x);
    }
    
    int pop() {
        int val = s[mxFreq].top();
        s[mxFreq].pop();
        if(s[freq[val]--].empty()) mxFreq--;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */

int main() {
    
}