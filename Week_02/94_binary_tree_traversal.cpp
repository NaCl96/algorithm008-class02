/*
 * @Author: NaCl
 * @Date: 2020-04-23 08:18:52
 * @LastEditTime: 2020-04-23 11:45:47
 * @LastEditors: Please set LastEditors
 * @Description: 树的前中后遍历的非递归实现
 * @FilePath: \algorithm008-class02\Week_02\94_binary_tree_traversal.cpp
 */

#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * @description: 树结点定义
 * @param {type}
 * @return:
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * @description: 通过数组创建树
 * @param {type}
 * @return:
 */
TreeNode *createTree(vector<int> list, int start) {
  if (list[start] == '#') {
    return NULL;
  }
  TreeNode *root = new TreeNode(list[start]);
  int lnode = 2 * start + 1;
  int rnode = 2 * start + 2;
  if (lnode > list.size() - 1) {
    root->left = NULL;
  } else {
    root->left = createTree(list, lnode);
  }

  if (rnode > list.size() - 1) {
    root->right = NULL;
  } else {
    root->right = createTree(list, rnode);
  }
  return root;
}

/**
 * @description: 中序非递归_1
 * @param {type}
 * @return: 中序遍历数组
 */
vector<int> inorderedTraversal(TreeNode *root) {
  vector<int> ans;
  stack<pair<TreeNode *, bool>> stk;
  stk.push(make_pair(root, false));
  bool visited;
  while (!stk.empty()) {
    root = stk.top().first;
    visited = stk.top().second;
    if (root == NULL) {
      continue;
    }
    if (visited) {
      ans.push_back(root->val);
    } else {
      stk.push(make_pair(root->right, false));
      stk.push(make_pair(root, true));
      stk.push(make_pair(root->left, false));
    }
  }
}

/**
 * @description: 中序非递归_2
 * @param {type}
 * @return:
 */
vector<int> inorderedTraversa2(TreeNode *root) {
  stack<TreeNode *> stk;
  vector<int> ans;
  TreeNode *rt = root;

  while (rt || !stk.empty()) {
    while (rt) {
      stk.push(rt);
      rt = rt->left;
    }
    rt = stk.top();
    stk.pop();
    ans.push_back(rt->val);
    rt = rt->right;
  }
  return ans;
}


/* ----------------------------------------------- */
//前序
vector<int> preorderTraversal(TreeNode* root){
  vector<int> ans;
  stack<TreeNode*> stk;
  TreeNode* rt = root;
  while(rt || stk.size()){
    while(rt){
      ans.push_back(rt->val);
      stk.push(rt->right);
      rt = rt->left;
    }
    rt = stk.top();
    stk.pop();
  }
  return ans;
}
int main() {
  vector<int> list = {1,'#',2,3};

  TreeNode* root = createTree(list,0);
  vector<int> res = inorderedTraversa2(root);
  return 0;
}

/* ----------------------------------------------- */
//后序
vector<int> postorderTraversal(TreeNode *root){
  vector<int> ans;
  stack<TreeNode*> stk;
  //用来记录是从左子树返回，还是从右子树返回，
  unordered_map<TreeNode*,int> map;
  TreeNode* rt = root;
  while(rt || stk.size()){
    //不断将左子树压入栈中
    while(rt){
      stk.push(rt);
      rt = rt->left;
    }
    //当栈不空，且是从右子树返回，那么就访问，并且出栈当前结点，
    while(stk.size() && map[stk.top()]){
      ans.push_back(stk.top()->val);
      stk.pop();
    }
    //如果从左子树返回，那么就去遍历右子树，并且记录当前在右子树。
    if(stk.size()){
      rt = stk.top()->right;
      map[stk.top()] = 1;
    }
  }
  return ans;
}