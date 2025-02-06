/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <GROUP MEMBERS>
 * All rights reserved.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "questions.h"
#include "players.h"
#include "jeopardy.h"

// Put macros or constants here using #define
#define BUFFER_LEN 256
#define NUM_PLAYERS 4

// Processes the answer from the user containing what is or who is and tokenizes it to retrieve the answer.
void tokenize(char *input, char **tokens)
{
    char *token = strtok(input, " ");
    int i = 0;
    while (token != NULL && i < 3)
    {
        tokens[i] = token;
        token = strtok(NULL, " ");
        i++;
    }
}

// Displays the game results for each player, their name and final score, ranked from first to last place
void show_results(player *players, int num_players)
{
    // Simple bubble sort to rank players by score
    for (int i = 0; i < num_players - 1; i++)
    {
        for (int j = 0; j < num_players - i - 1; j++)
        {
            if (players[j].score < players[j + 1].score)
            {
                player temp = players[j];
                players[j] = players[j + 1];
                players[j + 1] = temp;
            }
        }
    }

    // Display results
    printf("\nGame Results:\n");
    for (int i = 0; i < num_players; i++)
    {
        printf("%d. %s: $%d\n", i + 1, players[i].name, players[i].score);
    }
}

int main(int argc, char *argv[])
{
    // An array of 4 players
    player players[NUM_PLAYERS];
    int num_players = NUM_PLAYERS;

    // Input buffer and commands
    char buffer[BUFFER_LEN] = {0};

    // Display the game introduction and initialize the questions
    printf("Welcome to Jeopardy!\n");
    initialize_game();

    // Prompt for players' names
    for (int i = 0; i < NUM_PLAYERS; i++)
    {
        printf("Enter player %d's name: ", i + 1);
        fgets(buffer, BUFFER_LEN, stdin);
        buffer[strcspn(buffer, "\n")] = '\0'; // Remove newline character
        strcpy(players[i].name, buffer);
        players[i].score = 0; // Initialize score to 0
    }

    // Perform an infinite loop getting command input from users until game ends
    while (true)
    {
        // Display categories and questions
        display_categories();

        // Prompt for the player's name
        printf("Enter the name of the player selecting the question: ");
        fgets(buffer, BUFFER_LEN, stdin);
        buffer[strcspn(buffer, "\n")] = '\0'; // Remove newline character

        // Store the player's name
        char player_name[MAX_LEN];
        strcpy(player_name, buffer);

        // Validate the player's name
        if (!player_exists(players, num_players, player_name))
        {
            printf("Invalid player name. Try again.\n");
            continue;
        }

        // Prompt for the category and value
        char category[MAX_LEN];
        int value;
        printf("Enter the category: ");
        fgets(category, MAX_LEN, stdin);
        category[strcspn(category, "\n")] = '\0'; // Remove newline character

        printf("Enter the question value: ");
        fgets(buffer, BUFFER_LEN, stdin);
        value = atoi(buffer);

        // Check if the question has already been answered
        if (already_answered(category, value))
        {
            printf("This question has already been answered. Choose another.\n");
            continue;
        }

        // Display the question
        display_question(category, value);

        // Prompt for the answer
        printf("Enter your answer (start with 'what is' or 'who is'): ");
        fgets(buffer, BUFFER_LEN, stdin);
        buffer[strcspn(buffer, "\n")] = '\0'; // Remove newline character

        // Validate the answer
        if (valid_answer(category, value, buffer))
        {
            printf("Correct!\n");
            update_score(players, num_players, player_name, value); // Pass the player's name, not the buffer
        }
        else
        {
            for (int i = 0; i < NUM_QUESTIONS; i++)
            {
                if (strcmp(questions[i].category, category) == 0 && questions[i].value == value)
                {
                    printf("Incorrect. The correct answer is: %s\n", questions[i].answer);
                    break;
                }
            }
        }

        // Mark the question as answered
        for (int i = 0; i < NUM_QUESTIONS; i++)
        {
            if (strcmp(questions[i].category, category) == 0 && questions[i].value == value)
            {
                questions[i].answered = true;
                break;
            }
        }

        // Check if all questions have been answered
        bool all_answered = true;
        for (int i = 0; i < NUM_QUESTIONS; i++)
        {
            if (!questions[i].answered)
            {
                all_answered = false;
                break;
            }
        }

        if (all_answered)
        {
            break; // End the game
        }
    }

    // Display the final results and exit
    show_results(players, num_players);
    return EXIT_SUCCESS;
}