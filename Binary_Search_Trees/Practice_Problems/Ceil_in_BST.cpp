#include <bits/stdc++.h>
using namespace std;

int findCeil(struct TreeNode *root, int input) {
  // The idea is to default to -1, as only when all values are smaller than
  // target will there be no ceil, then do a search, only update when we get a
  // greater value as it can be a potential ceil return the ceil TC:O(logn),
  // SC:O(1)
  if (root == NULL) {
    return -1;
  }
  int currentData, ans = -1;
  struct TreeNode *current = root;
  while (current != NULL) // TC:O(logn)
  {
    currentData = current->data;
    if (currentData < input) {
      current = current->right;
    } else if (currentData > input) {
      current = current->left;
      ans = currentData;
    } else {
      return input;
    }
  }
  return ans;
}