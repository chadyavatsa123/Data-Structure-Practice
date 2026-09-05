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
    int findSecondMinimumValue(TreeNode* root) {
        int mn=INT_MAX;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            mn=min(mn,node->val);
            if(node->left)
            q.push(node->left);
            if(node->right)
            q.push(node->right);

        }
        queue<TreeNode*>qq;
        qq.push(root);
        bool find=false;
        long long smn=LLONG_MAX;
        while(!qq.empty()){
            TreeNode* node=qq.front();
            qq.pop();
            if(smn>(long long)node->val && mn!=node->val){
            smn=node->val;
            find=true;
            }
            if(node->left)
            qq.push(node->left);
            if(node->right)
            qq.push(node->right);

        }
       if(find==false)
       return -1;
        return smn;
    }
};