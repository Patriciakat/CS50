﻿#include <cs50.h>
#include <stdio.h>
#include <string.h>

#define MAX 9

typedef struct
{
    string name;
    int votes;
} candidate;

candidate candidates[MAX];

int candidate_count;

bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }
    print_winner();
}

bool vote(string name)
{
    for (int i = 0; i < candidate_count; i++) {

        if (strcmp(name, candidates[i].name) == 0) {
            candidates[i].votes = candidates[i].votes + 1;
            return true;
        }
    }

    return false;
}

// Sorted winner of the election using SIMPLE SORTING ALGORITHM
void print_winner(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i +1; j < candidate_count; j++)
        {
            if (candidates[i].votes > candidates[j].votes)
            {
                int temp = candidates[i].votes;
                string temp1 = candidates[i].name;
                candidates[i].votes = candidates[j].votes;
                candidates[i].name = candidates[j].name;
                candidates[j].votes = temp;
                candidates[j].name = temp1;
            }
        }
    }
    printf("The WINNER is: %s\n", candidates[candidate_count - 1].name);
    return;
}
