// a program that calculates the approximate grade level needed to comprehend some text

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text:\n");

    int words = count_words(text);

    double L = (double) count_letters(text) / (double) words * 100;
    double S = (double) count_sentences(text) / (double) words * 100;

    double index = 0.0588 * L - 0.296 * S - 15.8;

    if (index < 1) {
        printf("Before Grade 1\n");
    }
    else if (index >= 16) {
        printf("Grade 16+\n");
    }
    else {
        printf("Grade: %0.f\n", index);
    }
}

int count_letters(string text) {

    int letters = 0;
    int current;

    for (int i = 0; i < strlen(text); i++)
    {
        current = text[i];

        if (isalpha(current))
        {
            letters++;
        }
    }

    return letters;
}

int count_words(string text) {

    int words = 1;
    int current;

    for (int i = 0; i <= strlen(text); i++)
    {
        current = text[i];

        if (current == 32)
        {
            words++;
        }
    }

    return words;
}

int count_sentences(string text) {

    int sentence = 0;
    int current;

    for (int i = 0; i <= strlen(text); i++)
    {
        current = text[i];

        if (current == 46 || current == 33 || current == 63)
        {
            sentence++;
        }
    }

    return sentence;
}