#include <iostream>
#include"Heap.h"
using namespace std;

int main()
{
	Heap example, example2;
	int massive[] = { 1,3,5,7,9,2,4,6,8,0 }, massive_2[] = {99, 11, 88, 22, 77, 33, 66, 44, 55}, var = 1, var2 = 1;
	char symbol, symbol2;

	example.A = massive;
	example.length = sizeof(massive) / sizeof(int);
	example.heap_size = example.length - 1;

	example2.A = massive_2;
	example2.length = sizeof(massive_2) / sizeof(int);
	example2.heap_size = example2.length - 1;


	while (var > 0)
	{
		cout << "Enter '=' to show massive, 's' to sort massive, '+' to build max heap, '-' to build min heap, \n'x' to exit: ";
		cin >> symbol;

		switch (symbol)
		{
		case '=':
			for (int i = 0; i < sizeof(massive) / sizeof(int); ++i) cout << massive[i] << " ";
			cout << endl;
			break;

		case 's':
			example.HeapSort(massive);
			example.heap_size = example.length - 1;
			break;

		case '+':
			example.BuildMaxHeap(massive);
			break;

		case '-':
			example.BuildMinHeap(massive);
			break;

		case 'x':
			--var;
			break;
		}
	}

	while (var2 > 0)
	{
		cout << "\nEnter '=' to show massive, '+' to HeapMax(), '-' to HeapMin(), '*' to HeapExtractMax(), \n'/' to HeapExtractMin(), 'K' to HeapIncreaseKey(), 'k' to HeapDecreaseKey, 'I' to MaxHeapInsert(), 'i' to MinHeapInsert, 'x' to exit: ";
		cin >> symbol2;

		switch (symbol2)
		{
		case '=':
			for (int i = 0; i < sizeof(massive_2) / sizeof(int); ++i) cout << massive_2[i] << " ";
			cout << endl;
			break;

		case '+':
			example2.BuildMaxHeap(massive_2);
			cout<<example2.HeapMaximum(massive_2);
			break;

		case '-':
			example2.BuildMinHeap(massive_2);
			cout<<example2.HeapMinimum(massive_2);
			break;

		case '*':
			example2.BuildMaxHeap(massive_2);
			cout<<example2.HeapExtractMax(massive_2);
			break;

		case '/':
			example2.BuildMinHeap(massive_2);
			cout<<example2.HeapExtractMin(massive_2);
			break;

		case 'K':
			int key, index;
			cout << "Enter key: ";
			cin >> key;
			cout << "\nEnter index: ";
			cin >> index;
			example2.BuildMaxHeap(massive_2);
			example2.HeapIncreaseKey(massive_2, index, key);
			break;

		case 'k':
			int key1, index1;
			cout << "Enter key: ";
			cin >> key1;
			cout << "\nEnter index: ";
			cin >> index1;
			example2.BuildMinHeap(massive_2);
			example2.HeapDecreaseKey(massive_2, index1, key1);
			break;

		case 'I':
			int key2;
			cout << "Enter key: ";
			cin >> key2;
			example2.BuildMaxHeap(massive_2);
			example2.MaxHeapInsert(massive_2, key2);
			break;

		case 'i':
			int key3;
			cout << "Enter key: ";
			cin >> key3;
			example2.BuildMinHeap(massive_2);
			example2.MinHeapInsert(massive_2, key3);
			break;

		case 'x':
			--var2;
			break;
		}
	}
	


	


	
	



}

