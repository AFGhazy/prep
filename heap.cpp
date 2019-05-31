#include<bits/stdc++.h>
using namespace std;

void heapSort(vector<int> & v) {
    int n = v.size();
    for(int i = 0; i < n; ++i) {
        int j = i / 2, k = i;
        while(k > 0) {
            if(v[j] < v[k]) swap(v[j], v[k]); 
            k = j;
            j /= 2;
        }
    }

    for(int i = n - 1; i > 0; --i) {
        swap(v[i], v[1]);
        int j = 1;
        while(j < i) {
            int tmpJ = j;
            if(j * 2 < i && v[j * 2] > v[j] && (2 * j + 1 >= i || v[2 * j + 1] < v[j * 2])) swap(v[j], v[j * 2]), tmpJ = j * 2;
            if(j * 2 + 1 < i && v[j * 2 + 1] > v[j]) swap(v[j], v[j * 2 + 1]), tmpJ = j * 2 + 1;
            if(j == tmpJ) break;
            j = tmpJ;
        }
    }
}

vector<int> v;
unordered_set<int> m;

int main() {
    freopen("out.txt", "w", stdout);
    

    for(int i = 0; i < 10000; ++i) {
        int cur;
        do {
            cur = rand();
        } while(m.count(cur));
        v.push_back(cur);
        m.insert(cur);
    }
    int tmp = v[0];
    v[0] = numeric_limits<int>::max();
    v.push_back(tmp);

    heapSort(v);
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, "\n"));
    cout << endl;
    cout << "done!" << endl;
}