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

int read4(char *buf);

class SolutionRead4 {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    
    private:
    static const int BUFF_SIZE = 4;
    char buf4[BUFF_SIZE];
    int curBufSize = BUFF_SIZE;
    int curIndex = BUFF_SIZE;
    
    public:
    int read(char *buf, int n) {
        int i = 0;
        while(i < n) {
            if(curIndex >= curBufSize) {
                curBufSize = read4(buf4);
                
                if(curBufSize == 0) break;
                
                curIndex = 0;
            }
            buf[i++] = buf4[curIndex++];
            
        }
        
        return i;
    }
};

int lengthOfLongestSubstringTwoDistinct(string s) {
    int mxLen = 0, curChars = 0, idx = 0, len = 0, n = s.length();
    const int SZ = (1 << 8);
    vector<int> cnt(SZ, 0);

    while(len <= n) {
        if(curChars <= 2) {
            mxLen = max(mxLen, len - idx);

            if(len == n) break;
            if(!cnt[s[len]]) curChars++;
            cnt[s[len]]++;
            len++;
        }
        else {
            cnt[s[idx]]--;
            if(!cnt[s[idx]]) curChars--;
            idx++;
        }
    }
    return mxLen;
}

class SolutionNextClosestTime {
public:
    void enumrate(const string & accum, const string pspDigits, set<string> & s) {
        if(accum.size() == 5) {
            s.insert(accum);
            return;
        }
        
        if(accum.size() == 2) return enumrate(accum + ":", pspDigits, s);
        
        for(auto c: pspDigits) {
            if(c != ':') {
                int len = accum.length();
                if(
                    (len == 0 && c <= '2') ||
                    (len == 1 && c < '4') ||
                    (len == 1 && accum[0] < '2') ||
                    (len == 3 && c < '6') ||
                    len == 4
                )
                enumrate(accum + c, pspDigits, s);
            }
        }
    }
    
    string nextClosestTime(string time) {
        set<string> s;
        enumrate("", time, s);
        
        if(s.upper_bound(time) == s.end()) {
            return *s.begin();
        } else {
            return *s.upper_bound(time);
        }
    }
};

// https://leetcode.com/problems/expressive-words/discuss/122660/C%2B%2BJavaPython-2-Pointers-and-4-pointers
class SolutionExpressiveWords {
public:
    vector<pair<char, int>> compress(const string & s) {
        vector<pair<char, int> > v;
    for(auto c: s) {
            if(v.empty() || v.back().first != c) v.push_back({c, 1});
            else v.back().second++;
        }
        return v;
    }
    
    int expressiveWords(string S, vector<string>& words) {
        vector<pair<char, int> > original = compress(S);
        
        
        int res = 0;
        for(auto w: words) {
            vector<pair<char,int>> cur = compress(w);
            
            bool match = true;
            if(cur.size() == original.size()) {
                for(int i = 0; i < cur.size(); ++i) {
                    
                    if(cur[i].first != original[i].first
                      || cur[i].second > original[i].second ||
                      (cur[i].second == 1 && original[i].second == 2))
                        match = false;
                }
            } else match = false;
            
            if(match) res++;
        }
    return res;
    }
};

class SolutionFindReplaceString {
public:
    string findReplaceString(string in, vector<int>& ind, vector<string>& sources, vector<string>& targets) {
        string out(in.size(), ' ');
        int n = ind.size();
        vector<string> s(n), t(n);
        vector<int> perm(n);
        iota(perm.begin(), perm.end(), 0);
        sort(perm.begin(), perm.end(), [&](const int & a, const int & b) -> bool {
            return ind[a] < ind[b];
        });
        
        for(int i = 0; i < n; ++i) s[i] = sources[perm[i]], t[i] = targets[perm[i]];
        sort(ind.begin(), ind.end());
        
        int cur = n - 1;
        for(int i = in.length() - 1; i >= 0; --i) {
            out[i] = in[i];
            if(cur >= 0 && i == ind[cur]) {
                
                if(out.find(s[cur]) == i) out.replace(i, s[cur].size(), t[cur]);
                --cur;
            }
        }
        return out;
    }
};

class SolutionMyAtoi {
public:
    long long helper(const string & s, const int & idx) {
        if(idx == -1) return 0;
        
        return helper(s, idx - 1) * 10 + (s[idx] - '0');
    }
    
