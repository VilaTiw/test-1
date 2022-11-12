#include <iostream>
#include"Tree.h"

using namespace std;

int main()
{
	int var_b = 1, var_s = 1, number;
	char symbol_b, symbol_s, version_tree;

	Node example, *root = nullptr, *delNode = nullptr, *simple_root = nullptr;
	
	cout << "What kind of tree you want to create ? simple tree - enter 's', binary search tree - 'b': ";
	cin >> version_tree;

	switch (version_tree)
	{
	case 's':
		while (var_s != 0)
		{
			cout << "\n'+' - create tree\n's' - show tree\n'1' - PrefixOrder\n'2' - PostfixOrder\n'3' - InfixOrder\n'x' - exit\n";
			cin >> symbol_s;

			switch (symbol_s)
			{
			case'+':
				int n;
				cout << "How many nodes, you want to create?\n";
				cin >> n;
				example.CreateTree(&simple_root, n);
				break;

			case's':
				if (simple_root != nullptr)
				{
					example.ShowTree(simple_root, 0);
				}
				else
				{
					cout << "Tree is empty! There is nothing to show.." << endl;
				}
				break;

			case'1':
				example.PrefixOrder(simple_root);
				break;

			case'2':
				example.PostfixOrder(simple_root);
				break;

			case'3':
				example.InfixOrder(simple_root);
				break;

			case 'x':
				var_s = 0;
				break;

			}
		}
		break;

	case 'b':
		
		while (var_b != 0)
		{
			cout << "'+' - insertnodebst\n's' - showtree\n'-' - delete\n'x' - exit\n";
			cin >> symbol_b;

			switch (symbol_b)
			{
			case '+':
				if (root != nullptr)
				{
					example.InsertNodeBST(root);
				}
				else
				{
					root = example.CreateRootBST();
				}
				break;

			case 's':
				if (root != nullptr)
				{
					example.ShowTree(root, 0);
				}
				else
				{
					cout << "Tree is empty! There is nothing to show.." << endl;
				}
				break;

			case '-':
				if (root != nullptr)
				{
					cout << "Enter number you want to delete: ";
					cin >> number;

					delNode = example.SearchNodeBST(number, root);

					if (delNode != nullptr)
					{
						example.DeleteNodeBST(&root, &delNode);
					}
					else
					{
						cout << "The node with this key doesn`t exist!" << endl;
					}

				}
				else
				{
					cout << "Tree is empty! There is nothing to delete.." << endl;
				}
				break;

			case 'x':
				var_b = 0;
				break;
			}

		}
		break;
	}

}


