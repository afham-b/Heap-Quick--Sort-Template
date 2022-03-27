#pragma once

#include <algorithm>

// sort_compare - Standard sort comparison function
//	Parameters: a, b - values of type T which is less-than comparable
//	Returns: true if a < b, false otherwise
template <typename T>
inline bool sort_compare (const T& a, const T& b) { return a < b; }

// sort_partition - Partition an array segment according to pivot value
//	Parameters:
//		a - an array of an arbitrary type T
//		low - low index of segment
//		high - low index of segment
//		pivot = index of partition value
//		cmp - comparison function or function object for comparing type T
template <typename T, typename U>
size_t sort_partition (T a[], size_t low, size_t high, size_t pivot, U cmp) {
	int pivot_value = a[pivot];
	std::swap(a[pivot], a[high]);
	pivot = low;
	for (size_t i = low; i < high; i++) {
		if (cmp(a[i], pivot_value))
			std::swap(a[i], a[pivot++]);
	}
	std::swap(a[pivot], a[high]);
	return pivot;
}

// sort - Quicksort, array segment
//	Parameters:
//		a - an array of an arbitrary type T
//		low - low index of segment
//		high - low index of segment
//		cmp - comparison function or function object for comparing type T
template <typename T, typename U>
void sort (T a[], size_t low, size_t high, U cmp) {
	if (low < high) {
		size_t pivot = (low + high) / 2;
		pivot = sort_partition(a, low, high, pivot, cmp);
		if (pivot > low)
			sort(a, low, pivot - 1, cmp);
		if (pivot < high)
			sort(a, pivot + 1, high, cmp);
	}
}

// sort - Quicksort
//	Parameters:
//		a - an array of an arbitrary type T
//		n - size of array a
//		cmp - comparison function or function object for comparing type T
template <typename T, typename U>
void sort (T a[], size_t n, U cmp) { sort(a, 0, n - 1, cmp); }

// sort - Quicksort using sort_compare as the comparison function
template <typename T>
void sort (T a[], size_t n) { sort(a, n, sort_compare<T>); }