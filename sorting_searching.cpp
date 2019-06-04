#include<bits/stdc++.h>
using namespace std;

class SolutionFindMedianSortedArrays {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();
        if(n > m) return findMedianSortedArrays(b, a);
        
        int lo = 0, hi = n;
        int i, j;
        int sum = n + m;
        
        while(lo <= hi) {
            i = (lo + hi) / 2;
            j = (m + n + 1) / 2 - i;
            
            if(i && j < m && a[i - 1] > b[j]) hi = i - 1;
            else if(i < n && j && j <= m && a[i] < b[j - 1]) lo = i + 1;
            else break;
        }
        
        int mxLeft = max(i ? a[i - 1] : numeric_limits<int>::min(), (j && j <= m) ? b[j - 1] : numeric_limits<int>::min());

        int mnRight = min(i < n ? a[i] : numeric_limits<int>::max(), j < m ? b[j] : numeric_limits<int>::max());
        
        if(sum & 1) {
            return mxLeft;
        }
        return (mxLeft + mnRight) / 2.0;
        
        
        
    }
};

class SolutionSearchRotated {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size(), lshft = 0, hshft = n - 1, lo = 0, hi = n - 1;
        if(!n) return -1;
        
        while(lshft < hshft) {
            int i = (lshft + hshft) / 2;
            
            if(nums[i] < nums[0]) hshft = i; else lshft = i + 1;
        }
        if(nums[hshft] > nums[0]) ++hshft;
        
        while(lo < hi) {
            int i = (lo + hi) / 2;
            
            if(nums[(i + hshft) % n] < target) lo = i + 1; else hi = i;
        }
        
        return nums[(hi + hshft) % n] == target ? (hi + hshft) % n : -1;
    }
};

class SolutionMergeIntervals {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int > > v;
        sort(intervals.begin(), intervals.end());
        
        for(auto i: intervals) {
            int st = i[0], en = i[1];
            
            if(v.size() && st <= v.back()[1]) {
                st = v.back()[0];
                en = max(i[1], v.back()[1]);

                v.pop_back();
            }
            
            v.push_back({st, en});
        }
        
        return v;
    }
};

int main() {

}