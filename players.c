/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U Operating Systems
 * Group 8
 * Copyright (C) 2025, <Mahnoor Jamal, George Kassar, Emilio Giron, Syed Mesam Jafri, Farzad Shahdad>
 * All rights reserved.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "players.h"

// Returns true if the player name matches one of the existing players
bool player_exists(player *players, int num_players, char *name)
{
    for (int i = 0; i < num_players; i++)
    {
        if (strcmp(players[i].name, name) == 0)
        {
            return true;
        }
    }
    return false;
}

// Go through the list of players and update the score for the
// player given their name
void update_score(player *players, int num_players, char *name, int score)
{
    for (int i = 0; i < num_players; i++)
    {
        if (strcmp(players[i].name, name) == 0)
        {
            players[i].score += score; // Update the player's score
            return;
        }
    }
    printf("Player not found.\n");
}