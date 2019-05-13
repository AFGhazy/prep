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

int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(2, vector<int>(amount + 1, 0));

    for(int i = 0; i < coins.size(); ++i) {
        for(int j = 0; j <= amount; ++j) {
            if(!i&&!j) continue; 
            
            dp[i % 2][j] = min((i > 0 ? dp[(i-1)%2][j] : numeric_limits<int>::max()), (j >= coins[i] && dp[i%2][j - coins[i]] != numeric_limits<int>::max() ? 1 + dp[i%2][j - coins[i]] : numeric_limits<int>::max()));

        }
    }
        int sol = dp[(coins.size() - 1) % 2][amount];
    return sol == numeric_limits<int>::max() ? -1 : sol;
    }

int uniquePaths_(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(2, vector<int>(n + 1, 0));
        dp[0][1] = 1;
        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                dp[i % 2][j] = dp[(i - 1) % 2][j] + dp[i % 2][j - 1];
            }
        }
        return dp[m % 2][n];
    }

int minDistance(string word1, string word2) {
int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(2, vector<int>(m + 1, 0));

        

        for(int i = 1; i <= m; ++i) dp[0][i] = i;


        for(int i = 1; i <= n; ++i) {
            fill(dp[i%2].begin(), dp[i % 2].end(), 0);
            dp[i % 2][0] = i;
            for(int j = 1; j <= m; ++j) {

                int & ret = dp[i % 2][j];

                if(word1[i - 1] == word2[j - 1]){ ret = dp[(i - 1) % 2][j - 1];
                } else {
                    ret = 
                        1 + min(dp[(i - 1) % 2][j - 1], min(dp[(i - 1) % 2][j], dp[i % 2][j - 1]));
                }

            }
        }

        return dp[n % 2][m];
}



class WordBreakSolution {
public:
    
    static const int p1 = 999907;
static const int p2 = 999917;
static const int cp = 31;
    
    
    
    static bool solveWordBreak(vector<int> & dp, const string & s, int i, const unordered_set<int> & dict1, 
const unordered_set<int> & dict2,
                              vector<vector<bool> > & sol) {
    if(i == s.size()) return true;
        
    int h1 = 0;
    int h2 = 0;

    int & found = dp[i];
    if(found != -1) return found;
        
    found = 0;

    for(int j = i; j < s.size(); ++j) {
        h1 = ((h1 + s[j] - 'a' + 1) * cp) % p1;
        h2 = ((h2 + s[j] - 'a' + 1) * cp) % p2;

        
        if(dict1.count(h1) && dict2.count(h2)) {
            bool cur = solveWordBreak(dp, s, j + 1, dict1, dict2, sol);
            found |= cur;
            sol[i][j] = cur;
            // cout << "<<" << i << " " << j << " " << cur << endl;
        }
    }
    return found;
}
    
static void rebuildSol(vector<vector<bool>> & sol, 
               vector<string> & ss,
               int index,
               const string & t, 
                      const string & accum) {
    if(t.size() == index) ss.push_back(accum);
    
    for(int i = index; i < t.size(); ++i) {
        if(sol[index][i]) {
            // cout << index << " " << i << endl;
            rebuildSol(sol, ss, i + 1, t, accum + (index ? " " : "") + t.substr(index, i - index + 1));
        }
    }
}

vector<string> wordBreak(string s, const vector<string> & dict) {
    
    unordered_set<int> dict1;
    unordered_set<int> dict2;
    vector<int> dp(s.size(), -1);
    vector<vector<bool>> sol(s.size(), vector<bool>(s.size(), false));

    for(auto s: dict) {
        int h1 = 0;
        int h2 = 0;
        for(int i = 0; i < s.size(); ++i) {
            h1 = ((h1 + s[i] - 'a' + 1) * cp) % p1;
            h2 = ((h2 + s[i] - 'a' + 1) * cp) % p2;
        }

        dict1.insert(h1);
        dict2.insert(h2);
    }
    
    bool ret = solveWordBreak(dp, s, 0, dict1, dict2, sol);


    vector<string> t;
    rebuildSol(sol, t, 0, s, "");
    return t;
}
};


