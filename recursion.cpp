#include<bits/stdc++.h>
using namespace std;

class SolutionLetterCombinations {
public:
    vector<string> m = {"abc", "def", "ghi", "jkl", 
                               "mno", "pqrs", "tuv", "wxyz"};
    
    void gen(const string & dig, const string & accum, const int & idx, vector<string> & ret) {
        if(accum.size() == dig.size()) {
            ret.push_back(accum);
            return;
        }
        for(auto c: m[dig[idx] - '2']) gen(dig, accum + string(1, c), idx + 1, ret);
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        if(digits.empty()) return ret;
        gen(digits, "", 0, ret);
        return ret;
    }
};

class Solution {
public:
    void gen(const int & n, const string & acc, const int & bal, vector<string> & ret) {
        if(bal < 0) return;
        if(acc.size() == n) {
            if(!bal) ret.push_back(acc);
            return;
        }
        
        gen(n, acc + "(", bal + 1, ret);
        gen(n, acc + ")", bal - 1, ret);
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        gen(n * 2, "", 0, ret);
        return ret;
    }
};

class SolutionExistBoard {
public:
    bool exist(vector<vector<char>> & board, const string & word, const int & i, const int & j, 
              const int & k) {
        if(k == word.size()) return true;
        if(i < 0 || i >= board.size()) return false;
        if(j < 0 || j >= board[0].size()) return false;       
    
        
        int ret = (board[i][j] == word[k]);
        char tmp = board[i][j];
        board[i][j] = '*';
        ret = ret && (
            exist(board, word, i + 1, j, k + 1) ||
            exist(board, word, i - 1, j, k + 1) ||
            exist(board, word, i, j + 1, k + 1) ||
            exist(board, word, i, j - 1, k + 1)
        );
        board[i][j] = tmp;
        
        return ret;
    }
    
    bool exist(vector<vector<char>>& board, string word) {

        
        
        bool ret = false;
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[0].size(); ++j) {
                ret |= exist(board, word, i, j, 0);
            }
        }
        return ret;
    }
};

class SolutionFindWords {
public:
    static const int SIZE = (1 << 7); 

    struct Trie {
        string word;
        Trie* next[SIZE];

        Trie() {
            for(int i = 0; i < SIZE; ++i) next[i] = nullptr;
        }

        void insert(string & s, const int & idx = 0) {
            if(idx == s.length()) {
                word = s;
                return;
            }
            if(!next[s[idx]]) next[s[idx]] = new Trie();
            next[s[idx]]->insert(s, idx + 1);
        }
    };

    void findStartingFrom(vector<vector<char>> & board, Trie * cur, const int & i, const int & j, vector<string> & ret) {
        if(i < 0 || i >= board.size()) return;
        if(j < 0 || j >= board[0].size()) return;

        if(!cur) return;
        cur = cur->next[board[i][j]];
        if(!cur) return;

        if(cur->word.size()) ret.push_back(cur->word), cur->word = "";
        
        char tmp = board[i][j];
        
        int dir[] = {1, 0, -1, 0, 1};

        board[i][j] = '*';
        for(int x = 0; x < 4; ++x) {
            findStartingFrom(board, cur, i + dir[x], j + dir[x + 1], ret);
        }
        board[i][j] = tmp;
    }
    
    vector<string> findWords(vector<vector<char>>& board, const vector<string>& words) {
        vector<string> ret;
        Trie * root = new Trie();
        for(string s: words) {
            root->insert(s);
        }

        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[0].size(); ++j) {
                findStartingFrom(board, root, i, j, ret);
            }
        }

        return ret;
    }
};

int main() {
    SolutionFindWords sfw;
    vector<vector<char> >  board = {
{'o','a','a','n'},
  {'e','t','a','e'},
  {'i','h','k','r'},
  {'i','f','l','v'}
    };
    vector<string> v = sfw.findWords(board, {
        "oath","pea","eat","rain"
    });

    for(auto s :v) cout << s << endl;
}