    int myAtoi(string s) {
        int n = s.length();
        int start = 0, end = n-1;
        while(start < n && s[start] == ' ') start++;
        end = start;
        bool pos = false;
        bool point = false;
        bool dig = false;
        
        while(end < n && (isdigit(s[end]) || s[end] == '-' || s[end] == '.' || s[end] == '+')){
            dig |= (isdigit(s[end]));
            if(s[end] == '+' || s[end] == '-'){ if(pos||dig){ break; } pos = true; }   
            if(s[end] == '.'){ if(point){ break; } point = true; }   
         ++end;
        }
        
        if(start >= end) return 0;
        
        string cur = s.substr(start, end - start);
        long long neg = 1;
        if(cur.size() && (cur[0] == '-' || cur[0] == '+')) {
            neg = cur[0] == '+' ? 1 : -1;
            cur = cur.substr(1, cur.length() - 1);
        }
        
        int len = cur.length();
        while(len >= 0 && cur[len] != '.') len--;
        if(len != -1) cur = cur.substr(0, len);
        
         start = 0;
        while(start < cur.length() - 1 && cur[start] == '0') start ++;
        cout << start << endl;
        cur = cur.substr(start, cur.length() - start);
        cout << cur << endl;
        
        for(auto c: cur) if(!isdigit(c)) return 0;
        if(cur.length() > 10 && neg == -1) return numeric_limits<int>::min();
        else if(cur.length() > 10 && neg == 1)return numeric_limits<int>::max();
        
        long long res = neg * helper(cur, cur.length() - 1);
        cout << res << endl;
        cout << res << endl;
        if(res < numeric_limits<int>::min()) return numeric_limits<int>::min();
        else if(res > numeric_limits<int>::max()) return numeric_limits<int>::max();
        return res;
    }

    int myAtoiOptimal(string str) {
    long long int result = 0;
    int indicator = 1;

    int i = str.find_first_not_of(' ');
    if(str[i] == '-' || str[i] == '+')
        indicator = (str[i++] == '-')? -1 : 1;
        
    while('0'<= str[i] && str[i] <= '9') 
    {
        result = result*10 + (str[i++]-'0');
        if(result*indicator >= INT_MAX) return INT_MAX;
        if(result*indicator <= INT_MIN) return INT_MIN;                
    }
        
    return result*indicator;
    }
};

class SolutionIntToRoman {
public:
    string con(int num, string sym) {
        string out = "";
        while(num) {
            if(num & 1) out += sym;
            sym += sym;
            num >>= 1;
        }
        return out;
    }
    
    string vts(const int & num, const string & symbol, const int & val) {
        return con(num / val, symbol);
    }
    
    string intToRoman(int num) {
        vector<pair<string, int> > valToSymbol = {{"M",1000},
        {"CM", 900},
        {"D",500},
        {"CD", 400},
        {"C",100},
        {"XC",90},
        {"L",50},
        {"XL",40},
        {"X",10},
        {"IX",9},
        {"V",5},
        {"IV",4},
        {"I",1}};

    string out = "";
        for(auto vs: valToSymbol) {
            out += vts(num, vs.first, vs.second);
            num %= vs.second;
        }
        return out;




    }
};

class SolutionRomanToInt {
public:
    int romanToInt(string s) {
        vector<pair<string, int> > v = {{"M",1000},
        {"CM", 900},
        {"D",500},
        {"CD", 400},
        {"C",100},
        {"XC",90},
        {"L",50},
        {"XL",40},
        {"X",10},
        {"IX",9},
        {"V",5},
        {"IV",4},
        {"I",1}};
        
        int ret = 0;
        int i = 0;
        
        while(i < v.size()) {
            while(s.find(v[i].first) == 0) {
                int idx = v[i].first.size();
                int len = s.length() - idx;
                s = s.substr(idx, len);
                ret += v[i].second;
            }
            ++i;
        }
        return ret;
    }
};

int main() {
    // cout << lengthOfLongestSubstringTwoDistinct("aa") << endl;
    string s = "abcdefg";
    s.replace(0, 2, "xxxx");
    cout << s << endl;
    cout << (s.find("t") == string::npos) << endl;
    

}
