/*
 * @Author: your name
 * @Date: 2020-04-30 14:22:24
 * @LastEditTime: 2020-04-30 14:24:16
 * @LastEditors: Please set LastEditors
 * @Description: 二叉树的序列化与反序列化
 * @FilePath: \algorithm008-class02\Week_03\297_tree_seri_deseri.cpp
 */

#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
 public:
  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    string res = "";
    // if(root == NULL){
    //     return res;
    // }
    queue<TreeNode*> que;
    que.push(root);
    while (!que.empty()) {
      TreeNode* cur = que.front();
      que.pop();
      if (cur != NULL) {
        res += to_string(cur->val) + ',';
        que.push(cur->left);
        que.push(cur->right);
      } else if (cur == NULL) {
        res += "null,";
      }
    }
    return res;
  }

  // Decodes your encoded data to tree.
  vector<string> split(string& data) {
    if (data.size() == 0) {
      return {};
    }
    int start = 0;
    vector<string> res;
    while (1) {
      auto end = data.find(',', start);
      if (end == string::npos) break;
      res.push_back(data.substr(start, end - start));
      start = end + 1;
    }
    return move(res);
  }
  TreeNode* deserialize(string data) {
    vector<string> val = split(data);
    if (val[0] == "null") {
      return NULL;
    }
    queue<TreeNode*> que;
    que.push(new TreeNode(stoi(val[0])));
    TreeNode* ans = que.front();
    for (int i = 1; i < val.size();) {
      if (val[i] != "null") {
        auto cur = new TreeNode(stoi(val[i]));
        que.push(cur);
        que.front()->left = cur;
      }
      ++i;
      if (val[i] != "null") {
        auto cur = new TreeNode(stoi(val[i]));
        que.push(cur);
        que.front()->right = cur;
      }
      ++i;
      que.pop();
    }
    return ans;
  }
};