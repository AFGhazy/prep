#include<bits/stdc++.h>
using namespace std;

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

void fill(vector<vector<char>> & grid, int i, int j) {
    int h = grid.size(), w = grid[0].size();

    if(i < 0 || j < 0 || i == h || j == w || grid[i][j] == '0') return;

    grid[i][j] = '0';

    fill(grid, i + 1, j);
    fill(grid, i - 1, j);
    fill(grid, i, j + 1);
    fill(grid, i, j - 1);
}

int numIslands(vector<vector<char>>& grid) {
    if(grid.size() == 0) return 0;
    
    int h = grid.size(), w = grid[0].size(), count = 0;
    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) {
            if(grid[i][j] - '0') {
                count++, fill(grid, i, j);
            }
        }
    }
    return count;
}

int maxProduct(vector<int>& nums) {
    int cur = 1, curNeg = 1;
    int mx = numeric_limits<int>::min();
    for(int i = 0; i < nums.size(); ++i) {
        
        if(nums[i] == 0) {
            cur = 1, curNeg = 1;
            mx = max(mx, 0);
        } else {
            cur *= nums[i];
            mx = max(mx, cur);
            mx = max(mx, cur / curNeg);
            if(curNeg > 0) {
                curNeg *= nums[i];
            }
        }
    }
    return mx;
}


vector<int> enumrateAllPrimes(const int & n) {
    bitset<1000005> isPrime;
    isPrime.set();
    isPrime[0] = isPrime[1] = 0;
    vector<int> primes;
    for(int i = 2; i <= n / i; ++i) if(isPrime[i]) {
        int j = i + i;
        while(j <= n) isPrime[j] = false, j += i;
    }
    for(int i = 1; i <= n; ++i) if(isPrime[i]) primes.push_back(i);
    return primes;
}

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

int maxProfit2(vector<int> & v) {
    if(v.empty()) return 0;

    vector<int> mxProfit(v.size(), 0);
    int mn = v[0];
    for(int i =0; i < v.size(); ++i) {
        mn = min(mn, v[i]);
        if(i > 0) mxProfit[i] = mxProfit[i - 1];
        mxProfit[i] = max(v[i] - mn, mxProfit[i]);
    }

    int mxProfitB = 0;
    int mx = v.back();
    for(int i = v.size() - 1; i >= 0; --i) {
        mx = max(mx, v[i]);
        mxProfitB = max(mx - v[i] + (i ? mxProfit[i - 1] : 0), mxProfitB);
    }
    return mxProfitB;
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

// O(n^2) approach by taking the left most element as the starting point of traversal
void permute(vector<int> & v, vector<int> & p) {
    for(int i = 0; i < v.size(); ++i) {
        int nxt = i;
        while(nxt >= 0) {
            swap(v[i], v[nxt]);
            int tmp = p[nxt];
            p[nxt] -= v.size();
            nxt = tmp;
        }
    }
}

int maxSubArray(const vector<int>& v) {
    int mx = numeric_limits<int>::min();
    int sum = 0;
    for(int i = 0; i < v.size(); ++i) {
        sum += v[i];
        mx = max(sum, mx);
        if(sum < 0) sum = 0;
    }
    return mx;
}

bool isSequenceArray(const vector<int> & v, const int & m, const int & n) {
    for(int i = 0; i < v.size(); ++i) {
        if(v[i] < m || v[i] > n) return false;
        if(i && v[i] < v[i - 1]) return false;
    }
    return true;
}

int totalFruit(const vector<int>& tree) {
    unordered_map<int, int> trees_so_far;
    int start_index = 0, end_index = 0;
    int mx = 0;
    while(end_index < tree.size()) {
            cout << start_index << " " << end_index << " " << trees_so_far.size() << " " << mx << endl;
        if(trees_so_far.size() > 2) {
            trees_so_far[tree[start_index]]--;
            if(trees_so_far[tree[start_index]] == 0) trees_so_far.erase(tree[start_index]);
            start_index++;
        } else {
            trees_so_far[tree[end_index]]++;
            if(trees_so_far.size() <= 2) mx = max(mx, end_index - start_index + 1);
            end_index++;
        }

    }
    return mx;
}

class SolutionOddEvenJumps {
public:
    int oddEvenJumps(vector<int>& A) {
        const int pinf = numeric_limits<int>::max();
        const int ninf = numeric_limits<int>::min();
        map<int,int> m = {{pinf, pinf}, {ninf, ninf}};
        int n = A.size();
        vector<pair<bool, bool> > reached(A.size(), {false, false});
        reached[n-1] = {true, true};
        int count = 1;
        m[A[n-1]] = n - 1;
        
        for(int i = n - 2; i >= 0; --i) {
            auto oddJ = m.lower_bound(A[i]);
            auto evenJ = --m.upper_bound(A[i]);
            
            if(oddJ -> second != pinf) {
                reached[i].first = reached[oddJ -> second].second;
                if(reached[i].first) count++;
            }
            if(evenJ -> second != ninf) {
                reached[i].second = reached[evenJ -> second].first;
            }
            
            m[A[i]] = i;
        }
        
        return count;
    }
};

//https://leetcode.com/problems/container-with-most-water/discuss/6099/Yet-another-way-to-see-what-happens-in-the-O(n)-algorithm
class SolutionMaxArea {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1, ret = 0;
        while(l<r)
        {
            ret = max(ret, min(height[l], height[r]) * (r - l));
            if(height[l] < height[r])
                l++;
            else
                r--;
        }
        return ret;
    }
};

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

