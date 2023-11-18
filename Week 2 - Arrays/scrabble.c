#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    if (score1 > score2) {
        printf("Player 1 wins!\n");
    }
    if (score1 < score2) {
        printf("Player 2 wins!\n");
    }
    if (score1 == score2) {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    //     char arr[26];
    //     for (int i = 0; i < strlen(word); i++) {

    //         char letter = word[i];
    //         {
    //             for (int j = 0; j < 26; j++)
    //             {
    //                 if (letter == (arr[j] = 'A'+j))
    //                 {
    //                 printf("arr[%d] = %c\n", j, arr[j]);
    //                 }
    //             }
    //         }
    //     }

    int sum = 0;
    int index;

    for (int i = 0; i < strlen(word); i++)
    {
        char letter = toupper(word[i]);

        if (letter >= 65 && letter <= 90)
        {
            index = letter - 'A';
            sum = sum + POINTS[index];
        }
        else
        {
            sum = sum + 0;
        }
    }

    return sum;
}