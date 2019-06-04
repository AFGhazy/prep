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

int main() {
    
}