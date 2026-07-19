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
  int ans=0;
struct Node{
    int minNode,maxNode,maxSum;
  
    Node(int minNode,int maxNode,int maxSum){
        this->minNode=minNode;
        this->maxNode=maxNode;
        this->maxSum=maxSum;
    }
};
Node ValidBST(TreeNode* node){
    if(!node)
    return Node(INT_MAX,INT_MIN,0);
    auto left=ValidBST(node->left);
    auto right=ValidBST(node->right);
    if(left.maxNode<node->val && node->val<right.minNode){
    int sum=node->val+left.maxSum+right.maxSum;
    
    ans=max(ans,sum);
    return Node(min(node->val,left.minNode),max(node->val,right.maxNode),sum);}
    else
    return Node(INT_MIN,INT_MAX,0);
}
    int maxSumBST(TreeNode* root) {
      ValidBST(root);  
      return ans;
    }
};