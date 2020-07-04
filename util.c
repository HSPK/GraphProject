#include <stdio.h>
#include <stdlib.h>
#include "util.h"

int stoi(char *s)
{
    int ans = 0;
    int len = strle(s);
    //printf("%d\n", len);
    for (int i = 0; i < len; i++) {
        ans = ans * 10 + s[i] - '0';
    }
    return ans;
}

int strle(char *s)
{
    int i = 0;
    while(*s++ != '\0') {
        i++;
    }
    return i;
}

int strcmp(char *p, char *q) 
{
    char *a = p;
    char *b = q;
    while (!(*a - *b) && *b != '\0') {
        a++; b++;
    }
    return *a - *b;
}
