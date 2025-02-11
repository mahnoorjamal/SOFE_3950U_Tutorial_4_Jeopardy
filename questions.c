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

// Initializes the array of questions for the game
void initialize_game(void)
{
    // Example initialization of questions for each category
    // Programming questions
    strcpy(questions[0].category, "programming");
    strcpy(questions[0].question, "What is the name of the programming language created by Guido van Rossum?");
    strcpy(questions[0].answer, "Python");
    questions[0].value = 100;
    questions[0].answered = false;

    strcpy(questions[1].category, "programming");
    strcpy(questions[1].question, "What does the 'M' in MVC stand for?");
    strcpy(questions[1].answer, "Model");
    questions[1].value = 200;
    questions[1].answered = false;

    strcpy(questions[2].category, "programming");
    strcpy(questions[2].question, "What is the name of the JavaScript runtime built on Chrome's V8 engine?");
    strcpy(questions[2].answer, "Node.js");
    questions[2].value = 300;
    questions[2].answered = false;

    strcpy(questions[3].category, "programming");
    strcpy(questions[3].question, "What is the name of the version control system created by Linus Torvalds?");
    strcpy(questions[3].answer, "Git");
    questions[3].value = 400;
    questions[3].answered = false;

    // Algorithms questions
    strcpy(questions[4].category, "algorithms");
    strcpy(questions[4].question, "What is the time complexity of a binary search algorithm?");
    strcpy(questions[4].answer, "O(logn)");
    questions[4].value = 100;
    questions[4].answered = false;

    strcpy(questions[5].category, "algorithms");
    strcpy(questions[5].question, "What is the name of the algorithm used to find the shortest path in a graph?");
    strcpy(questions[5].answer, "Dijkstra");
    questions[5].value = 200;
    questions[5].answered = false;

    strcpy(questions[6].category, "algorithms");
    strcpy(questions[6].question, "What is the name of the sorting algorithm that uses a divide-and-conquer approach?");
    strcpy(questions[6].answer, "Merge");
    questions[6].value = 300;
    questions[6].answered = false;

    strcpy(questions[7].category, "algorithms");
    strcpy(questions[7].question, "What is the name of the algorithm used to solve the traveling salesman problem?");
    strcpy(questions[7].answer, "DP");
    questions[7].value = 400;
    questions[7].answered = false;

    // Databases questions
    strcpy(questions[8].category, "databases");
    strcpy(questions[8].question, "What is the name of the database language used to query and manipulate data?");
    strcpy(questions[8].answer, "SQL");
    questions[8].value = 100;
    questions[8].answered = false;

    strcpy(questions[9].category, "databases");
    strcpy(questions[9].question, "What is the name of the database model that uses tables to represent data?");
    strcpy(questions[9].answer, "Relational");
    questions[9].value = 200;
    questions[9].answered = false;

    strcpy(questions[10].category, "databases");
    strcpy(questions[10].question, "What is the name of the database system developed by Oracle Corporation?");
    strcpy(questions[10].answer, "Oracle");
    questions[10].value = 300;
    questions[10].answered = false;

    strcpy(questions[11].category, "databases");
    strcpy(questions[11].question, "What is the name of the NoSQL database that uses JSON-like documents?");
    strcpy(questions[11].answer, "MongoDB");
    questions[11].value = 400;
    questions[11].answered = false;
}

// Displays each of the remaining categories and question dollar values that have not been answered
void display_categories(void)
{
    printf("Available Categories and Questions:\n");
    for (int i = 0; i < NUM_CATEGORIES; i++)
    {
        printf("%s:\n", categories[i]);
        for (int j = 0; j < NUM_QUESTIONS / NUM_CATEGORIES; j++)
        {
            int index = i * (NUM_QUESTIONS / NUM_CATEGORIES) + j;
            if (!questions[index].answered)
            {
                printf("  $%d\n", questions[index].value);
            }
        }
    }
}

// Displays the question for the category and dollar value
void display_question(char *category, int value)
{
    for (int i = 0; i < NUM_QUESTIONS; i++)
    {
        if (strcmp(questions[i].category, category) == 0 && questions[i].value == value)
        {
            printf("Question: %s\n", questions[i].question);
            return;
        }
    }
    printf("Question not found.\n");
}

// Returns true if the answer is correct for the question for that category and dollar value
bool valid_answer(char *category, int value, char *answer)
{
    for (int i = 0; i < NUM_QUESTIONS; i++)
    {
        if (strcmp(questions[i].category, category) == 0 && questions[i].value == value)
        {
            // Remove "what is" or "who is" from the answer
            char *token = strtok(answer, " ");
            while (token != NULL)
            {
                if (strcmp(token, "is") == 0)
                {
                    token = strtok(NULL, " ");
                    if (token != NULL && strcmp(token, questions[i].answer) == 0)
                    {
                        return true;
                    }
                }
                else if (strcmp(token, questions[i].answer) == 0)
                {
                    return true;
                }
                token = strtok(NULL, " ");
            }
        }
    }
    return false;
}

// Returns true if the question has already been answered
bool already_answered(char *category, int value)
{
    for (int i = 0; i < NUM_QUESTIONS; i++)
    {
        if (strcmp(questions[i].category, category) == 0 && questions[i].value == value)
        {
            return questions[i].answered;
        }
    }
    return false;
}