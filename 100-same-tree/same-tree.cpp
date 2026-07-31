/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Agar dono null hain → same
        if (!p && !q) return true;
        
        // Agar ek null hai aur dusra nahi → different
        if (!p || !q) return false;
        
        // Agar values alag hain → different
        if (p->val != q->val) return false;
        
        // Left aur Right subtree ko recursively check karo
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
