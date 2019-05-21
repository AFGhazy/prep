#include<bits/stdc++.h>
using namespace std;

template<class T>
void print(const vector<T> v) {
    copy(v.begin(), v.end(), ostream_iterator<T>(cout, " "));
    cout << endl;
}

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    vector<int> ret;

    int p1 = 0, p2 = 0;
    int sz1 = nums1.size(), sz2 = nums2.size();

    while(p1 < sz1 && p2 < sz2) {
        if(nums1[p1] < nums2[p2]) p1++;
        else if(nums1[p1] > nums2[p2]) p2++;
        else ret.push_back(nums1[p1]), p1++, p2++;
    }

    return ret;
}

void test() {
    vector<int> a = {4,9,5}, b = {9,4,9,8,4};
    print(intersect(a, b));
}

int main() {
    test();
}