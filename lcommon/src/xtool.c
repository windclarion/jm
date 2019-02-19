#include <stdio.h>

#include <xtool.h>

#define BYTE_COUNT_EACH_LINE    16

//display binary data
static const char hex[] = "0123456789ABCDEF";
static const char seperator = ',';
static const char prefix[] = "0x";

void display_binary(const void* data, size_t len)
{
    const unsigned char *p = (const unsigned char *)data;
    char stash[BYTE_COUNT_EACH_LINE*(2 + sizeof(seperator) + sizeof(prefix) - 1)];

    int j = 0;
    for (int i = 0; i < (int)len; i++) {
        for (int k = 0; k < (int)sizeof(prefix) - 1; k++) {
            stash[j++] = prefix[k];
        }
        stash[j++] = hex[(p[i] >> 4) & 0xF];
        stash[j++] = hex[p[i] & 0xF];
        stash[j++] = seperator;
        if (j == sizeof(stash)) {
            stash[j-1] = '\0';
            fprintf(XLOG_STD_TARGET, "%s\n", stash);
            j = 0;
        }
    }
    if (j) {
        stash[j-1] = '\0';
        fprintf(XLOG_STD_TARGET, "%s\n", stash);
    }
    fprintf(XLOG_STD_TARGET, "\n");
}

#define INT_COUNT_EACH_LINE     4

void display_int(int x)
{
    fprintf(XLOG_STD_TARGET, "0x%X\n", x);
}

void display_int_array(int x[], size_t sz)
{
    for (int i = 0; i < (int)sz; i++) {
        fprintf(XLOG_STD_TARGET, "%s%X%c", prefix, x[i], seperator);
        if (i % INT_COUNT_EACH_LINE == INT_COUNT_EACH_LINE - 1) fprintf(XLOG_STD_TARGET, "\n");
    }
    if (sz % INT_COUNT_EACH_LINE != 0) fprintf(XLOG_STD_TARGET, "\n\n");
    else fprintf(XLOG_STD_TARGET, "\n");
}

char* lstrip(char *s)
{
    char *p = s;
    while (*p == ' ' || *p == '\t')
        p++;
    return p;
}

char* rstrip(char *s)
{
    char *p = s;
    while (*p) {
        p++;
    }
    p--;
    while (p >= s) {
        if (*p == ' ' || *p == '\t' || *p == '\n') --p;
        else break;
    }
    *++p = '\0';
    return s;
}

char* strip(char *s)
{
    return rstrip(lstrip(s));
}