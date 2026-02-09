# Doubly Linked List (Insert After + Delete)

## Data Structure
A doubly linked list is used. Each node contains:
- `data` (integer)
- `prev` pointer (previous node)
- `next` pointer (next node)

## Functions Implemented
- `createNode()` : Allocates and initializes a new node.
- `insertEnd()` : Adds a node at the end (used to build a sample list).
- `displayForward()` : Prints the list from head to tail.
- `findNode()` : Finds a node by value (returns pointer to that node).
- `insertAfter()` : Inserts a new node after a given node pointer.
- `deleteValue()` : Deletes the first node that matches a given value.

## main() Overview
The `main()` function:
1. Creates a doubly linked list (10, 20, 30)
2. Inserts 25 after 20
3. Deletes the node with value 10
4. Prints the list after each operation

## Sample Output
Initial List: 10 <-> 20 <-> 30 <-> NULL
After insertAfter(20, 25): 10 <-> 20 <-> 25 <-> 30 <-> NULL
After deleteValue(10): 20 <-> 25 <-> 30 <-> NULL

