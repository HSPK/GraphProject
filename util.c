#include <stdio.h>
#include <stdlib.h>
#include "util.h"

void *reverse(char *s, int i, int j)
{
    char temp;
    char *p = s + i;
    char *q = s + j;
    while (p < q) {
        temp = *p;
        *p = *q;
        *q = temp;
        p++; q--;
    }
}

char *itos(int i)
{
    char *s = (char *)malloc(sizeof(char) * MAX_STR_LEN);
    int j = 0;
    if (i == 0) {
        s[0] = '0';
        s[1] = '\0';
        return s;
    }
    while (i != 0)
    {
        s[j++] = i % 10 + '0';
        i /= 10;
    }
    s[j] = '\0';
    return s;
}

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
