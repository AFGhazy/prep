#include<bits/stdc++.h>
using namespace std;

int find(int v, vector<int> & p) {
    if(p[v] == v) return v;
    return p[v] = find(p[v], p);
}

int uni(const int & a, const int & b, vector<int> & p) {
    if(rand() & 1) return p[find(a,p)] = find(b, p);
    return p[find(b,p)] = find(a, p);
}

int main() {
    srand(time(NULL));
    int n = 10;
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);

    cout << uni(1, 2, p) << endl;
    cout << find(1, p) << endl;
    cout << uni(2, 3, p) << endl;
    cout << uni(1, 4, p) << endl;
    cout << uni(1, 0, p) << endl;
    cout << find(0, p) << endl;

    cout << uni(5, 9, p) << endl;
    cout << find(9, p) << endl;
    cout << uni(5, 6, p) << endl;
    cout << uni(7, 6, p) << endl;
    cout << uni(7, 8, p) << endl;
    cout << find(8, p) << endl;

    cout << uni(3, 7, p) << endl;
    cout << find(8, p) << endl;


}