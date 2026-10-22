#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // The idea is to find the node in which we will insert the value
        // we do this search, and store the last node which is the node in which
        // to be inserted, the direction to be inserted is kept in track by left
        // which is updated based on where was the current moved to left or right;
        // then simply insert the value on the insert node depending on the left bool
        // handle null root separately.
        // TC:O(logn), SC:O(1)
        if(root==NULL)
        {
            root=new TreeNode(val);
            return root;
        }
        TreeNode* current=root;
        TreeNode* insertNode;
        bool left;
        while(current!=NULL) // TC:O(logn)
        {
          int currentData=current->val;
          insertNode=current;
          if(currentData>val)
          {
            current=current->left;
            left=true;
          }
          else if(currentData<val)
          {
            current=current->right;
            left=false;
          }
        }
        if(left)
        {
            insertNode->left=new TreeNode(val);
        }
        else
        {
            insertNode->right=new TreeNode(val);
        }
        return root;
    }
};