int comb(int n, int r) {
    vector<vector<int> > dp(2, vector<int>(r + 1, 1));

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j < i; ++j) {
            dp[i % 2][j] = dp[(i - 1) % 2][j - 1] + dp[(i - 1) % 2][j];
        }
    }
    return dp[n % 2][r];
}

bool exist(vector<vector<char>> & board, const string & word, const int & i, const int & j, 
              const int & k) {
        if(k == word.size()) return true;
        if(i < 0 || i >= board.size()) return false;
        if(j < 0 || i >= board[0].size()) return false;       
    
        
        int ret = (board[i][j] == word[k]);
        char tmp = board[i][j];
        board[i][j] = '*';
        ret = ret && (
            exist(board, word, i + 1, j, k + 1) ||
            exist(board, word, i - 1, j, k + 1) ||
            exist(board, word, i, j + 1, k + 1) ||
            exist(board, word, i, j - 1, k + 1)
        );
        board[i][j] = tmp;
        
        return ret;
    }
    
    bool exist(vector<vector<char>>& board, string word) {

        
        
        bool ret = false;
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[0].size(); ++j) {
                ret |= exist(board, word, i, j, 0);
            }
        }
        return ret;
    }

struct HashTuple {
    size_t operator() (const tuple<int, int, int>& t) const {
        return hash<int>()(get<0>(t) ^ get<1>(t) * 1021 ^ get<2>(t) * 1048573);
    }
};

struct Clock {
    int weight;
    int price;

    public:
    Clock(int weight, int price) : price(price), weight(weight) {}
};

int knapsack(vector<vector<int> > & dp, const vector<Clock> & clocks, const int & totalWeight, const int & index) {
    if(totalWeight < 0) return numeric_limits<int>::min();
    if(index == clocks.size()) return 0;

    int & ret = dp[totalWeight][index];

    if(ret != -1) return ret;

    ret = max(clocks[index].price + knapsack(dp, clocks, totalWeight - clocks[index].weight, index + 1) 
    , knapsack(dp, clocks, totalWeight, index + 1));
    return ret;
}

int knapsackIterative(const vector<Clock> & clocks, const int & totalWeight) {
    vector<int> dp(totalWeight + 1, 0);
    for(int i = 0; i < clocks.size(); ++i) {
        for(int j = totalWeight; j >= clocks[i].weight; --j) {
            dp[j] = max(dp[j - clocks[i].weight] + clocks[i].price, dp[j]);
        }
    }
    return dp[totalWeight];
}

class SolutionTriangleMinimumPath {
public:

    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int> > dp(2, vector<int>(triangle.size() + 1, numeric_limits<int>::max()));
        
        dp[0][1] = 0;
        for(int i = 1; i <= triangle.size(); ++i) {
            for(int j = 1; j <= i; ++j) {
                int pi = ((i - 1) % 2 + 2) % 2;
                

                dp[i % 2][j] = 
                    triangle[i - 1][j - 1] + min(dp[pi][j], dp[pi][j - 1]);
                
            }
        }
        return *min_element(dp[triangle.size() % 2].begin(), 
                           dp[triangle.size() % 2].end());
    }
};

class SolutionMinimumPathSum {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int> > dp(2, vector<int>(n + 1, numeric_limits<int>::max()));
        
        dp[0][1] = 0;
        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                int pi = (i - 1) % 2;

                
                dp[i % 2][j] = 
                    grid[i - 1][j - 1] + min(dp[pi][j], dp[i % 2][j - 1]);
                
                
            }
        }
        return dp[m % 2][n];
    }
}; 

