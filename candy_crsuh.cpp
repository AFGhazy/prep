#include<bits/stdc++.h>
using namespace std;

void extract(stack<int> & s) {
    vector<int> ext;
    while(s.size() && ext.size() < 3) ext.push_back(s.top()), s.pop();
    if(ext.size() != 3 || ext[0] != ext[2] || ext[1] != ext[0]) {
        while(ext.size()) s.push(ext.back()), ext.pop_back();
        return;
    }
    int cur = ext[0];
    while(s.size() && cur == s.top()) s.pop();
}

vector<int> getReducedGame(const vector<int> & v) {
    
    stack<int> s;
    int n = v.size();

    for(int i = 0; i <= n; ++i) {
        if(s.size() && (i == n ||  s.top() != v[i])) {
            extract(s);
        }

        if(i < n) s.push(v[i]);
    }

    vector<int> ret(s.size());
    while(s.size()) ret[s.size() - 1] = s.top(), s.pop();
    return ret;
}

vector<int> candyCrush(const vector<int> & nums) {
    int endPtr = nums.length - 1;
    int curPtr = endPtr;

    while (curPtr >=0) {
        int nextPtr = curPtr-1;
        while (nextPtr >= 0 && nums[nextPtr] == nums[curPtr]) nextPtr--;

        int diff = curPtr - nextPtr;
        if (diff >= 3) {
            
            // if curPtr is not the last one,
            // shift diff position forward for all elements after the curPtr up to the endPtr
            if (curPtr < endPtr) {
                for (int shiftFwdPtr = curPtr + 1; shiftFwdPtr <= endPtr; shiftFwdPtr++) {
                    nums[shiftFwdPtr - diff] = nums[shiftFwdPtr];
                }
            }

            endPtr -= diff;
            curPtr = nextPtr+1;
            while (curPtr < endPtr && nums[curPtr] == nums[curPtr+1]) curPtr++;
        }
        else {
            curPtr = nextPtr;
        }
    }

    int length = endPtr + 1;
    int[] ans = new int[length];
    System.arraycopy(nums, 0, ans, 0, length);

    return ans;

}

int main() {
    vector<int> sol = getReducedGame({1, 3, 3, 3, 2, 2, 2, 3, 1});
    copy(sol.begin(), sol.end(), ostream_iterator<int>(cout, " "));
}