# Balanced Parentheses Checker (C – Stack Based)

## Overview
This program checks whether a mathematical expression contains a **balanced number of parentheses `()`** using a stack.  
It ignores all other characters and focuses only on parentheses order and count.

---

## Data Structure

### Stack
The stack is implemented using an array.

- `data[]` stores opening parentheses `'('`
- `top` tracks the index of the top element
- Follows **LIFO (Last In, First Out)** principle

---

## Function Descriptions

### `void init(Stack *s)`
Initializes the stack by setting `top = -1`.

---

### `int isEmpty(Stack *s)`
Checks whether the stack is empty.  
Returns `1` if empty, otherwise `0`.

---

### `void push(Stack *s, char ch)`
Pushes an opening parenthesis `'('` onto the stack.

---

### `char pop(Stack *s)`
Removes the top element from the stack.  
Used when a closing parenthesis `')'` is encountered.

---

### `int isBalanced(const char *expr)`
Checks whether the parentheses in the expression are balanced.

**Logic:**
- Push `'('` onto the stack
- Pop when `')'` is found
- If pop is attempted on an empty stack → not balanced
- Stack must be empty at the end

**Returns:**
- `1` → Balanced parentheses  
- `0` → Not balanced parentheses

---

## main() Overview
The `main()` function:
- Stores test expressions in an array
- Calls `isBalanced()` for each expression
- Prints whether the parentheses are balanced or not

---

## Sample Output

Expression: a + (b - c) * (d
Result: Not balanced parentheses

Expression: m + (a - b * (c + d * (m)))
Result: Balanced parentheses

Expression: a + (b - c)
Result: Balanced parentheses