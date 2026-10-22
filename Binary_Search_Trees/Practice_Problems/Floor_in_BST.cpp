#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
  TreeNode *left;
  TreeNode *right;
  int val;

  TreeNode(int val) {
    this->left = NULL;
    this->right = NULL;
    this->val = val;
  }
};

class Solution {

public:
  int floor(TreeNode *root, int x) {
    int Fl = -1;
    TreeNode *current = root;
    while (current != NULL) {
      int val = current->val;
      if (val < x) {
        current = current->right;
        Fl = val;
      } else if (val > x) {
        current = current->left;
      } else {
        return val;
      }
    }
    return Fl;
  }
};