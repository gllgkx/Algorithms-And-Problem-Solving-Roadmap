# Set 7: Final Course Projects (Capstone)

This folder contains the **Capstone Projects** for the Algorithms & Problem-Solving Level 2 course. These projects represent complete software systems that integrate **Modular Programming**, **Structs**, **Enums**, and the custom **`MyLib`** library.

## Project List

| # | Project Name | Description | Key Concepts | Status |
|---|---|---|---|---|
| 1 | **Stone-Paper-Scissor** | A fully functional console game with rounds, scoring, and dynamic UI colors. | `Structs Data Flow`, `State Management`, `Dynamic UI` | Completed |
| 2 | **Math Quiz Game** | An educational game with variable difficulty levels and operation types. | `Logic Building`, `Random Question Gen` |  In Progress |

## Key Technical Concepts
* **Struct-Based Data Flow:** Passing complex game states (like `stRoundInfo` and `stGameResults`) between functions efficiently instead of using global variables.
* **Dynamic UI Control:** Changing console colors dynamically based on game events (Red for loss, Green for win) using `system("color ...")`.
* **Modular Architecture:** Breaking down the game loop into independent, testable functions (`StartGame`, `PlayGame`, `WhoWonRound`).

* **Library Integration:** Heavy reliance on `MyLib` for input validation (`Read_Number`) and secure random number generation (`srand`).
