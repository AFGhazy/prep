#include<bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct State {
    int min;
    int max;
    bool isValid;
    
    State(int min, int max, bool isValid) : min(min), max(max), isValid(isValid) {}
};

class SolutionIsValidBSTS {
public:
    State isValidBSTS(TreeNode * cur) {
        State ret = State(cur->val, cur->val, true);
        if(cur->left) {
            State l = isValidBSTS(cur->left);
            ret.min = min(l.min, ret.min);
            ret.isValid = l.isValid && ret.isValid && l.max < cur->val;
        }
        
        if(cur->right) {
            State r = isValidBSTS(cur->right);
            ret.max = max(r.max, ret.max);
            ret.isValid = r.isValid && ret.isValid && r.min > cur->val;
        }
        
        return ret;
    }
    
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        return isValidBSTS(root).isValid;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


class SolutionOptimalIsValidBST {
public:
    
    bool isValidBSTHelper(TreeNode* cur, TreeNode* &prev) {
        if(!cur) return true;
        
        bool ret = isValidBSTHelper(cur->left, prev);
        if(!ret || (prev && prev->val >= cur->val)) return false;
        prev = cur;
        return isValidBSTHelper(cur->right, prev);
    }
    
    bool isValidBST(TreeNode* root) {
        TreeNode * prev = NULL;
        return isValidBSTHelper(root, prev);
    }
};


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode * l, TreeNode * r) {
        if(l == NULL && r == NULL) return true;
        if(!l || !r) return false;
        return isSymmetric(l->left, r->right) && isSymmetric(l->right, r->left) && l->val == r->val;
    }
    
    bool isSymmetric(TreeNode* cur) {
        return isSymmetric(cur, cur);
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct State {
    TreeNode * node;
    int level;
    State(TreeNode * node, int level) : node(node), level(level) {}
};

class SolutionLevelOrder {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > v;
        queue<State> q;
        if(root) q.push(State(root, 0));
        while(q.size()) {
            State cur = q.front();
            q.pop();
            if(cur.level >= v.size()) v.push_back(vector<int>());
            v[cur.level].push_back(cur.node->val);
            if(cur.node->left) q.push(State(cur.node->left, cur.level + 1));
            if(cur.node->right) q.push(State(cur.node->right, cur.level + 1));
        }
        return v;
    }
};

class SolutionZigzagLevelOrder {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > v;
        queue<State> q;
        if(root) q.push(State(root, 0));
        while(q.size()) {
            State cur = q.front();
            TreeNode * l = cur.node->left;
            TreeNode * r = cur.node->right;
            int lvl = cur.level;
            q.pop();
            
            if(lvl >= v.size()) v.push_back(vector<int>());
            v[lvl].push_back(cur.node->val);
            
            if(l) q.push(State(l, lvl + 1));
            if(r) q.push(State(r, lvl + 1));
        }
        for(int i = 0; i < v.size(); ++i) if(i & 1) reverse(v[i].begin(), v[i].end());
        return v;
    }
};

int main() {

}