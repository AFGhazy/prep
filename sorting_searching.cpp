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

class Solution {
public:
    vector<int> twoSum(vector<int>& a, int target) {
        int n = a.size();
        int i = 0, j = n - 1;
        while(i < j) {
            if(a[i] + a[j] == target) {
                return {i + 1, j + 1};
            } else if(a[i] + a[j] < target) ++i;
            else --j;
        }
        return {};
    }
};

class SolutionFindKthLargest {
public:
    int findKthLargest(vector<int>& nums, int k) {
        set<pair<int,int> > s;
        for(int & i: nums) {
            auto it = s.lower_bound({i, 0});
            int cnt = 0;
            if(it != s.end() && it->first == i) {
                cnt = it->second;
                s.erase(it);
            }
            s.insert({i, cnt + 1});
            
            if(k-- <= 0) {
                cnt = s.begin()->second - 1;
                int val = s.begin()->first;
                s.erase(s.begin());
                if(cnt) s.insert({val, cnt});
            }
        }
        return s.begin()->first;
    }
};


// https://leetcode.com/problems/kth-largest-element-in-an-array/discuss/60294/Solution-explained 
// partial sort, nth element, 
class SolutionFindKthLargestOpt {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq; // smallest on top
        for (int i = 0; i < nums.size(); ++i) {
            pq.push(nums[i]);
            cout << pq.top() << endl;
            if(pq.size() > k) pq.pop();
        }
        return pq.top();
    }
};

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<int> rooms;
        for(auto & i: intervals) {
            int mn, idx = -1;
            for(int j = 0; j < rooms.size(); ++j) {
                if(idx == -1 || mn > rooms[j]) mn = rooms[j], idx = j;
            }
            if(idx == -1 || mn > i[0]) rooms.push_back(i[1]);
            else rooms[idx] = i[1];
        }
        return rooms.size();
    }
};

class SolutionMinMeetingRooms {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<int> rooms;
        priority_queue<int, vector<int>, greater<int> > pq;
        
        for(auto & i: intervals) {
            if(pq.size() && pq.top() <= i[0]) pq.pop();
            pq.push(i[1]);
        }
        return pq.size();
    }
};

int main() {

}