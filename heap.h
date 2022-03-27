#pragma once

#include <algorithm>

// sort_compare - Standard sort comparison function
//	Parameters: a, b - values of type T which is less-than comparable
//	Returns: true if a < b, false otherwise
template <typename T>
inline bool sort_compare (const T& a, const T& b) { return a < b; }

inline size_t left (size_t i) { return i * 2 + 1; }
inline size_t right (size_t i) { return i * 2 + 2; }

// heapify - Heapify a sub-tree rooted at node i
//	Parameters
//		a - an array of an arbitrary type T
//		n - size of array a
//		i - an index in array a
//		cmp - comparison function or function object for comparing type T
template <typename T, typename U>
void heapify (T a[], size_t n, size_t i, U cmp) {
	size_t l = 2 * i + 1; // Left child of i
	size_t r = 2 * i + 2; // Right child of i
	size_t max = i; // Initialize index of max element of i, l, and r
	// Determine max
	if (l < n && cmp(a[max], a[l]))
		max = l;
	if (r < n && cmp(a[max], a[r]))
		max = r;
	// Swap and heapify affected sub-tree
	if (max != i) {
		std::swap(a[i], a[max]);
		heapify(a, n, max, cmp);
	}
}

// sort - Heap sort
//	Parameters:
//		a - an array of an arbitrary type T
//		n - size of array a
//		cmp - comparison function or function object for comparing type T
template <typename T, typename U>
void sort (T a[], size_t n, U cmp) {
	// Build a heap
	for (size_t i = n / 2 - 1; i < n; i--)
		heapify(a, n, i, cmp);
	// Sort the array
	for (size_t i = n - 1; i < n; i--) {
		std::swap(a[0], a[i]);
		heapify(a, i, 0, cmp);
	}
}

// sort - Heap sort using sort_compare as the comparison function
template <typename T>
void sort (T a[], size_t n) { sort(a, n, sort_compare<T>); }