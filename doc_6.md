# Build Min Heap and Max Heap from an Unsorted Array

## Data Structure
The heap is stored in an array.
For an element at index `i`:
- Left child = `2*i + 1`
- Right child = `2*i + 2`
- Parent = `(i - 1) / 2`

## Functions Implemented
- `swap()` : swaps two integers.
- `maxHeapify()` : fixes max-heap property at index `i`.
- `buildMaxHeap()` : builds a max heap by calling heapify from last non-leaf to root.
- `minHeapify()` : fixes min-heap property at index `i`.
- `buildMinHeap()` : builds a min heap similarly.
- `printArray()` : prints the heap array.
- `copyArray()` : copies original array so we can build both heaps separately.

## main() Overview
The `main()` function:
1. Creates an unsorted array
2. Copies it into two arrays
3. Builds a max heap from one copy and a min heap from the other
4. Prints the results

## Sample Output
Original Array: 3 5 1 10 2 7 6 4
Max Heap Array: 10 5 7 4 2 1 6 3
Min Heap Array: 1 2 3 4 5 7 6 10
