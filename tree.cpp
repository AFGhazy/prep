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

int main() {

}