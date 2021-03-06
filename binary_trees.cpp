#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;
        
        auto tmp = root->right;
        root->right = invertTree(root->left);
        root->left = invertTree(tmp);
        
        return root;
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
    bool LCA(TreeNode * cur, TreeNode * p, TreeNode * q, TreeNode *& lca) {
        if(!cur) return false;
        
        bool ret = false;
        
        bool l = LCA(cur->left, p, q, lca);
        bool r = LCA(cur->right, p, q, lca);
        
        ret = (cur == p || cur == q);
        
        if((l && r || (ret && (l || r))) && lca == NULL) {
            lca = cur;
        }
        
        ret |= (l || r);
        
        return ret;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode * sol = NULL;
        LCA(root, p, q, sol);
        return sol;
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
class SolutionDiameterOfBinaryTree {
public:
    int findDim(TreeNode * cur, int & mx) {
        if(!cur) return 0;
        
        int l = 1 + findDim(cur->left, mx);
        int r = 1 + findDim(cur->right, mx);
        
        
        
        mx = max(max(l + r - 2, mx), max(l, r) - 1);
        
        return max(l, r);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int mx = 0;
        findDim(root, mx);
        return mx;
    }
};


int main() {
}