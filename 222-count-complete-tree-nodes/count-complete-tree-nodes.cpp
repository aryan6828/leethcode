class Solution {
public:
    int computeHeight(TreeNode* root) {
        int h = 0;
        while (root) {
            h++;
            root = root->left;
        }
        return h;
    }

    bool exists(int idx, int h, TreeNode* root) {
        int left = 0, right = (1 << (h - 1)) - 1;
        for (int i = 0; i < h - 1; i++) {
            int mid = (left + right) / 2;
            if (idx <= mid) {
                root = root->left;
                right = mid;
            } else {
                root = root->right;
                left = mid + 1;
            }
        }
        return root != nullptr;
    }

    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int h = computeHeight(root);
        if (h == 1) return 1;

        int left = 0, right = (1 << (h - 1)) - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (exists(mid, h, root)) left = mid + 1;
            else right = mid - 1;
        }

        return (1 << (h - 1)) - 1 + left;
    }
};
