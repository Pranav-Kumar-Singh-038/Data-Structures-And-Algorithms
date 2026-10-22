#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
  TreeNode *left;
  TreeNode *right;
  int data;

  TreeNode(int val) {
    this->left = NULL;
    this->right = NULL;
    this->data = val;
  }
};

class Solution {
public:
  bool findTarget(TreeNode *root,
                  int target) // traverse inorder and inorder reverse, inorder
                              // gives ascending in bst and reverse inorder will
                              // give descending, then normal 2 sum approach.
  {
    // TC: O(n), SC: O(logn)
    if (!root) {
      return false;
    }

    stack<TreeNode *> s1, s2;
    TreeNode *temp1 = root;
    TreeNode *temp2 = root;

    while (1) {
      while (temp1) {
        s1.push(temp1);
        temp1 = temp1->left;
      }

      while (temp2) {
        s2.push(temp2);
        temp2 = temp2->right;
      }

      if (s1.empty() || s2.empty()) {
        break;
      }

      temp1 = s1.top();
      temp2 = s2.top();

      if ((temp1->data + temp2->data) == target) {
        if (temp1 == temp2) {
          return false;
        }

        return true;
      }

      else if ((temp1->data + temp2->data) < target) {
        s1.pop();
        temp1 = temp1->right;
        temp2 = NULL;
      } else {
        s2.pop();
        temp2 = temp2->left;
        temp1 = NULL;
      }
    }

    return false;
  }

  bool findTarget1(TreeNode *root,
                   int k) // traverse the tree, for each node find its
                          // k-node->val, using binary search in bst.
  {
    // TC: O(nlogn), SC: O(n)
    TreeNode *current;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      current = q.front();
      q.pop();
      if (current->left) {
        q.push(current->left);
      }
      if (current->right) {
        q.push(current->right);
      }
      int target = k - current->data;
      bool found = searchBST(root, target, current);
      if (found) {
        return true;
      }
    }
    return false;
  }

  bool searchBST(TreeNode *root, int val, TreeNode *firstNode) {
    // TC: O(logn)(if not skewed), SC: O(1)
    TreeNode *current = root;
    while (current != NULL) {
      if (current->data == val && current == firstNode) {
        return false;
      } else if (current->data == val && current != firstNode) {
        return true;
      } else if (current->data > val) {
        current = current->left;
      } else {
        current = current->right;
      }
    }
    return false;
  }

  TreeNode *createBST(vector<optional<int>> vec) {
    if (vec.empty() || !vec[0].has_value()) {
      return NULL;
    }
    TreeNode *root = new TreeNode(vec[0].value());
    TreeNode *current = NULL;
    queue<TreeNode *> q;
    q.push(root);
    int i = 1;
    while (i < vec.size()) {
      current = q.front();
      q.pop();
      if (i < vec.size() && vec[i].has_value()) {
        current->left = new TreeNode(vec[i].value());
        q.push(current->left);
      }
      i++;
      if (i < vec.size() && vec[i].has_value()) {
        current->right = new TreeNode(vec[i].value());
        q.push(current->right);
      }
      i++;
    }
    return root;
  }
};

int main() {
  int n, val;
  cin >> n >> val;
  vector<optional<int>> vec(n);
  string x;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (x == "null") {
      vec[i] = nullopt;
    } else {
      vec[i] = stoi(x);
    }
  }
  Solution sol;
  TreeNode *root = sol.createBST(vec);
  bool ans = sol.findTarget(root, val);
  cout << ans;
  return 0;
}
