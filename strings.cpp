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

int main() {

    cout << licenseKeyFormatting("--a-a-a-a--", 2) << endl;
}
