# Set 7: Final Course Projects (Capstone)

This folder contains the **Capstone Projects** for the Algorithms & Problem-Solving Level 2 course. These projects represent complete software systems that integrate **Modular Programming**, **Structs**, **Enums**, and the custom **`MyLib`** library.

## Project List

| #   | Project Name            | Description                                                                                     | Key Concepts                                                    | Status    |
| --- | ----------------------- | ----------------------------------------------------------------------------------------------- | --------------------------------------------------------------- | --------- |
| 1   | **Stone-Paper-Scissor** | A fully functional console game with rounds, scoring, and dynamic UI colors.                    | `Structs Data Flow`, `State Management`, `Dynamic UI`           | Completed |
| 2   | **Math Quiz Game**      | An educational game with variable difficulty levels, operation types, and smart division logic. | `Struct Composition`, `Reverse Logic (Math)`, `Flag Management` | Completed |

## Key Technical Concepts

- **Struct-Based Data Flow:** Passing complex game states (like `stRoundInfo` and `stQuizz`) between functions efficiently instead of using global variables.
- **Smart Math Logic:** Implementing "Reverse Multiplication" to generate integer-only Division questions dynamically.
- **Dynamic UI Control:** Changing console colors dynamically based on game events (Red for Wrong, Green for Right) using `system("color ...")`.
- **Modular Architecture:** Breaking down the game loop into independent, testable functions (`StartGame`, `PlayGame`, `Generate_Question`).
- **Library Integration:** Heavy reliance on `MyLib` for input validation (`Read_Number`) and secure random number generation (`srand`).
