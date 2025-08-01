#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
  TreeNode *left;
  int val;
  TreeNode *right;
  TreeNode(int val) {
    this->val = val;
    this->left = NULL;
    this->right = NULL;
  }
};

class Solution {
public:

// Find predecessor in left subtree.
// Make predecessor's .right point to current's .right.
// Move current's .left to .right.
// Set .left to NULL.
// Move to .right.

  void flatten(TreeNode *root) {
    // The idea is , we integrate the left subtree to the right of the node at each step, and continue
    // the end of the left sub tree with the right subtree, now the order is essentially root, left, right
    // we start with finding the end of the left subtree, which is either the first left node, or the right most 
    // element of the first left node, as in preorder we visit the right node last, then we connect this end
    // of left subtree to the right of the current and change the current's right to left, continue this as we visit
    // next nodes.
    // TC:O(2n), SC:O(1)
    TreeNode *curr = root;
    while (curr != NULL) {
      if (curr->left) 
      {
        TreeNode *prev = curr->left;
        while (prev->right) 
        {
          prev = prev->right;
        }
        // Connect predecessor's right to current's right
        prev->right = curr->right;

        // Move left subtree to the right
        curr->right = curr->left;
        curr->left = NULL;
      }
      // Move to the next node
      curr = curr->right;
    }
  }

  void flatten1(TreeNode *root) {
    // The idea is that, we traverse using preorder traversal and store the
    // address of each node, then we traverse the array and keep appending the
    // nodes in the order of the array to root. TC:O(2n), SC:O(2n)
    if (root == NULL) {
      return;
    }
    vector<TreeNode *> nodes;    // SC:O(n)
    stack<TreeNode *> stk;       // SC:O(n)
    while (root || !stk.empty()) // TC:O(n)
    {
      if (root) {
        nodes.push_back(root);
        if (root->right) {
          stk.push(root->right);
        }
        root = root->left;
      } else {
        root = stk.top();
        stk.pop();
      }
    }

    TreeNode *current = nodes[0];
    for (int i = 1; i < nodes.size(); i++) // TC:O(n)
    {
      current->right = nodes[i];
      current->left = NULL;
      current = current->right;
    }
  }
};
