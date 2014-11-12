/**
 * by Jaroslaw Hirniak
 * 11 November 2014
 */

#define DEBUG

#include "pq.h"
#include <vector>
#include <limits>

#include <iterator>
#include <iostream>

using namespace std;

template<typename T>
void PQ<T>::insert(T item) {
  heap.push_back(item);
  upheap(size());
}

template<typename T>
T PQ<T>::remove() {
  T val = heap[1];
  heap[1] = heap[size()];
  downheap(1);
  return val;
}

template<typename T>
T PQ<T>::replace(T item) {
  heap[0] = item;
  downheap(0);
  T val = heap[0];
  heap[0] = numeric_limits<T>::max();
  return val;
}

template<typename T>
vector<T> PQ<T>::heapsort(vector<T> &items) {
  items.insert(items.begin(), numeric_limits<T>::max());

  for (size_t k = items.size()/2; k >= 1; --k) {
    downheap(items, k);
  }

  size_t N = items.size() - 1;
  while (N > 1) {
    T temp = items[1];
    items[1] = items[N];
    items[N] = temp;
    downheap(items, --N, 1);
  }

  items.erase(items.begin());

  return items;
}

template<typename T>
void PQ<T>::upheap(int k) {
  T val = heap[k];
  heap[0] = numeric_limits<T>::max();

  while (heap[k/2] < val) {
    heap[k] = heap[k/2];
    k /= 2;
  }

  heap[k] = val;
}

template<typename T>
void PQ<T>::downheap(vector<T> &items, size_t N, size_t k) {
  T val = items[k];

  while (k <= N / 2) {
    size_t j = 2*k;

    if (j < N && items[j] < items[j+1]) {
      ++j;
    }

    if (val >= items[j]) {
      break;
    }

    items[k] = items[j];
    k = j;
  }

  items[k] = val;
}

template<typename T>
void PQ<T>::downheap(vector<T> &items, size_t k) {
  downheap(items, items.size() - 1, k);
}

template<typename T>
void PQ<T>::downheap(int k) {
  downheap(heap, size(), k);
}

#ifdef DEBUG

template<typename T>
void printVector(vector<T> v) {
  typename vector<T>::iterator it;
  cout << "{ ";
  for(it = v.begin(); it != v.end(); ++it) {
    cout << *it;
    if (it != prev(v.end())) {
      cout << ", ";
    }
  }
  cout << " }" << endl;
}

int main() {
  vector<int> v0 { 9, 5, 1, 3, 4, 7, 5, 2, 6, 8, 0 };
  PQ<int>* pq = new PQ<int>();
  printVector(v0);
  pq->heapsort(v0);
  printVector(v0);
}

#endif

#ifndef DEBUG
int main() {
}
#endif
