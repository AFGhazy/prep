#include<bits/stdc++.h>
using namespace std;


int numUniqueEmails(vector<string>& emails) {
    unordered_set<string> s;
    for(auto e: emails) {
//        const regex reg_exp("@");
//        const regex_token_iterator<string::iterator> end_token;
//        regex_token_iterator<string::iterator> it(s.begin(), s.end(), reg_exp, -1);
//        vector<string> v{it, end_token};

        string t = "";
        int i = 0;
        bool plusFound = false;
        while(e[i] != '@') {
            plusFound |= e[i] == '+';
            if(e[i] != '.' && !plusFound) {
                t += string(1, e[i]);
            }
            ++i;
        }
        t += e.substr(i, e.length() - i);
        s.insert(t);
    }
    return s.size();
}

string licenseKeyFormatting(string s, int k) {
    int n = s.length();
    int count = 0;
    string t = "";

    int firstDahses = 0;
    for(int i = 0; i < n; ++i) if(s[i] != '-') break; else firstDahses++;

    for(int i = n - 1; i >= 0; --i) {
        if(s[i] != '-') {
            t += string(1, toupper(s[i]));
            count++;

            if(count == k) {
                if(i != firstDahses) t += "-";
                count = 0;
            }
        }
    }

    reverse(t.begin(), t.end());
    return t;
}

class SolutionLengthOfLongestSubstring {
public:
 int lengthOfLongestSubstring(string s) {
    int n = s.length();
    const int csz = (1 << 8);  

    int mx = 0;
    for(int i = 0; i < n; ++i) {
        vector<bool> v(csz, 0);
        for(int j = i; j < min(i + csz, n); ++j) {
            if(v[s[j]]) break;
            v[s[j]] = true, mx = max(mx, j - i + 1);
        }
    }
    return mx;
}

int optimalLengthOfLongestSubstring(string s) {
        vector<int> dict(256, -1);
        int maxLen = 0, start = -1;
        for (int i = 0; i != s.length(); i++) {
            if (dict[s[i]] > start)
                start = dict[s[i]];
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }
};

class SolutionMultiplyStrings {
public:
    string multiply(string a, string b) {
        int asz = a.length();
        int bsz = b.length();
        string res(asz + bsz, '0');
        for(int i = asz - 1; i >= 0; --i) {
            for(int j = bsz - 1; j >= 0; --j) {
                int cur = res[i + j + 1] - '0';
                int tot = (a[i] - '0') * (b[j] - '0') + cur;
                res[i+j+1] = (tot % 10) + '0';
                res[i+j] = (tot / 10) + res[i+j];
            }
        }
        int i = 0;
        // zero special case
        while(res[i] == '0' && i < res.size() - 1) ++i;
        return res.substr(i);
}
};

class SolutionRotateSquareMatrix {
public:
    void rotate(vector<vector<int>>& m) {
        int n = m.size();
        for(int depth = 0; depth < n / 2; ++depth) {
            for(int i = depth; i < n - depth - 1; ++i) {
                swap(m[n - i - 1][depth], m[depth][i]);
                swap(m[n - i - 1][depth], m[n - depth - 1][n - i - 1]);
                swap(m[n - depth - 1][n - i - 1], m[i][n - depth - 1]);
            }
        }
    }
};

class SolutionMinWindow {
public:
    string minWindow(string s, string t) {
        int n = s.length(), m = t.length();
        if(n == 0 || m == 0) return "";
        
        const int sz = (1 << 8);
        vector<int> needed(sz, 0);
        int rem = t.length();
        for(int i = 0; i < m; ++i) needed[t[i]]++;
        
        int l = 0, len = 0, solL = 0, min = numeric_limits<int>::max();
        while(l < n && len <= n) {
            if(rem) {
                if(len == n) break;
                
                needed[s[len]]--;
                if(needed[s[len]] >= 0) rem--;
                len++;
            } else {
                if(len - l < min) {
                    min = len - l;
                    solL = l;
                }
                needed[s[l]]++;
                if(needed[s[l]] > 0) rem++;
                l++;
            }
        }
        return (min == numeric_limits<int>::max() ? "" : s.substr(solL, min));
    }
};

class SolutionEasyMinWindow {
public:
    string minWindow(string s, string t) {
        int n = s.length(), m = t.length();
        if(n == 0 || m == 0) return "";
        
        const int sz = (1 << 8);
        vector<int> map(sz, 0);
        for(auto c: t) map[c]++;
        
        const int inf = numeric_limits<int>::max();
        int start = 0, end = 0, solStart = 0, min = inf, remaining = m;
        
        while(end < n) {
            map[s[end]]--;
            if(map[s[end]] >= 0) remaining--;
            end++;
            
            while(!remaining) {
                if(min > end - start) {
                    min = end - start;
                    solStart = start;
                }
                
                map[s[start]]++;
                if(map[s[start]] > 0) remaining++;
                start++;
            }
        }
        
        return min == inf ? "" : s.substr(solStart, min);
    }
};

int main() {

    cout << licenseKeyFormatting("--a-a-a-a--", 2) << endl;
}
