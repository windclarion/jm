#ifndef __XTOOL_H__
#define __XTOOL_H__


#include <stddef.h>
#define JOIN_AGAIN(a, b) a##b
#define JOIN(a, b) JOIN_AGAIN(a,b)

#define STATIC_ASSERT(e) typedef char JOIN(assertion_failed_at_line_, __LINE__) [(e) ? 1 : -1] __attribute__((__unused__))
#define BUILD_BUG_ON(condition) ((void)sizeof(char[1 - 2 * !!(condition)]))

#define CASSERT(cond, msg)  typedef char msg[(cond) ? 1 : -1] __attribute__((__unused__))

#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))

#define XLOG_TO_STDOUT 1
#define XLOG_TO_STDERR 2

#ifndef XLOG_TARGET
#define XLOG_TARGET XLOG_TO_STDERR
#endif

#if XLOG_TARGET == XLOG_TO_STDOUT || XLOG_TARGET == XLOG_TO_STDERR
#include <stdio.h>

#if XLOG_TARGET == XLOG_TO_STDOUT
#define XLOG_STD_TARGET stdout
#else
#define XLOG_STD_TARGET stderr
#endif

#define XLOG_LEVEL_ERROR        1
#define XLOG_LEVEL_WARNING      2
#define XLOG_LEVEL_INFO         3
#define XLOG_LEVEL_DEBUG        4
#define XLOG_LEVEL_VERBOSE      5

#define XLOG_LEVEL XLOG_LEVEL_DEBUG

#define XLOGV(format, ...) if (XLOG_LEVEL >= XLOG_LEVEL_VERBOSE) fprintf(XLOG_STD_TARGET, "%s:%d: " format "\n", __func__, __LINE__, ## __VA_ARGS__)
#define XLOGD(format, ...) if (XLOG_LEVEL >= XLOG_LEVEL_DEBUG) fprintf(XLOG_STD_TARGET, "%s:%d: " format "\n", __func__, __LINE__, ## __VA_ARGS__)
#define XLOGI(format, ...) if (XLOG_LEVEL >= XLOG_LEVEL_INFO) fprintf(XLOG_STD_TARGET, "%s:%d: " format "\n", __func__, __LINE__, ## __VA_ARGS__)
#define XLOGW(format, ...) if (XLOG_LEVEL >= XLOG_LEVEL_WARNING) fprintf(XLOG_STD_TARGET, "%s:%d: warning! " format "\n", __func__, __LINE__, ## __VA_ARGS__)
#define XLOGE(format, ...) if (XLOG_LEVEL >= XLOG_LEVEL_ERROR) fprintf(XLOG_STD_TARGET, "%s:%d: error! " format "\n", __func__, __LINE__, ## __VA_ARGS__)

#define XELOGV(format, ...) if (XLOG_LEVEL >= XLOG_LEVEL_VERBOSE) fprintf(stderr, "%s:%d: " format "\n", __func__, __LINE__, ## __VA_ARGS__)
#define XELOGD(format, ...) if (XLOG_LEVEL >= XLOG_LEVEL_DEBUG) fprintf(stderr, "%s:%d: " format "\n", __func__, __LINE__, ## __VA_ARGS__)
#define XELOGI(format, ...) if (XLOG_LEVEL >= XLOG_LEVEL_INFO) fprintf(stderr, "%s:%d: " format "\n", __func__, __LINE__, ## __VA_ARGS__)
#define XELOGW(format, ...) if (XLOG_LEVEL >= XLOG_LEVEL_WARNING) fprintf(stderr, "%s:%d: warning! " format "\n", __func__, __LINE__, ## __VA_ARGS__)
#define XELOGE(format, ...) if (XLOG_LEVEL >= XLOG_LEVEL_ERROR) fprintf(stderr, "%s:%d: error! " format "\n", __func__, __LINE__, ## __VA_ARGS__)

#define XSLOGV(format, ...) if (XLOG_LEVEL >= XLOG_LEVEL_VERBOSE) fprintf(stdout, "%s:%d: " format "\n", __func__, __LINE__, ## __VA_ARGS__)
#define XSLOGD(format, ...) if (XLOG_LEVEL >= XLOG_LEVEL_DEBUG) fprintf(stdout, "%s:%d: " format "\n", __func__, __LINE__, ## __VA_ARGS__)
#define XSLOGI(format, ...) if (XLOG_LEVEL >= XLOG_LEVEL_INFO) fprintf(stdout, "%s:%d: " format "\n", __func__, __LINE__, ## __VA_ARGS__)
#define XSLOGW(format, ...) if (XLOG_LEVEL >= XLOG_LEVEL_WARNING) fprintf(stdout, "%s:%d: warning! " format "\n", __func__, __LINE__, ## __VA_ARGS__)
#define XSLOGE(format, ...) if (XLOG_LEVEL >= XLOG_LEVEL_ERROR) fprintf(stdout, "%s:%d: error! " format "\n", __func__, __LINE__, ## __VA_ARGS__)

#define ENTER(...) do { \
    if (XLOG_LEVEL_VERBOSE <= XLOG_LEVEL) { \
        fprintf(XLOG_STD_TARGET, "%s:%d: enter.", __func__, __LINE__); \
        fprintf(XLOG_STD_TARGET, " " __VA_ARGS__); \
        fprintf(XLOG_STD_TARGET, "\n"); \
    } \
} while(0)

#define LEAVE(...) do { \
    if (XLOG_LEVEL_VERBOSE <= XLOG_LEVEL) { \
        fprintf(XLOG_STD_TARGET, "%s:%d: leave.", __func__, __LINE__); \
        fprintf(XLOG_STD_TARGET, " " __VA_ARGS__); \
        fprintf(XLOG_STD_TARGET, "\n"); \
    } \
} while(0)

#endif


void display_binary(const void *data, size_t len);
void display_int(int x);
void display_int_array(int x[], size_t sz);

char* lstrip(char *s);
char* rstrip(char *s);
char* strip(char *s);

#endif  /* __XTOOL_H__ */