int twoEndsCoinGame(const vector<int> & v) {

    int n = v.size();
    vector<vector<int> > dp(n, vector<int>(n, 0));
    for(int width = 0; width < n; ++width) {
        for(int i = 0, j = width; j < n; ++j, ++i) {

            int bothStart = i + 2 <= j ? dp[i + 2][j] : 0;
            int bothEnd = j -2 >= i ? dp[i][j - 2] : 0;
            int bothEnds = i + 1 <= j - 1 ? dp[i + 1][j - 1] : 0;

            dp[i][j] = max(v[i] + min(bothStart, bothEnds), v[j] + min(bothEnd, bothEnds));

        }
    }

    return dp[0][n - 1];
}

int climbingStairs(int n, int k) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= k && i - j >= 0; ++j) {
            dp[i] += dp[i - j];
        }
    }
    return dp[n];
}

int minimumMessiness(const vector<string>& words, const int & lineLength) {
    int n = words.size();
    vector<int> sol(n);
    vector<int> minMess(n, numeric_limits<int>::max());
    for(int i = 0; i < n; ++i) {
        int mess = lineLength - words[i].size();
        
        minMess[i] = (i > 0 ? minMess[i - 1] : 0) + mess * mess;
        sol[i] = i;
        for(int j = i - 1; j >= 0; --j) {
            mess -= (words[j].size() + 1);
            if(mess < 0) break;

            int totalMess = mess * mess + (j > 0 ? minMess[j - 1] : 0);
            if(minMess[i] > totalMess) {
                sol[i] = j;
                minMess[i] = totalMess;
            }
        }
    }
    copy(sol.begin(), sol.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    return minMess.back();
}

class SolutionLIS {
public:    
    int lengthOfLIS(vector<int>& nums) {
        
        
        int n = nums.size();
        
        vector<int> dp(n, 0);
        int mx = 0;
        int idx = 0;
        vector<vector<int> > sol(n);
        for(int i = 0; i < n; ++i) {
            dp[i] = 1;
            mx = max(mx, 1);
            sol[i]= {nums[i]};
            for(int j = 0; j < i; ++j) {
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i], dp[j] + 1);
                    if(dp[i] > mx) {
                        sol[i] = sol[j];
                        sol[i].push_back(nums[i]);
                        mx = dp[i];
                        idx = i;
                    }
                }
            }
        }
        // copy(sol[idx].begin(), sol[idx].end(), ostream_iterator<int>(cout, " "));
        return mx;
    }
};

void test() {
    // cout << fib(1) << endl;
    // cout << fib(8) << endl;
    // cout << fib(3) << endl;
    // cout << fib(30) << endl;

    // cout << fibIterative(1) << endl;
    // cout << fibIterative(8) << endl;
    // cout << fibIterative(3) << endl;
    // cout << fibIterative(30) << endl;
    // cout << coinChange({19,28,176,112,30,260,491,128,70,137,253}, 8539);

    // cout << comb(3, 2) << endl;
    // cout << comb(10, 3) << endl;
    // cout << comb(20, 3) << endl;

    // int totalWeight = 10;
    // vector<Clock> v = {Clock(3, 7), Clock(8, 8), Clock(6, 4)};
    // vector<vector<int>> dp(totalWeight + 1, vector<int>(v.size(), -1));
    // cout << knapsack(dp, v, totalWeight, 0) << endl;
    // cout << knapsackIterative(v, totalWeight) << endl;

    // cout << twoEndsCoinGame({8, 15, 3, 7}) << endl;
    // cout << twoEndsCoinGame({2, 2, 2, 2}) << endl;
    // cout << twoEndsCoinGame({20, 30, 2, 2, 2, 10}) << endl;

    // cout << climbingStairs(4, 3) << endl;

    // cout << climbingStairs(5, 2) << endl;
    // cout << climbingStairs(1, 2) << endl;
    // cout << climbingStairs(2, 2) << endl;
    // cout << climbingStairs(4, 2) << endl;
    // cout << climbingStairs(6, 2) << endl;
    // cout << climbingStairs(8, 2) << endl;

    cout << minimumMessiness({"a", "b", "c", "d"}, 5) << endl;
    cout << minimumMessiness({"aaa", "bb", "cc", "ddddd"}, 6) << endl;
}

int main() {
    test();
}