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

int main() {

}