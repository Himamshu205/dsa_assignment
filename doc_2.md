# Infix to Postfix Conversion and Evaluation

## (a) Data Structures Used
- **Character Stack**: Implemented using a character array to store operators and parentheses during infix to postfix conversion.
- **Integer Stack**: Implemented using an integer array to store operands while evaluating the postfix expression.

Both stacks use a simple array with a `top` index.

## (b) Functions Description
- **`prec(char c)`**  
  Returns the precedence of an operator (`+`, `-`, `*`, `/`).

- **`toPostfix(const char *in, char *out)`**  
  Converts the given infix expression into postfix form using a stack and operator precedence rules.

- **`evalPostfix(const char *p)`**  
  Evaluates the postfix expression by applying operators on operands popped from the stack.

## (c) Overview of `main()` Function
The `main()` function:
1. Reads the infix expression from the user.
2. Converts it to postfix using `toPostfix()`.
3. Evaluates the postfix expression using `evalPostfix()`.
4. Displays the postfix expression and the final result.

## (d) Sample Output
**Input**
(12+3)*4


**Output**
Postfix: 12 3 + 4 *
Result: 60