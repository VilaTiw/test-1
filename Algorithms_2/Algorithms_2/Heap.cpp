#include"Heap.h"
#include<iostream>

using namespace std;

int Heap::Parent(int i)
{
	return i>>1;
}

int Heap::Left(int i)
{
	return (i<<1) + 1;
}

int Heap::Right(int i)
{
	return (i<<1) + 1 + 1;
}

void Heap::Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void Heap::MaxHeapify(int* A, int i)
{
	int l = Left(i), r = Right(i), largest = 0;
	if ((l <= heap_size) && (A[l] > A[i])) largest = l;
	else largest = i;

	if ((r <= heap_size) && (A[r] > A[largest])) largest = r;
	if (largest != i)
	{
		Swap(&A[i], &A[largest]);
		MaxHeapify(A, largest);
	}

}

void Heap::BuildMaxHeap(int* A)
{
	for (int i = (length / 2) - 1; i >= 0; --i) MaxHeapify(A, i);
}

void Heap::MinHeapify(int* A, int i)
{
	int l = Left(i), r = Right(i), least = 0;
	if ((l <= heap_size) && (A[l] < A[i])) least = l;
	else least = i;

	if ((r <= heap_size) && (A[r] < A[least])) least = r;
	if (least != i)
	{
		Swap(&A[i], &A[least]);
		MinHeapify(A, least);
	}

}

void Heap::BuildMinHeap(int* A)
{
	for (int i = (length / 2) - 1; i >= 0; --i) MinHeapify(A, i);
}

void Heap::HeapSort(int* A)
{
	char symbol;
	cout << "Do you want to sort massive descending or ascending ? (enter d/a): ";
	cin >> symbol;
	switch (symbol)
	{
	case 'a':
		BuildMaxHeap(A);

		for (int i = length - 1; i > 0; --i)
		{
			Swap(&A[0], &A[i]);
			--heap_size;
			MaxHeapify(A, 0);
		}
		break;

	case 'd':
		BuildMinHeap(A);

		for (int i = length - 1; i > 0; --i)
		{
			Swap(&A[0], &A[i]);
			--heap_size;
			MinHeapify(A, 0);
		}
		break;
	}
}

int Heap::HeapMaximum(int* A)
{
	return A[0];
}

int Heap::HeapExtractMax(int* A)
{
	int max;

	if (heap_size < 0)
	{
		cout << "The queue is empty!\n";
	}

	max = A[0];
	A[0] = A[heap_size];
	--heap_size;
	MaxHeapify(A, 0);

	return max;
}

void Heap::HeapIncreaseKey(int* A, int i, int k)
{
	if (k <= A[i])
	{
		cout << "The new key is less than current key!\n";
	}

	A[i] = k;

	while (i > 0 && A[Parent(i)] < A[i])
	{
		Swap(&A[i], &A[Parent(i)]);
		i = Parent(i);
	}
}

void Heap::MaxHeapInsert(int* A, int k)
{
	if (heap_size + 1 < length)
	{
		++heap_size;
		A[heap_size] = k;
		HeapIncreaseKey(A, heap_size, k);
	}
	else
	{
		cout << "An impossible option - the binary heap is larger than the array" << endl;
	}
	
}

int Heap::HeapMinimum(int* A)
{
	return A[0];
}

int Heap::HeapExtractMin(int* A)
{
	int min;

	if (heap_size < 0)
	{
		cout << "The queue is empty!\n";
	}

	min = A[0];
	A[0] = A[heap_size];
	--heap_size;
	MinHeapify(A, 0);

	return min;
}

void Heap::HeapDecreaseKey(int* A, int i, int k)
{
	if (A[i] <= k)
	{
		cout << "The new key is bigger than current key!\n";
	}

	A[i] = k;

	while (i > 0 && A[Parent(i)] > A[i])
	{
		Swap(&A[i], &A[Parent(i)]);
		i = Parent(i);
	}
}

void Heap::MinHeapInsert(int* A, int k)
{
	if (heap_size + 1 < length)
	{
		++heap_size;
		A[heap_size] = k;
		HeapDecreaseKey(A, heap_size, k);
	}
	else
	{
		cout << "An impossible option - the binary heap is larger than the array" << endl;
	}
}

