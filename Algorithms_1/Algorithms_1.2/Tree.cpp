#include<iostream>
#include"Tree.h"

using namespace std;

void Node::CreateTree(Node** pNode, int n)
{
	if (n <= 0)
	{
		*pNode = nullptr;
	}
	else
	{
		int data, n_left = n / 2, n_right = n - n_left - 1;
		cout << "Enter data: ";
		cin >> data;

		(*pNode) = new Node;
		((*pNode)->key = data);
		((*pNode)->left = nullptr);
		((*pNode)->right = nullptr);


		CreateTree(&((*pNode)->left), n_left);
		CreateTree(&((*pNode)->right), n_right);

	}
}

void Node::PrefixOrder(Node* pNode)
{
	if (pNode != nullptr)
	{
		cout << " " << pNode->key << " ";
		PrefixOrder(pNode->left);
		PrefixOrder(pNode->right);
	}
}

void Node::PostfixOrder(Node* pNode)
{
	if (pNode != nullptr)
	{
		PostfixOrder(pNode->left);
		PostfixOrder(pNode->right);
		cout << " " << pNode->key << " ";
	}
}

void Node::InfixOrder(Node* pNode)
{
	if (pNode != nullptr)
	{
		InfixOrder(pNode->left);
		cout << " " << pNode->key << " ";
		InfixOrder(pNode->right);
	}

}

Node* Node::SearchNodeBST(int key, Node* root)
{
	Node* pNode = root;

	while (pNode != NULL)
	{

		if (pNode->key == key)
		{
			//cout << "Key is " << key<<endl;

			return pNode;
		}
		else
		{
			if (pNode->key > key)
			{
				pNode = pNode->left;
			}
			else
			{
				pNode = pNode->right;
			}
		}
	}
	
	return nullptr;
}

Node* Node::CreateRootBST()
{
	int data;
	cout << "Enter data: ";
	cin >> data;

	Node* root = new Node;
	root->key = data;
	root->left = nullptr;
	root->right = nullptr;
	root->parent = nullptr;

	return root;
}

void Node::InsertNodeBST(Node* root)
{
	int data;
	cout << "Enter data: ";
	cin >> data;

	if (SearchNodeBST(data, root) != nullptr)
	{
		cout << "This key already exist!\n";
	}
	else
	{
		Node* pNew = new Node;
		pNew->key = data;
		pNew->left = nullptr;
		pNew->right = nullptr;
		pNew->parent = nullptr;

		Node* pNode = root;
		Node* previous = nullptr;

		while (pNode != nullptr)
		{
			previous = pNode;

			if (pNode->key > data)
			{
				pNode = pNode->left;
			}
			else
			{
				pNode = pNode->right;
			}
		}

		pNew->parent = previous;

		if (previous->key > data)
		{
			previous->left = pNew;
		}
		else
		{
			previous->right = pNew;
		}
	}
}

void Node::ShowTree(Node* root, int L)
{
	if (root != NULL)
	{
		ShowTree(root->left, L + 1);

		for (int i = 0; i < L; ++i) cout << " ";
		cout << root->key << endl;

		ShowTree(root->right, L + 1);
	}
	
}

Node* Node::TreeMinimum(Node* root)
{
	while (root->left != nullptr)
	{
		root = root->left;
	}

	//cout << "Min: " << root->key << endl;

	return root;
}

Node* Node::TreeMaximum(Node* root)
{
	while (root->right != nullptr)
	{
		root = root->right;
	}

	//cout << "Max: " << root->key << endl;

	return root;
}

Node* Node::SuccessorNodeBST(Node* root)
{
	Node* link = nullptr;

	if (root->right != NULL)
	{
		 link = TreeMinimum(root->right);
		 return link;
	}
	else
	{
		Node* previous = root->parent;

		while (previous != nullptr && previous->right == root)
		{
			root = previous;
			previous = previous->parent;
		}

		return previous;	
	}
}

Node* Node::PredecessorNodeBST(Node* root)
{
	Node* link = nullptr;

	if (root->left != NULL)
	{
		link = TreeMaximum(root->left);
		return link;
	}
	else
	{
		Node* previous = root->parent;

		while (previous != nullptr && previous->right != root)
		{
			root = previous;
			previous = previous->parent;
		}

		return previous;
	}
}

int Node::DeleteNodeBST(Node** root, Node** delNode)
{
	int variable = 0;

	if ((*delNode)->left == nullptr && (*delNode)->right == nullptr)
	{
		if (*delNode == *root)
		{
			variable = (*delNode)->key;
			cout << "Root: " << root << endl;
			cout << "delNode: " << delNode << endl;
			*root = nullptr;
			delete *root;
			cout << "Root: " << root << endl;
			cout << "delNode: " << delNode << endl;

		}
		else
		{
			if ((*delNode) == ((*delNode)->parent)->left)
			{
				((*delNode)->parent)->left = nullptr;
			}
			else
			{
				((*delNode)->parent)->right = nullptr;
			}

			variable = (*delNode)->key;
			
			delete *delNode;
		}

		return variable;
	}

	if (((*delNode)->left == nullptr && (*delNode)->right != nullptr) || ((*delNode)->left != nullptr && (*delNode)->right == nullptr))
	{
		Node* next = nullptr;
		
		if ((*delNode)->left != nullptr)
		{
			next = (*delNode)->left;
		}
		else
		{
			next = (*delNode)->right;
		}

		if ((*delNode)->parent == nullptr)
		{
			next->parent = nullptr;

			variable = (*delNode)->key;
			cout << "delete root\n";
			
			*root = next;

			delete *delNode;

		}
		else
		{
			if (((*delNode)->parent)->left == (*delNode))
			{
				((*delNode)->parent)->left = next;
			}
			else
			{
				((*delNode)->parent)->right = next;
			}

			next->parent = (*delNode)->parent;

			variable = (*delNode)->key;

			delete *delNode;
		}

		return variable;

	}

	if ((*delNode)->left != nullptr && (*delNode)->right != nullptr)
	{
		Node* term = nullptr;
		char symbol;

		cout << "You want to delete current node by Predecessor-node or Successor-node ? (enter 'p' or 's') : ";
		cin >> symbol;

		switch (symbol)
		{
		case 'p':
			term = PredecessorNodeBST(*delNode);
			break;

		case 's':
			term = SuccessorNodeBST(*delNode);
			break;
		}

		variable = (*delNode)->key;

		(*delNode)->key = term->key;

		DeleteNodeBST(root, &term);

		return variable;
	}
}
