#include<bits/stdc++.h>
using namespace std;

unordered_map<int, int> fibCache;

int fib(int n) {
    if(n < 2) return n;

    if(!fibCache.count(n)) {
        fibCache[n] = fib(n - 1) + fib(n - 2);
    }
    return fibCache[n];
}

int fibIterative(int n) {
    if(n < 2) return n;
    int f0 = 0;
    int f1 = 1;
    int f = 0;
    for(int i = 2; i <= n; ++i) {
        f = f0 + f1;
        f0 = f1;
        f1 = f;
    }
    return f;
}

int maxSubArray(const vector<int> & v, int start, int end) {
    if(start > end) return v[end];
    if(start == end) return v[start];

    int mx = v[start];
    int mid = (start + end) / 2;

    mx = max(mx, maxSubArray(v, start, mid));
    mx = max(mx, maxSubArray(v, mid + 1, end));

    int lmx = v[mid];
    int rmx = v[mid];
    int cur = 0;
    for(int i = mid; i >= start; --i) {
        cur += v[i];
        lmx = max(cur, lmx);
    }

    cur = 0;
    for(int i = mid; i <= end; ++i) {
        cur += v[i];
        rmx = max(cur, rmx);
    }


    return max(mx, lmx + rmx - v[mid]);
}

int maxSubArray(vector<int> v) {
    return maxSubArray(v, 0, v.size() - 1);
}

int change(int amount, vector<int>& coins) {
        if(!amount) return 1;
        
        vector<vector<int>> dp(2, vector<int>(amount + 1, 0));
    dp[0][0] = 1;
    for(int i = 0; i < coins.size(); ++i) {
        for(int j = 0; j <= amount; ++j) {
            if(!i&&!j) continue;
            
            dp[i % 2][j] = (i > 0 ? dp[(i-1)%2][j] : 0) + (j >= coins[i] ? dp[i%2][j - coins[i]] : 0);
            
        }
    }
        int sol = dp[(coins.size() - 1) % 2][amount];
    return sol;
}

void test() {
    cout << fib(1) << endl;
    cout << fib(8) << endl;
    cout << fib(3) << endl;
    cout << fib(30) << endl;

    cout << fibIterative(1) << endl;
    cout << fibIterative(8) << endl;
    cout << fibIterative(3) << endl;
    cout << fibIterative(30) << endl;
    cout << coinChange({19,28,176,112,30,260,491,128,70,137,253}, 8539);
}

int main() {
    test();
}