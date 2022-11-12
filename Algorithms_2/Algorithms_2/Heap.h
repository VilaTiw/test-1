#pragma once

struct Heap
{
	int* A;
	int heap_size;
	int length;

	int Parent(int i);
	int Left(int i);
	int Right(int i);

	void Swap(int* a, int* b);

	void MaxHeapify(int* A, int i);
	void BuildMaxHeap(int* A);

	void MinHeapify(int* A, int i);
	void BuildMinHeap(int* A);

	void HeapSort(int* A);

	int HeapMaximum(int* A);
	int HeapExtractMax(int* A);
	void HeapIncreaseKey(int* A, int i, int k);
	void MaxHeapInsert(int* A, int k);

	int HeapMinimum(int* A);
	int HeapExtractMin(int* A);
	void HeapDecreaseKey(int* A, int i, int k);
	void MinHeapInsert(int* A, int k);


};
