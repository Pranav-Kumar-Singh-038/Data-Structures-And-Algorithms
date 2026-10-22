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
  TreeNode *deleteNode(TreeNode *root, int key) {
    if (root == NULL) {
      return NULL;
    }

    TreeNode *current = root;
    TreeNode *prev = NULL;
    bool found = false;

    while (current != NULL && !found) {
      if (key < current->val) {
        prev = current;
        current = current->left;
      } else if (key > current->val) {
        prev = current;
        current = current->right;
      } else {
        found = true;
      }
    }

    if (!found) {
      return root;
    }

    if (!current->left && !current->right) {
      if (!prev) {
        delete current;
        return NULL;
      }
      if (prev->left == current) {
        prev->left = NULL;
      } else {
        prev->right = NULL;
      }
      delete current;
      return root;
    }

    if (!current->left || !current->right) {
      TreeNode *child = (current->left) ? current->left : current->right;
      if (!prev) {
        delete current;
        return child;
      }
      if (prev->left == current) {
        prev->left = child;
      } else {
        prev->right = child;
      }
      delete current;
      return root;
    }

    TreeNode *rightChild = current->right;
    TreeNode *leftSubtree = current->left;

    TreeNode *leftmost = rightChild;
    while (leftmost->left != NULL) {
      leftmost = leftmost->left;
    }
    leftmost->left = leftSubtree;

    if (!prev) {
      delete current;
      return rightChild;
    }
    if (prev->left == current) {
      prev->left = rightChild;
    } else {
      prev->right = rightChild;
    }

    delete current;
    return root;
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

  void printBFS(TreeNode *root) {
    if (!root) {
      cout << "null";
      return;
    }

    queue<TreeNode *> q;
    q.push(root);

    vector<string> result;

    while (!q.empty()) {
      TreeNode *current = q.front();
      q.pop();

      if (current) {
        result.push_back(to_string(current->val));
        q.push(current->left);
        q.push(current->right);
      } else {
        result.push_back("null");
      }
    }

    while (!result.empty() && result.back() == "null") {
      result.pop_back();
    }

    for (int i = 0; i < result.size(); i++) {
      cout << result[i];
      if (i < result.size() - 1)
        cout << " ";
    }
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
  TreeNode *ans = sol.deleteNode(root, val);
  sol.printBFS(ans);
  return 0;
}
