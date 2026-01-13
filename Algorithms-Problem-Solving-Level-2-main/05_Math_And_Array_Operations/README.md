# Set 5: More Array Problems & Math Functions (Problems 41-50)

This folder focuses on **Array Validation** and the manual implementation of standard **Mathematical Functions**. The goal is to understand the internal logic of functions like `sqrt`, `round`, and `floor` without relying on built-in libraries.

## Problem List

| # | Problem Name | Description | Key Concepts |
|---|---|---|---|
| 41 | **Is Palindrome Array** | Checks if an array reads the same forwards and backwards. | `Palindrome Logic`, `Loop Optimization (N/2)` |
| 42 | **Count Odd Numbers** | Counts the number of odd integers in an array. | `Modulo Operator`, `Counters` |
| 43 | **Count Even Numbers** | Counts the number of even integers in an array. | `Modulo Operator`, `Counters` |
| 44 | **Count Positive Numbers** | Counts numbers greater than zero. | `Conditional Logic`, `Counters` |
| 45 | **Count Negative Numbers** | Counts numbers less than zero. | `Conditional Logic`, `Counters` |
| 46 | **My ABS** | Recreates the Absolute Value function manually. | `Math Logic`, `Negation` |
| 47 | **My Round** | Recreates the standard Round function. | `Type Casting`, `Math Logic (+0.5)` |
| 48 | **My Floor** | Recreates the Floor function (rounds down). | `Edge Cases`, `Negative Number Logic` |
| 49 | **My Ceil** | Recreates the Ceil function (rounds up). | `Edge Cases`, `Type Casting` |
| 50 | **My Sqrt** | Calculates Square Root using the Babylonian Method. | `Algorithms`, `Iterative Approximation` |

## Key Technical Concepts
* **Loop Optimization:** In the Palindrome problem, the loop runs only up to `Length / 2` to save performance.
* **Math Algorithms:** Implementing complex math logic manually (e.g., **Babylonian Method** for Square Root).
* **Edge Case Handling:** Specifically handling negative numbers in `Floor` and `Ceil` functions to match standard behavior.
* **Reinventing the Wheel:** Re-coding standard library functions (`<cmath>`) to master the underlying logic.