/**
 * Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
 * 
 * For example:
 * Given the below binary tree and sum = 22,
 *                     5
 *                    / \
 *                   4   8
 *                  /   / \
 *                 11  13  4
 *                /  \    / \
 *               7    2  5   1
 * return
 * [
 *   [5,4,11,2],
 *   [5,8,4,5]
 * ]
 */

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    public:
        vector<vector<int> > pathSum(TreeNode *root, int sum) {
            if (root == NULL) {
                return ret_;
            }
            vector<int> vec;
            figure(root, sum, vec);
            return ret_;
        }
        void figure(TreeNode *node, int sum, vector<int> vec) {
            vec.push_back(node->val);
            sum -= node->val;
            if (node->left == NULL && node->right == NULL && sum == 0) {
                ret_.push_back(vec);
                return;
            }
            if (node->left) {
                figure(node->left, sum, vec);
            }
            if (node->right) {
                figure(node->right, sum, vec);
            }
        }

    private:
        vector<vector<int> > ret_;
};