//    cout << canJump({3, 3, 1, 0, 2, 0, 1}) << endl;
//    cout << canJump({3, 2, 0, 0, 2, 0, 1}) << endl;
//
//    vector<int> a = {1, 1, 5, 5, 7, 7, 9, 9, 9, 10};
//    cout << removeDuplicates(a) << endl;
//    print(a);
//vector<int> v = enumrateAllPrimes(2017);
//    print(v);
//    int acc = accumulate(v.begin(), v.end(), 0, [](int sum, int a) -> int {
//               return sum + (a & 1 ? a : 0);
//               });
//    print(enumrateAllPrimes(acc));
//    cout << acc << endl;

    // vector<int> a = {1, 2, 3, 4};
    // vector<int> v = {1, 2, 3, 0};

    // permute(a, v);
    // print(a);
    // cout << maxSubArray({-2,1,-3,4,-1,2,1,-5,4}) << endl;
    // cout << isSequenceArray({1,2,3,4,5}, 1, 5) << endl;
    // cout << isSequenceArray({-5, -5, -5, -4, -4, -3, -3, -2, -2}, -5, -2) << endl;
    // cout << isSequenceArray({0, 1, 2, 3, 4, 5}, 1, 5) << endl;

    // cout << totalFruit({3,3,3,1,2,1,1,2,3,3,4}) << endl;

   
}

struct tupleHash {
    template<class T>
    size_t operator() (const vector<T> & t) const {
        hash<T> ht;
        auto h1 = ht(t[0]);
        auto h2 = ht(t[1]);
        auto h3 = ht(t[2]);

        return h1 ^ h2 ^ h3;
    }
};

vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    unordered_set<vector<int>, tupleHash > s;
    for(int i = 0; i < n; ++i) {
        int target = - nums[i];

        if(i && nums[i] == nums[i-1]) continue;

        int j = i + 1, k = n - 1;
        while(j < k) {
            if(nums[j] + nums[k] > target) k--;
            else if(nums[j] + nums[k] < target) j++;
            else {
                vector<int> v = {nums[i], nums[j], nums[k]};
                s.insert(v);
                ++j;
            }
        }
    }
    vector<vector<int>> v(s.begin(), s.end());
    return v;
}

vector<vector<int> > threeSumOptimal(vector<int> &num) {
    
    vector<vector<int> > res;

    std::sort(num.begin(), num.end());

    for (int i = 0; i < num.size(); i++) {
        
        int target = -num[i];
        int front = i + 1;
        int back = num.size() - 1;

        while (front < back) {

            int sum = num[front] + num[back];
            
            // Finding answer which start from number num[i]
            if (sum < target)
                front++;

            else if (sum > target)
                back--;

            else {
                vector<int> triplet(3, 0);
                triplet[0] = num[i];
                triplet[1] = num[front];
                triplet[2] = num[back];
                res.push_back(triplet);
                
                // Processing duplicates of Number 2
                // Rolling the front pointer to the next different number forwards
                while (front < back && num[front] == triplet[1]) front++;

                // Processing duplicates of Number 3
                // Rolling the back pointer to the next different number backwards
                while (front < back && num[back] == triplet[2]) rear--;
            }
            
        }

        // Processing duplicates of Number 1
        while (i + 1 < num.size() && num[i + 1] == num[i]) 
            i++;

    }
    
    return res;
    
}

// https://leetcode.com/problems/next-permutation/discuss/13994/Readable-code-without-confusing-ij-and-with-explanation
class SolutionNextPermutation {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;
        for(; i >= 0; --i) {
            if(nums[i + 1] > nums[i]) break;
        }
        if(i == -1) {
            reverse(nums.begin(), nums.end());
        } else {
            
            int idx = n - 1;
            // we will ignore the equal numbers because we don't want to end up with previous permutation
            
            while(nums[idx] <= nums[i]) idx--;
            swap(nums[i], nums[idx]);
            // copy(nums.begin(), nums.end(), ostream_iterator<int>(cout, " "));
            sort(nums.begin() + i + 1, nums.end());
        }
    }
};

class SolutionPlusOne {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int c = 1;
        for(int i = n - 1; i >= 0; --i) {
            int cur = digits[i] + c;
            digits[i] = (cur % 10);
            c = cur / 10;
        }
        if(c) digits.insert(digits.begin(), c);
        return digits;
    }
}; 


class SolutionFindMissingRanges {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        set<int> t(nums.begin(), nums.end());
        nums = vector<int>(t.begin(), t.end());
        
        set<pair<int,int> > s;
        s.insert({lower, upper});
        for(auto num: nums) {

            set<pair<int,int>>::iterator it = --(s.upper_bound({num, upper}));
            pair<int, int> cur = *it;
            s.erase(it);
            
            if(cur.first == cur.second);
            else if(cur.first == num) {
                cur.first++;
                s.insert(cur);
            }
            else if(cur.second == num) {
                cur.second--;
                s.insert(cur);
            }
            else {
                s.insert({cur.first, num - 1});
                s.insert({num + 1, cur.second});
            }
        }
        
        vector<string> ret;
        for(auto r: s) {
            if(r.first == r.second) {
                ret.push_back(to_string(r.first));
            } else {
                ret.push_back(to_string(r.first) + "->" + to_string(r.second));
            }
        }
        return ret;
    }
};

int main() {
    test();
    vector<int> v = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    threeSum(v);
}
