#include <stdio.h>
#include <string.h>
#include "textFind.h"

int main()
{
    char searchWord[WORD];
    char option[WORD];

    getWord(searchWord);
    getWord(option);
    if (strcmp(option, "a") == 0)
    {
        print_lines(searchWord);
    }
    else
    {
        print_similar_words(searchWord);
    }
}