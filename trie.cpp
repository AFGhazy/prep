#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    static const int SIZE = 1 << 8;
    Node * nxt[SIZE];
    bool isWord;
    Node(){
        memset(nxt, 0, sizeof nxt);
        isWord = false;
    }
};

class Trie {
private: 
    Node * root;
public:
    Trie() : root(new Node()) {

    }

    void insert(const string & word) {
        Node * cur = root;
        for(auto c: word) {
            if(!cur->nxt[c]) cur->nxt[c] = new Node();
            cur = cur->nxt[c];
        }
        cur->isWord = true;
    }
    
    bool search(string word) {
        return find(word, false);
    }
    
    bool startsWith(string prefix) {
        return find(prefix, true);
    }
    
    bool find(const string & word, bool prefix) {
        Node * cur = root;
        for(auto c: word) {
            if(!cur->nxt[c]) return false;
            cur = cur->nxt[c];
        }
        return prefix || (cur && cur->isWord);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main() {
    
}