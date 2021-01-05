#include <stdio.h>
#include <string.h>
#include "textFind.h"

int getLine(char s[])
{
    memset(s, 0, LINE);
    char c = getchar();

    while (c=='\n')
        c=getchar();

    for (int i = 0; i < LINE; i++, c = getchar())
    {
        if (c != EOF && c != '\n')
            s[i] = c;
        else
            break;
    }
    return strlen(s);
}

int getWord(char w[])
{
    memset(w, 0, WORD);
    char c = getchar();

    while (c==' '|| c=='\r' || c=='\n'|| c=='\t')
        c=getchar();

    for (int i = 0; i < WORD; i++, c = getchar())
    {
        if (c != EOF && c != '\n' && c != '\t' && c != ' ' && c != '\r')
            w[i] = c;
        else
            break;
        
    }
    return strlen(w);
}

int substring(char *str1, char *str2)
{
    char *search;
    search = strstr(str1, str2);

    if (search == NULL)
        return 0;
    else
        return 1;
}

int similar(char *s, char *t, int n)
{
    if (strcmp(s, t) == 0)
        return 1;

    int sLen = strlen(s);
    int tLen = strlen(t);
    int newSize = sLen - n;
    if (newSize != tLen)
        return 0;

    char check[newSize];

    int i = 0, j = 0, mistakes = 0;

    while (mistakes <= n && i < sLen && j < tLen)
    {
        if (s[i] != t[j])
        {
            mistakes++;
            i++;
        }
        else
        {
            check[j] = t[j];
            i++;
            j++;
        }
    }
    if (strcmp(t, check) == 0)
        return 1;
    else
        return 0;
}

void print_lines(char *str)
{
    char line[LINE];
    int len = getLine(line);

    while (len != 0)
    {
        int check = substring(line, str);
        if (check == 1)
        {
            printf("%s\n", line);
        }
        len = getLine(line);
    }
}

void print_similar_words(char *str)
{
    char word[WORD];
    int len = getWord(word);
        
    while (len != 0)
    {
        int check = similar(word, str, 1);
        if (check == 1)
            printf("%s\n", word);
        len = getWord(word);
    }
}