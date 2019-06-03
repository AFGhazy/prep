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

int main() {

}