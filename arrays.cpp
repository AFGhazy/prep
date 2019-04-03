#include<bits/stdc++.h>
using namespace std;

void print(vector<int> a) {
for_each(a.begin(), a.end(), [](const int & cur) -> void {
        cout << cur << " ";
    });
    cout << endl;
    }

//https://leetcode.com/problems/sort-colors
void sortColors(vector<int>& a) {
    int n = a.size();
    int pre = 0;
    int suf = n - 1;
    for(int i = 0; i < n && i <= suf; ++i) {
        if(a[i] == 0) {
            swap(a[i], a[pre++]);
        } else if(a[i] == 2) {
            swap(a[i--], a[suf--]);
        }
    }
}

void addOne(vector<int> & v) {
    reverse(v.begin(), v.end());
    int carry = 1;
    for(int i = 0; i < v.size(); ++i) {
        int sum = v[i] + carry;
        carry = sum / 10;
        v[i] = sum % 10;
    }
    if(carry != 0) v.push_back(carry);
    reverse(v.begin(), v.end());
}

void test() {
    array<int, 5> a = {1, 2, 5, 7, 9};

    array<int, 5> c = {1, 2, 5, 7, 9};
//    reverse(a.begin(), a.end());

//    rotate(a.begin(), a.begin() + 3, a.end());
    for_each(a.begin(), a.end(), [](const int & cur) -> void {
        cout << cur << endl;
    });
    cout << (a == c) << endl;

    cout << binary_search(a.begin(), a.end(), 5) << endl;
    cout << binary_search(a.begin(), a.end(), 4) << endl;

    array<int, 5> b = {9, 7, 5, 3, 1};
    cout << binary_search(b.begin(), b.end(), 7, greater<int>()) << endl;
    cout << binary_search(b.begin(), b.end(), 8, greater<int>()) << endl;

    vector<int> t = {9, 9, 9, 9};

    addOne(t);
    print(t);
    t = {0};

    addOne(t);
    print(t);

    t = {1, 9};
    addOne(t);
    print(t);

}

int main() {
    test();
}
