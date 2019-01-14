#pragma once

typedef int ItemType;

struct BinaryNode
{
	ItemType   item;	// data item
	BinaryNode *left;	// pointer pointing to left subtree
	BinaryNode *right;	// pointer pointing to right subtree
};
