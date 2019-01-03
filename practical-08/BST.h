//
// Created by Yadunand Prem on 29/11/18.
//

#ifndef PRACTICAL_08_BST_H
#define PRACTICAL_08_BST_H

#include "BinaryNode.h"

class BST {
 private:
  BinaryNode *root;
 public:
  BST();
  ~BST();

  BinaryNode *search(ItemType target);
  BinaryNode *search(BinaryNode *root, ItemType target);

  void insert(ItemType item);
  void insert(BinaryNode *&root, ItemType target);

  void inorder();
  void inorder(BinaryNode *t);

  void preorder();
  void preorder(BinaryNode *t);

  void postorder();
  void postorder(BinaryNode *t);

  bool isEmpty();

  int countNodes();
  int countNodes(BinaryNode *t);

  int getHeight();
  int getHeight(BinaryNode *t);

  bool isBalanced();
  bool isBalanced(BinaryNode *t);

};

#endif //PRACTICAL_08_BST_H
