#include<bits/stdc++.h>
using namespace std;


class SolutionSampleStats {
public:
    vector<double> sampleStats(vector<int>& count) {
        int sum = 0, mxCnt = 0;
        double mn = 1e300, mx = 1e-300, avg = 0, mode = 1e-300, median;
        for(int i = 0; i < count.size(); ++i) {
            sum += count[i];
            if(mxCnt < count[i]) mxCnt = count[i], mode = i;
            avg += (i * 1LL) * count[i];
            if(count[i]) {
                mn = min(mn, (double)i);
                mx = max(mx, (double)i);
            }
        }
        avg /= sum;
        
        int med = sum / 2;
        int i = 0;
        while(med - count[i] > 0) med -= count[i], ++i;
        median = i;
        if((sum % 2 == 0) && med >= count[i]) {
            
            while(!count[++i]);
            median = (i + median) / 2;
        }
        
        return {mn, mx, avg, median, mode};
    }
};


class SolutionCarPooling {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<vector<int> > t2 = trips;
        
        sort(t2.begin(), t2.end(), [](const vector<int> & a, const vector<int>& b) -> bool {
           if(a[2] == b[2]) return a[1] < b[1];
            return a[2] < b[2];
        });
        
        sort(trips.begin(), trips.end(), [](const vector<int> & a, const vector<int>& b) -> bool {
           if(a[1] == b[1]) return a[2] < b[2];
            return a[1] < b[1];
        });
        
        
        
        int sum = 0;
        int k = 0;
        for(auto & v: trips) {
            while(k < t2.size() && t2[k][2] <= v[1]) sum -= t2[k][0], ++k;
            sum += v[0];
            if(sum > capacity) return false;
        }
        return true;
    }
};

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation */
 class MountainArray {public:int get(int index); int length(); };

class SolutionFindInMountainArray {
public:
    int bst(int l, int h, int target, MountainArray &m) {
        while(l < h) {
            int mid = (l + h) / 2;
            int v = m.get(mid);
            if(v < target) l = mid + 1;
            else if(v > target) h = mid - 1;
            else h = mid;
        }
        if(m.get(l) == target) return l;
        return -1;
    }
    
    int bst2(int l, int h, int target, MountainArray &m) {
        while(l < h) {
            int mid = (l + h) / 2;
            int v = m.get(mid);
            if(v < target) h = mid - 1;
            else if(v > target) l = mid + 1;
            else h = mid;
        }
        if(m.get(l) == target) return l;
        return -1;
    }
    
    int findInMountainArray(int target, MountainArray &m) {
        int l = 0, h = m.length() - 1;
        while(l < h) {
            int mid1 = l + (h - l) / 3;
            int mid2 = h - (h - l) / 3;
            int v1 = m.get(mid1), v2 = m.get(mid2);
            
            
            if(v1 < v2) {
                l = mid1 + 1;
            } else if(v1 > v2) {
                h = mid2 - 1;
            } else {
                l = mid1 + 1, h = mid2 - 1;
            }
        }
        
        int s1 = bst(0, l, target, m);
        if(s1 == -1) return bst2(l, m.length() - 1, target, m);
        else return s1;
    }
};