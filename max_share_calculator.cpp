#include<bits/stdc++.h>
using namespace std;

void topK(const vector<pair<string, int> > & v) {
    unordered_map<string, map<int, set<string > >::iterator > mp;
    map<int, set<string>> occ;
    
    for(auto & p: v) {
        int val = p.second + 0;
        string cmpny = p.first;
        
        
        if(mp.count(cmpny)) val += mp[cmpny]->first, occ.erase(mp[cmpny]);
        
        occ[val].insert(cmpny);
        mp[cmpny] = occ.find(val);
        
        
        int mn = occ.size();
        auto t = occ.end();
        while(mn--) {
            --t;
            cout << t->first << " "; copy(t->second.begin(), t->second.end(), ostream_iterator<string>(cout, " "));
            cout << endl;
        }
        cout << endl;
    }
}

int main() {
    topK({{"g", 1}, {"g", 2}, {"g", 3}, {"f", 20}, {"a", 100}, {"c", 5}});
}