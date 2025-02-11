/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U Operating Systems
 * Group 8
 * Copyright (C) 2025, <Mahnoor Jamal, George Kassar, Emilio Giron, Syed Mesam Jafri, Farzad Shahdad>
 * All rights reserved.
 *
 */
#ifndef JEOPARDY_H_
#define JEOPARDY_H_

#define MAX_LEN 256

// Processes the answer from the user containing what is or who is and tokenizes it to retrieve the answer.
extern void tokenize(char *input, char **tokens);

// Displays the game results for each player, their name and final score, ranked from first to last place
extern void show_results(player *players, int num_players);

#endif /* JEOPARDY_H_ */