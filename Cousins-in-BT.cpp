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
    
    bool siblings(TreeNode *root, int x, int y){
        if(root== NULL) return false;
        
        if(root->left != NULL && root->right !=NULL && root->left->val == x && root->right->val ==y) {
            return true;
        }
        if(root->left != NULL && root->right !=NULL && root->left->val == y && root->right->val ==x) {
            return true;
        }
        
        bool l = siblings(root->left, x, y);
        if(l== true) return l; 
        
        bool r = siblings(root->right, x,y);
        if(r==true) return r; 
        
        return false; 
    }
    
    int func(TreeNode* root, int x, int level){
        
       // you have to find at which level x lies. 
        if(root == NULL) return 0;
        if(root->val == x) return level;
        
        int ll = func(root->left, x, level+1);
        if(ll!=0) return ll; 
        
        int lr = func(root->right, x , level+1);
        if(lr!=0) return lr;
        
        
        return 0; // does not exists. 
        
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
      if(func(root, x, 1)== func(root,y,1) && !siblings(root,x,y)){
          return true;
      }
        return false; 
    }
};
