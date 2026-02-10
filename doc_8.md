# Sorting Random Integers (Short Version)

## Data Structure
Dynamic integer array `a[]` is created using `malloc()` to store N random values in [1,1000].

## Functions Implemented
- `cmpCount()` : comparison function for `qsort()` and counts total comparisons.
- `printSmart()` : prints full array if N <= 100, else prints first 50 and last 50.

## main() Overview
`main()`:
1. Reads N
2. Generates N random numbers
3. Prints array before sorting
4. Sorts using `qsort()`
5. Prints sorted array and total comparisons

## Sample Output
Enter N: 10

Before:
512 44 901 12 77 300 2 999 18 605

After:
2 12 18 44 77 300 512 605 901 999

Total Comparisons: 25
Swaps/Moves: N/A (qsort)