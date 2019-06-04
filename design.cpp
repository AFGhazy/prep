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

int main() {
    
}