#pragma once
#include<iostream>

typedef int datatype;

struct Node
{
	datatype key;
	Node* parent;
	Node* left;
	Node* right;

	void CreateTree(Node** pNode, int n);
	void PrefixOrder(Node* pNode);
	void PostfixOrder(Node* pNode);
	void InfixOrder(Node* pNode);
	void ShowTree(Node* root, int L);

	Node* SearchNodeBST(int key, Node* root);
	Node* CreateRootBST();
	void  InsertNodeBST(Node* root);
	Node* TreeMinimum(Node* root);
	Node* TreeMaximum(Node* root);
	Node* SuccessorNodeBST(Node* root);
	Node* PredecessorNodeBST(Node* root);
	int   DeleteNodeBST(Node** root, Node** delNode);
	
};
