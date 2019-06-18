#include<bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
public:
    ll cal(stack<ll> & s, char op) {
        ll n1 = 0;
        ll n2 = 0;
        if(s.size()) n1 = s.top(), s.pop();
        if(s.size()) n2 = s.top(), s.pop();
        ll ret = 0;
        switch(op) {
            case '+': ret = n1 + n2; break;
            case '*': ret = n1 * n2; break;
            case '-': ret = n1 - n2; break;
            case '/': ret = n1 / n2; break;
        }
        return ret;
    }
    
    int calculate(string s) {
        stack<ll> num;
        stack<char> op;
        string prev = "";
        s = "("+s+")";
        bool isLastWasOp = false;
        
        for(int i = s.size() - 1; i >= 0; --i) {
            if(s[i] == ' ') continue; 
            
            if('0' <= s[i] && s[i] <= '9') {
                prev = string(1, s[i]) + prev;
                isLastWasOp = false;
            } else if(prev != "") {
                num.push(stol(prev.c_str()));
                prev = "";
            }
            
            if(s[i] == '(') {
                stack<ll> tmpNum;
                stack<char> tmpOp;
                
                if(isLastWasOp) num.push(0);
                
                while(op.top() != ')') {
                    if(op.top() == '*' || op.top() == '/') {
                        num.push(cal(num, op.top()));
                        op.pop();
                    }
                    else {
                        tmpNum.push(num.top());
                        num.pop();
                        tmpOp.push(op.top());
                        op.pop();
                    }
                }
                
                while(tmpOp.size()) {
                    num.push(tmpNum.top()), tmpNum.pop();
                    op.push(tmpOp.top()), tmpOp.pop();
                }
                
                while(op.top() != ')') {
                    num.push(cal(num, op.top()));
                    op.pop();
                }
                
                op.pop();
                
            }
            
            if(s[i] == ')' || s[i] == '-' || s[i] == '*' || s[i] == '+' || s[i] == '/') {   
                op.push(s[i]);
                isLastWasOp = (s[i] == '-' || s[i] == '+');
            }
        }
        return (int)num.top();
    }
};

int main() {
    
}