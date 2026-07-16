#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
  int data;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int val)
  {
    data = val;
    left = right = NULL;
  }
};

// Binary Search Tree Insert
TreeNode *insert(TreeNode *root, int val)
{
  if (root == NULL)
    return new TreeNode(val);

  if (val < root->data)
    root->left = insert(root->left, val);
  else
    root->right = insert(root->right, val);

  return root;
}

void preOrder(TreeNode *root)
{
  if (root == NULL)
    return;
  cout << root->data << " ";
  preOrder(root->left);
  preOrder(root->right);
}

void inOrder(TreeNode *root)
{
  if (root == NULL)
    return;
  inOrder(root->left);
  cout << root->data << " ";
  inOrder(root->right);
}

void postOrder(TreeNode *root)
{
  if (root == NULL)
    return;
  postOrder(root->left);
  postOrder(root->right);
  cout << root->data << " ";
}

void levelOrder(TreeNode* root){
  if(root== nullptr) return;

  queue<TreeNode*> q;
  q.push<root>;
  q.push<nullptr>;

  while(!q.empty()){
    TreeNode* frontNode = q.front();
    q.pop();

    if(frontNode != NULL){
      cout<<frontNode->data<<" ";
      if(frontNode->left) q.push(frontNode->left);
      if(frontNode->right) q.push(frontNode->right);
    } else if (!q.empty()){
      q.push(nullptr);
    }
  }
}

int main()
{
  TreeNode *root = new TreeNode(25);
  insert(root, 10);
  insert(root, 20);
  insert(root, 30);
  insert(root, 40);
  insert(root, 60);

  cout<<height(root);

  return 0;
}