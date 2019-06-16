#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int cnt = 0;
        for(int i = 0; i < arr.size(); ++i) {
            cnt += (!arr[i]);
        }
        int n = arr.size();
        for(int i = n - 1; i >= 0; --i) {
            if(i + cnt < n) arr[i + cnt] = arr[i];
            if(!arr[i]) {
                if(i + cnt - 1 < n) arr[i + cnt - 1] = 0;
                --cnt;
            }
        }
    }
};