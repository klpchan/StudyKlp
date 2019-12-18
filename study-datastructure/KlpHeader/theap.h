#pragma once
#define SYMBOL  <
#define ANTISYMBOL >
#define MAX_HEAP_SIZE 10
int heap[MAX_HEAP_SIZE + 1] = {0};// idx from 1 to 10
int heapsize = 0;

//int heapcmp(int id1, int id2) {
//	return id1 - id2;
//}

void siftDown(int(*cmp)(int, int)) {
	int cur = 1;
	int pos = cur;
	while (1)
	{
		int l = cur << 1; // cur * 2
		int r = l + 1;
		if (l <= heapsize && cmp(heap[l], heap[pos]) SYMBOL 0) pos = l; // l <= heapsize
		if (r <= heapsize && cmp(heap[r], heap[pos]) SYMBOL 0) pos = r; // r <= heapsize
		if (cur != pos) {
			int tmp = heap[cur];
			heap[cur] = heap[pos];
			heap[pos] = tmp;
			cur = pos;
		}
		else
		{
			break;
		}
	}
}

void siftUp(int val, int(*cmp)(int,int)) {
	heap[++heapsize] = val;
	int cur = heapsize;
	int par = cur >> 1;
	while (par) {
		if (cmp(heap[cur], heap[par]) SYMBOL 0) {
			int tmp = heap[cur];
			heap[cur] = heap[par];
			heap[par] = tmp;
			cur = par;
			par = par >> 1;
		}
		else {
			break;
		}
	}
}

void tryPutToHeap(int tweetId,int(*cmp)(int,int)) {
	if (heapsize < MAX_HEAP_SIZE) {
		siftUp(tweetId,cmp);
	} else {
		if (cmp(tweetId, heap[1]) ANTISYMBOL 0) {
			heap[1] = tweetId;
			siftDown(cmp);
		}
	}
}

int deleteTop(int(*cmp)(int,int)) {
	int id = heap[1];
	heap[1] = heap[heapsize--];
	siftDown(cmp);
	return id;
}
