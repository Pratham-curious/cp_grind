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
    pair<int,int> nodeSum(TreeNode* root,int& ans){
        if(root == NULL) return {0,0};
        auto right = nodeSum(root->right,ans);
        auto left = nodeSum(root->left,ans);

        int sum = right.first + left.first + root->val;
        int count = right.second + left.second + 1;

        ans += ((sum/count) == root->val);

        return {sum,count};
    }
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        nodeSum(root,ans);
        return ans;
    }
};