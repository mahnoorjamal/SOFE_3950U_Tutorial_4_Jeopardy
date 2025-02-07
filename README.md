# SOFE_3950U_Tutorial_4_Jeopardy
# Tutorial 4 - Group 8

**Group Members:**
- Mahnoor Jamal - 100822030
- George Kassar - 100872343
- Emilio Giron - 100783207
- Syed Mesam Jafri - 100869437
- Farzad Shahdad - 100861389

---

## Jeopardy Game Project

This project is a command-line implementation of the popular game show Jeopardy. It supports up to four players and allows them to select categories, answer questions, and accumulate scores. The game ends when all questions have been answered, and the final results are displayed.

---

## How to Compile and Run the Code

### Compiling with Makefile
1. Ensure you have `make` and `gcc` installed on your system.
2. Open a terminal and navigate to the project directory.
3. Run the following command to compile the code:

make

4. Run the executable:

./jeopardy.exe


### Compiling Without Makefile
1. Ensure you have `gcc` installed on your system.
2. Open a terminal and navigate to the project directory.
3. Compile the source files using the following commands:

gcc -Wall -Wextra -std=c99 -c jeopardy.c -o jeopardy.o
gcc -Wall -Wextra -std=c99 -c questions.c -o questions.o
gcc -Wall -Wextra -std=c99 -c players.c -o players.o
gcc jeopardy.o questions.o players.o -o jeopardy.exe

4. Run the executable:

./jeopardy.exe


---

## How to Play the Game

1. **Start the Game**:
- Run the executable (`./jeopardy.exe`).
- The game will display a welcome message and prompt you to enter the names of up to four players.

2. **Enter Player Names**:
- Enter the names of the players when prompted.

3. **Select a Question**:
- The game will display the available categories and their corresponding dollar values.
- Enter the name of the player who will select the question.
- Enter the category and the dollar value of the question you want to answer.

4. **Answer the Question**:
- The game will display the selected question.
- Enter your answer in the format:
  - `what is [answer]` or `who is [answer]` (e.g., `what is Python`).
  - Alternatively, you can just enter the answer (e.g., `Python`).

5. **Score Updates**:
- If the answer is correct, the player's score will be updated.
- If the answer is incorrect, the correct answer will be displayed.

6. **Continue Playing**:
- The game will repeat the process until all questions have been answered.

7. **Final Results**:
- Once all questions are answered, the game will display the final results, ranking the players from first to last place based on their scores.

---

## Description of Functions

### `questions.c`
- **`initialize_game`**:
- Initializes the array of questions for the game. Each question is assigned a category, question text, answer, dollar value, and a flag to track if it has been answered.

- **`display_categories`**:
- Displays the available categories and the dollar values of unanswered questions.

- **`display_question`**:
- Displays the question for the selected category and dollar value.

- **`valid_answer`**:
- Validates the player's answer by comparing it to the correct answer for the selected question.

- **`already_answered`**:
- Checks if a question has already been answered.

### `players.c`
- **`player_exists`**:
- Checks if a player with the given name exists in the list of players.

- **`update_score`**:
- Updates the score of the player with the given name.

### `jeopardy.c`
- **`tokenize`**:
- Tokenizes the player's answer to extract the actual answer (e.g., `what is Python` → `Python`).

- **`show_results`**:
- Displays the final results of the game, ranking players by their scores.

- **`main`**:
- The main function that runs the game loop, handles player input, and manages the flow of the game.

---

## Project Structure
- **`jeopardy.c`**: Contains the main game logic and functions for handling player input and displaying results.
- **`questions.c`**: Contains functions for managing questions, categories, and answers.
- **`players.c`**: Contains functions for managing player data and scores.
- **`questions.h`**: Header file for `questions.c`.
- **`players.h`**: Header file for `players.c`.
- **`jeopardy.h`**: Header file for `jeopardy.c`.
- **`Makefile`**: Automates the compilation process.

---

## Notes
- Ensure all source files (`jeopardy.c`, `questions.c`, `players.c`) and header files (`questions.h`, `players.h`, `jeopardy.h`) are in the same directory before compiling.
- The game is designed to be played in a terminal or command prompt.

---

Enjoy playing Jeopardy!
