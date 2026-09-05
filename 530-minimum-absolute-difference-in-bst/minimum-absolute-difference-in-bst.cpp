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
private:
  void inorder(TreeNode* node,vector<int>&res){
    if(node==NULL)return ;
    inorder(node->left,res);
    res.push_back(node->val);
    inorder(node->right,res);
  }
public:
    int getMinimumDifference(TreeNode* root) {
        vector<int>res;
        inorder(root,res);
        int diff=INT_MAX;
        for(int i=0;i<res.size()-1;i++){
            if(res[i+1]-res[i]<diff)
            diff=res[i+1]-res[i];
        }
        return diff;

    }
};