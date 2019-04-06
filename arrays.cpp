#include<bits/stdc++.h>
using namespace std;


int maxProfit(vector<int> & v) {
    if(v.empty()) return 0;

    int mxProfit = 0;
    int mn = v[0];
    for(int i =0; i < v.size(); ++i) {
        mn = min(mn, v[i]);
        mxProfit = max(v[i] - mn, mxProfit);
    }
    return mxProfit;
}

int removeDuplicates(vector<int>& a) {
    int sz = 0;
        for(int i = 0; i < a.size(); ++i) {
            if(!i || a[i-1] != a[i])  a[sz++] = a[i];
        }
        return sz;
    }

// https://leetcode.com/problems/jump-game/
bool canJump(const vector<int>& nums) {
    int mx = 0;
    bool ret = true;
//     for_each(nums.begin(), nums.end(), [&mx, &ret](const int & a) -> void {
//              if(mx < 0) ret = false;
//              mx = max(mx, a);
//              mx--;
//              });
//
//              return ret;


              for(int i = 0; i <= mx && i <= nums.size() - 1; ++i) {
                mx = max(i + nums[i], mx);
              }

              return mx >= nums.size() - 1;


    }

void print(vector<int> a) {
for_each(a.begin(), a.end(), [](const int & cur) -> void {
        cout << cur << " ";
    });
    cout << endl;
    }

void print(string a) {
cout << a << endl;
    }

    // https://leetcode.com/problems/multiply-strings/
string multiply(string a, string b) {

    bool neg = false;

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    if(a.back() == '-') neg ^= true, a.pop_back();
    if(b.back() == '-') neg ^= true, b.pop_back();

    vector<int> c(a.size() + b.size(), 0);

    for(int i = 0; i < a.size(); ++i) {
        for(int j = 0; j < b.size(); ++j) {
            int cur = (a[i] - '0') * (b[j] - '0') + c[i + j];
            c[i + j] = cur % 10;
            c[i + j + 1] += cur / 10;
        }
    }

    // check the size for input "0" & "0"
    while(c.back() == 0 && c.size() > 1) c.pop_back();

    vector<char> ret;

    for_each(c.begin(), c.end(), [&ret](const int & a) {
             ret.push_back(a + '0');
             });

    if(neg) ret.push_back('-');


    reverse(ret.begin(), ret.end());
     return string(ret.begin(), ret.end());

}

void print(vector<char> a) {
for_each(a.begin(), a.end(), [](const char & cur) -> void {
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
//    array<int, 5> a = {1, 2, 5, 7, 9};
//
//    array<int, 5> c = {1, 2, 5, 7, 9};
////    reverse(a.begin(), a.end());
//
////    rotate(a.begin(), a.begin() + 3, a.end());
//    for_each(a.begin(), a.end(), [](const int & cur) -> void {
//        cout << cur << endl;
//    });
//    cout << (a == c) << endl;
//
//    cout << binary_search(a.begin(), a.end(), 5) << endl;
//    cout << binary_search(a.begin(), a.end(), 4) << endl;
//
//    array<int, 5> b = {9, 7, 5, 3, 1};
//    cout << binary_search(b.begin(), b.end(), 7, greater<int>()) << endl;
//    cout << binary_search(b.begin(), b.end(), 8, greater<int>()) << endl;
//
//    vector<int> t = {9, 9, 9, 9};
//
//    addOne(t);
//    print(t);
//    t = {0};
//
//    addOne(t);
//    print(t);
//
//    t = {1, 9};
//    addOne(t);
//    print(t);


//    print(multiply({'-', '7', '6', '1', '8', '3', '8', '2', '5', '7', '2', '8', '7'}, {'1', '9', '3', '7', '0', '7', '7', '2', '1'}));

    cout << canJump({3, 3, 1, 0, 2, 0, 1}) << endl;
    cout << canJump({3, 2, 0, 0, 2, 0, 1}) << endl;

    vector<int> a = {1, 1, 5, 5, 7, 7, 9, 9, 9, 10};
    cout << removeDuplicates(a) << endl;
    print(a);
}

int main() {
    test();
}
