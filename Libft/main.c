#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h>

// Colors for printf
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define RESET   "\033[0m"

static void test_ft_atoi(void)
{
    printf(YELLOW "\nTESTING ft_atoi():\n" RESET);

    struct {
        char *input;
        const int expected;
    } test_cases[] = {
        {"0", 0},
        {"123", 123},
        {"-456", -456},
        {"2147483647", 2147483647},  // INT_MAX
        {"-2147483648", -2147483648}, // INT_MIN
        {"42", 42},
        {"-99", -99}
    };

    int passed = 0;
    int total = sizeof(test_cases) / sizeof(test_cases[0]);

    for (int i = 0; i < total; i++)
    {
        int result = ft_atoi(test_cases[i].input);
        printf("Test %d: ft_atoi(%s) -> ", i + 1, test_cases[i].input);
        
        if (result == test_cases[i].expected)
        {
            printf(GREEN "PASS: \"%d\"\n" RESET, result);
            passed++;
        }
        else
        {
            printf(RED "FAIL: got \"%d\", expected \"%d\"\n" RESET, result, test_cases[i].expected);
        }
    }

    printf("Summary: %d/%d " GREEN "PASSED" RESET "\n", passed, total);
}

void test_ft_isalpha(void) {
    printf(YELLOW "\nTESTING ft_isalpha()\n" RESET);
    for (int c = -1; c <= 255; c++) {
        if ((ft_isalpha(c) != 0) != (isalpha(c) != 0)) {
            printf(RED "FAIL: ft_isalpha(%d) = %d, expected %s\n" RESET, 
                   c, ft_isalpha(c), (isalpha(c) ? "non-zero" : "zero"));
            return;
        }
    }
    printf(GREEN "ft_isalpha: OK!\n" RESET);
}

void test_ft_isdigit(void) {
    printf(YELLOW "\nTESTING ft_isdigit()\n" RESET);
    for (int c = -1; c <= 255; c++) {
        if ((ft_isdigit(c) != 0) != (isdigit(c) != 0)) {
            printf(RED "FAIL: ft_isdigit(%d) = %d, expected %s\n" RESET, 
                   c, ft_isdigit(c), (isdigit(c) ? "non-zero" : "zero"));
            return;
        }
    }
    printf(GREEN "ft_isdigit: OK!\n" RESET);
}

void test_ft_isalnum(void) {
    printf(YELLOW "\nTESTING ft_isalnum()\n" RESET);
    for (int c = -1; c <= 255; c++) {
        if ((ft_isalnum(c) != 0) != (isalnum(c) != 0)) {
            printf(RED "FAIL: ft_isalnum(%d) = %d, expected %s\n" RESET, 
                   c, ft_isalnum(c), (isalnum(c) ? "non-zero" : "zero"));
            return;
        }
    }
    printf(GREEN "ft_isalnum: OK!\n" RESET);
}

void test_ft_isprint(void) {
    printf(YELLOW "\nTESTING ft_isprint()\n" RESET);
    for (int c = -1; c <= 255; c++) {
        if ((ft_isprint(c) != 0) != (isprint(c) != 0)) {
            printf(RED "FAIL: ft_isprint(%d) = %d, expected %s\n" RESET, 
                   c, ft_isprint(c), (isprint(c) ? "non-zero" : "zero"));
            return;
        }
    }
    printf(GREEN "ft_isprint: OK!\n" RESET);
}

void test_ft_isascii(void) {
    printf(YELLOW "\nTESTING ft_isascii()\n" RESET);
    for (int c = -1; c <= 255; c++) {
        if ((ft_isascii(c) != 0) != (isascii(c) != 0)) {
            printf(RED "FAIL: ft_isascii(%d) = %d, expected %s\n" RESET, 
                   c, ft_isascii(c), (isascii(c) ? "non-zero" : "zero"));
            return;
        }
    }
    printf(GREEN "ft_isprint: OK!\n" RESET);
}

void test_ft_memset(void) {
    printf(YELLOW "\nTESTING ft_memset()\n" RESET);
    
    char str1[10] = "abcdefghi";
    char str2[10] = "abcdefghi";
    int c = 'x';
    size_t len = 5;

    ft_memset(str1, c, len);
    memset(str2, c, len);

    if (memcmp(str1, str2, 10) != 0) {
        printf(RED "FAIL: ft_memset() did not match memset()\n" RESET);
        printf("  ft_memset result: %.*s\n", 10, str1);
        printf("  memset result:    %.*s\n", 10, str2);
        return;
    }
    printf(GREEN "ft_memset: OK!\n" RESET);
}

void test_ft_bzero(void) {
    printf(YELLOW "\nTESTING ft_bzero()\n" RESET);
    
    char str1[10] = "abcdefghi";
    char str2[10] = "abcdefghi";
    size_t n = 5;

    ft_bzero(str1, n);
    bzero(str2, n);

    if (memcmp(str1, str2, 10) != 0) {
        printf(RED "FAIL: ft_bzero() did not match bzero()\n" RESET);
        printf("  ft_bzero result: %.*s\n", 10, str1);
        printf("  bzero result:    %.*s\n", 10, str2);
        return;
    }
    printf(GREEN "ft_bzero: OK!\n" RESET);
}

void test_ft_memcpy(void) {
    printf(YELLOW "\nTESTING ft_memcpy()\n" RESET);
    
    char src[10] = "123456789";
    char dst1[10] = {0};
    char dst2[10] = {0};
    size_t n = 5;

    ft_memcpy(dst1, src, n);
    memcpy(dst2, src, n);

    if (memcmp(dst1, dst2, 10) != 0) {
        printf(RED "FAIL: ft_memcpy() did not match memcpy()\n" RESET);
        printf("  ft_memcpy result: %.*s\n", 10, dst1);
        printf("  memcpy result:    %.*s\n", 10, dst2);
        return;
    }
    printf(GREEN "ft_memcpy: OK!\n" RESET);
}

void test_ft_memmove(void) {
    printf(YELLOW "\nTESTING ft_memmove()\n" RESET);
    
    // Test overlapping regions (src < dst)
    char str1[20] = "123456789";
    char str2[20] = "123456789";
    size_t len = 5;

    ft_memmove(str1 + 3, str1, len);
    memmove(str2 + 3, str2, len);

    if (memcmp(str1, str2, 20) != 0) {
        printf(RED "FAIL: ft_memmove() did not match memmove() (src < dst)\n" RESET);
        printf("  ft_memmove result: %s\n", str1);
        printf("  memmove result:    %s\n", str2);
        return;
    }

    // Test overlapping regions (dst < src)
    char str3[20] = "123456789";
    char str4[20] = "123456789";

    ft_memmove(str3, str3 + 3, len);
    memmove(str4, str4 + 3, len);

    if (memcmp(str3, str4, 20) != 0) {
        printf(RED "FAIL: ft_memmove() did not match memmove() (dst < src)\n" RESET);
        printf("  ft_memmove result: %s\n", str3);
        printf("  memmove result:    %s\n", str4);
        return;
    }

    printf(GREEN "ft_memmove: OK!\n" RESET);
}

void test_ft_strlen(void) {
    printf(YELLOW "\nTESTING ft_strlen()\n" RESET);
    char *str = "Hello, 42!";
    size_t len = strlen(str);
    size_t ft_len = ft_strlen(str);
    if (len != ft_len) {
        printf(RED "FAIL: ft_strlen(\"%s\") = %zu, expected %zu\n" RESET, str, ft_len, len);
        return;
    }
    printf(GREEN "ft_strlen: OK!\n" RESET);
}

void test_ft_strlcpy(void) {
    printf(YELLOW "\nTESTING ft_strlcpy()\n" RESET);

    char src[] = "Hello";
    char dst1[10] = {0};
    char dst2[10] = "Hello";
    size_t dstsize = sizeof(dst1);
    size_t ret1, ret2;

    ret1 = ft_strlcpy(dst1, src, dstsize);
    ret2 = strlen(dst2);

    if (ret1 != ret2 || strcmp(dst1, dst2) != 0) {
        printf(RED "FAIL: ft_strlcpy()\n" RESET);
        printf("  ft_strlcpy returned: %zu, dst: \"%s\"\n", ret1, dst1);
        printf("  strlcpy returned:    %zu, dst: \"%s\"\n", ret2, dst2);
        return;
    }
    printf(GREEN "ft_strlcpy: OK!\n" RESET);
}

void test_ft_strlcat(void) {
    printf(YELLOW "\nTESTING ft_strlcat()\n" RESET);

    char src[] = "World";
    char dst1[20] = "Hello";
    char dst2[20] = "HelloWorld";
    size_t dstsize = sizeof(dst1);
    size_t ret1, ret2;

    ret1 = ft_strlcat(dst1, src, dstsize);
    ret2 = strlen(dst2);

    if (ret1 != ret2 || strcmp(dst1, dst2) != 0) {
        printf(RED "FAIL: ft_strlcat()\n" RESET);
        printf("  ft_strlcat returned: %zu, dst: \"%s\"\n", ret1, dst1);
        printf("  strlcat returned:    %zu, dst: \"%s\"\n", ret2, dst2);
        return;
    }
    printf(GREEN "ft_strlcat: OK!\n" RESET);
}

void test_ft_toupper(void) {
    printf(YELLOW "\nTESTING ft_toupper()\n" RESET);

    for (int c = -1; c <= 255; c++) {
        if ((ft_toupper(c) != 0) != (toupper(c) != 0)) {
            printf(RED "FAIL: ft_toupper(%d) = %d, expected %d\n" RESET,
                   c, ft_toupper(c), toupper(c));
            return;
        }
    }
    printf(GREEN "ft_toupper: OK!\n" RESET);
}

void test_ft_tolower(void) {
    printf(YELLOW "\nTESTING ft_tolower()\n" RESET);

    for (int c = -1; c <= 255; c++) {
        if ((ft_tolower(c) != 0) != (tolower(c) != 0)) {
            printf(RED "FAIL: ft_tolower(%d) = %d, expected %d\n" RESET,
                   c, ft_tolower(c), tolower(c));
            return;
        }
    }
    printf(GREEN "ft_tolower: OK!\n" RESET);
}

void test_ft_strchr(void) {
    printf(YELLOW "\nTESTING ft_strchr()\n" RESET);

    const char *str = "Hello World";
    int c = 'o';
    char *res1 = ft_strchr(str, c);
    char *res2 = strchr(str, c);

    if (res1 != res2) {
        printf(RED "FAIL: ft_strchr(\"%s\", '%c') = %p, expected %p\n" RESET,
               str, c, (void *)res1, (void *)res2);
        return;
    }

    // Test for non-existent character
    c = 'z';
    res1 = ft_strchr(str, c);
    res2 = strchr(str, c);
    if (res1 != res2) {
        printf(RED "FAIL: ft_strchr(\"%s\", '%c') = %p, expected %p\n" RESET,
               str, c, (void *)res1, (void *)res2);
        return;
    }

    printf(GREEN "ft_strchr: OK!\n" RESET);
}

void test_ft_strrchr(void) {
    printf(YELLOW "\nTESTING ft_strrchr()\n" RESET);
    
    const char *str = "test string";
    int c = 't';
    char *res1 = ft_strrchr(str, c);
    char *res2 = strrchr(str, c);
    
    if (res1 != res2) {
        printf(RED "FAIL: ft_strrchr(\"%s\", '%c') = %p, expected %p\n" RESET,
               str, c, (void*)res1, (void*)res2);
        return;
    }
    printf(GREEN "ft_strrchr: OK!\n" RESET);
}

void test_ft_strncmp(void) {
    printf(YELLOW "\nTESTING ft_strncmp()\n" RESET);
    
    const char *s1 = "test";
    const char *s2 = "test2";
    size_t n = 4;
    int res1 = ft_strncmp(s1, s2, n);
    int res2 = strncmp(s1, s2, n);
    
    if ((res1 < 0 && res2 < 0) || (res1 > 0 && res2 > 0) || (res1 == 0 && res2 == 0)) {
        printf(GREEN "ft_strncmp: OK!\n" RESET);
    } else {
        printf(RED "FAIL: ft_strncmp(\"%s\", \"%s\", %zu) = %d, expected %d\n" RESET,
               s1, s2, n, res1, res2);
    }
}

void test_ft_memchr(void) {
    printf(YELLOW "\nTESTING ft_memchr()\n" RESET);
    
    const char str[] = "test string";
    int c = ' ';
    size_t n = sizeof(str);
    void *res1 = ft_memchr(str, c, n);
    void *res2 = memchr(str, c, n);
    
    if (res1 != res2) {
        printf(RED "FAIL: ft_memchr() = %p, expected %p\n" RESET, res1, res2);
        return;
    }
    printf(GREEN "ft_memchr: OK!\n" RESET);
}

void test_ft_memcmp(void) {
    printf(YELLOW "\nTESTING ft_memcmp()\n" RESET);
    
    const char s1[] = "test";
    const char s2[] = "test2";
    size_t n = 4;
    int res1 = ft_memcmp(s1, s2, n);
    int res2 = memcmp(s1, s2, n);
    
    if ((res1 < 0 && res2 < 0) || (res1 > 0 && res2 > 0) || (res1 == 0 && res2 == 0)) {
        printf(GREEN "ft_memcmp: OK!\n" RESET);
    } else {
        printf(RED "FAIL: ft_memcmp() = %d, expected %d\n" RESET, res1, res2);
    }
}

void test_ft_strnstr(void) {
    printf(YELLOW "\nTESTING ft_strnstr()\n" RESET);

    struct test_case {
        const char *haystack;
        const char *needle;
        size_t len;
        const char *expected;
    } tests[] = {
        {"Hello world", "world", 11, "world"},
        {"Hello world", "world", 5, NULL},
        {"Hello world", "", 11, "Hello world"},
        {"Hello world", "Hello", 11, "Hello world"},
        {"Hello world", "lo w", 11, "lo world"},
        {"Hello world", "goodbye", 11, NULL},
        {"", "needle", 0, NULL},
        {"short", "too long", 4, NULL},
        {"abc", "abc", 3, "abc"},
        {"abc", "abc", 2, NULL},
        {NULL, NULL, 0, NULL} // Sentinel
    };

    for (int i = 0; tests[i].haystack != NULL; i++) {
        char *result = ft_strnstr(tests[i].haystack, tests[i].needle, tests[i].len);
        if ((result == NULL && tests[i].expected != NULL) ||
            (result != NULL && tests[i].expected == NULL) ||
            (result != NULL && strncmp(result, tests[i].expected, strlen(tests[i].expected)) != 0)) {
            printf(RED "FAIL: ft_strnstr(\"%s\", \"%s\", %zu) = %s, expected %s\n" RESET,
                   tests[i].haystack, tests[i].needle, tests[i].len, 
                   result ? result : "NULL", 
                   tests[i].expected ? tests[i].expected : "NULL");
            return;
        }
    }
    printf(GREEN "ft_strnstr: OK!\n" RESET);
}

void test_ft_strdup(void) {
    printf(YELLOW "\nTESTING ft_strdup()\n" RESET);
    char *str = "Duplicate me!";
    char *dup = strdup(str);
    char *ft_dup = ft_strdup(str);
    if (strcmp(dup, ft_dup) != 0) {
        printf(RED "FAIL: ft_strdup(\"%s\") = \"%s\", expected \"%s\"\n" RESET, str, ft_dup, dup);
        free(dup);
        free(ft_dup);
        return;
    }
    free(dup);
    free(ft_dup);
    printf(GREEN "ft_strdup: OK!\n" RESET);
}

void test_ft_calloc(void) {
    printf(YELLOW "\n=== TESTING ft_calloc() ===\n\n" RESET);
    
    typedef struct {
        size_t nmemb;
        size_t size;
        const char *description;
    } test_case;

    test_case tests[] = {
        {5, sizeof(int), "Normal allocation (5 ints)"},
        {0, sizeof(int), "0 elements (should return non-NULL)"},
        {5, 0, "0 size (should return non-NULL)"},
        {0, 0, "0x0 allocation (implementation-defined)"},
        {1, 4096, "Large single element"},
        {SIZE_MAX/2, 2, "Potential overflow case"},
        {SIZE_MAX, 1, "Max elements"}
    };

    int passed = 0;
    int total = sizeof(tests)/sizeof(tests[0]);

    for (int i = 0; i < total; i++) {
        printf("Test %d: %-30s", i+1, tests[i].description);
        
        void *ft_ptr = ft_calloc(tests[i].nmemb, tests[i].size);
        void *sys_ptr = calloc(tests[i].nmemb, tests[i].size);
        
        // Check for matching NULLness
        if ((ft_ptr == NULL) != (sys_ptr == NULL)) {
            printf(RED "FAIL (NULL mismatch)\n" RESET);
            continue;
        }

        // If both succeeded, check memory
        if (ft_ptr && sys_ptr) {
            size_t total_size = tests[i].nmemb * tests[i].size;
            if (memcmp(ft_ptr, sys_ptr, total_size) != 0) {
                printf(RED "FAIL (memory not zeroed)\n" RESET);
                free(ft_ptr);
                free(sys_ptr);
                continue;
            }

            // Check alignment by testing as different types
            int alignment_ok = 1;
            if (tests[i].size >= sizeof(int)) {
                int *ft_int = (int *)ft_ptr;
                int *sys_int = (int *)sys_ptr;
                if (((uintptr_t)ft_int % _Alignof(int)) != 0) 
                    alignment_ok = 0;
            }
            
            if (!alignment_ok) {
                printf(RED "FAIL (alignment)\n" RESET);
                free(ft_ptr);
                free(sys_ptr);
                continue;
            }
        }

        printf(GREEN "PASS\n" RESET);
        passed++;
        free(ft_ptr);
        free(sys_ptr);
    }

    printf("\nSummary: %d/%d " GREEN "PASSED" RESET "\n", passed, total);
    
    // Additional edge case: ENOMEM simulation
    printf("\nTesting ENOMEM behavior... ");
    void *huge = ft_calloc(SIZE_MAX, SIZE_MAX);
    if (huge == NULL) {
        printf(GREEN "PASS (correctly returned NULL)\n" RESET);
    } else {
        printf(RED "FAIL (should return NULL)\n" RESET);
        free(huge);
    }
}

void test_ft_substr(void) {
    printf(YELLOW "\nTESTING ft_substr()\n" RESET);
    char *str = "Hello, 42!";
    char *sub = ft_substr(str, 7, 2);
    if (strcmp(sub, "42") != 0) {
        printf(RED "FAIL: ft_substr(\"%s\", 7, 2) = \"%s\", expected \"42\"\n" RESET, str, sub);
        free(sub);
        return;
    }
    free(sub);
    printf(GREEN "ft_substr: OK!\n" RESET);
}

void test_ft_strjoin(void) {
    printf(YELLOW "\nTESTING ft_strjoin()\n" RESET);
    char *s1 = "Hello, ";
    char *s2 = "42!";
    char *joined = ft_strjoin(s1, s2);
    if (strcmp(joined, "Hello, 42!") != 0) {
        printf(RED "FAIL: ft_strjoin(\"%s\", \"%s\") = \"%s\", expected \"Hello, 42!\"\n" RESET, s1, s2, joined);
        free(joined);
        return;
    }
    free(joined);
    printf(GREEN "ft_strjoin: OK!\n" RESET);
}

void test_ft_strtrim(void)
{
    printf(YELLOW "\nTESTING ft_strtrim():\n" RESET);

    // Test cases: {input, set, expected}
    const char *test_cases[][3] = {
        {"  hello  ", " ", "hello"},
        {"xxhello!xx", "x", "hello!"},
        {"abcHello, World!zyx", "abcxyz", "Hello, World!"},
        {"", "123", ""},
        {"hello", "", "hello"},
        {"xyz", "xyz", ""},
        {"   ", " ", ""},
        {"no_trim_needed", "123", "no_trim_needed"},
        {NULL, " ", NULL}  // NULL input (optional)
    };

    int passed = 0;
    int total = sizeof(test_cases) / sizeof(test_cases[0]);

    for (int i = 0; i < total; i++)
    {
        const char *s1 = test_cases[i][0];
        const char *set = test_cases[i][1];
        const char *expected = test_cases[i][2];
        char *result = ft_strtrim(s1, set);

        printf("Test %d: ft_strtrim(\"%s\", \"%s\") -> ", i + 1, s1 ? s1 : "NULL", set ? set : "NULL");
        
        if ((!result && !expected) || (result && expected && strcmp(result, expected) == 0))
        {
            printf(GREEN "PASS: \"%s\"\n" RESET, result ? result : "NULL");
            passed++;
        }
        else
        {
            printf(RED "FAIL: got \"%s\", expected \"%s\"\n" RESET, result ? result : "NULL", expected ? expected : "NULL");
        }

        free(result); // Safe even if result is NULL
    }

    printf("Summary: %d/%d " GREEN "PASSED" RESET "\n", passed, total);
}

void test_ft_split(void) {
    printf(YELLOW "\nTESTING ft_split()\n" RESET);
    char *str = "Hello,World,42";
    char **split = ft_split(str, ',');
    if (strcmp(split[0], "Hello") != 0 || strcmp(split[1], "World") != 0 || strcmp(split[2], "42") != 0) {
        printf(RED "FAIL: ft_split(\"%s\", ',') incorrect\n" RESET, str);
        for (int i = 0; split[i]; i++) free(split[i]);
        free(split);
        return;
    }
    for (int i = 0; split[i]; i++) free(split[i]);
    free(split);
    printf(GREEN "ft_split: OK!\n" RESET);
}

void test_ft_itoa(void)
{
    printf(YELLOW "\nTESTING ft_itoa():\n" RESET);

    struct {
        int input;
        const char *expected;
    } test_cases[] = {
        {0, "0"},
        {123, "123"},
        {-456, "-456"},
        {2147483647, "2147483647"},  // INT_MAX
        {-2147483648, "-2147483648"}, // INT_MIN
        {42, "42"},
        {-99, "-99"}
    };

    int passed = 0;
    int total = sizeof(test_cases) / sizeof(test_cases[0]);

    for (int i = 0; i < total; i++)
    {
        char *result = ft_itoa(test_cases[i].input);
        printf("Test %d: ft_itoa(%d) -> ", i + 1, test_cases[i].input);
        
        if (result && strcmp(result, test_cases[i].expected) == 0)
        {
            printf(GREEN "PASS: \"%s\"\n" RESET, result);
            passed++;
        }
        else
        {
            printf(RED "FAIL: got \"%s\", expected \"%s\"\n" RESET, result ? result : "NULL", test_cases[i].expected);
        }

        free(result); // Free allocated memory
    }

    printf("Summary: %d/%d " GREEN "PASSED" RESET "\n", passed, total);
}

// Helper function for testing ft_strmapi
static char map_func(unsigned int i, char c) {
    return (c + i); // Example: increment each char by its index
}

void test_ft_strmapi(void)
{
    printf(YELLOW "\nTESTING ft_strmapi():\n" RESET);

    struct {
        const char *input;
        const char *expected;
    } test_cases[] = {
        {"abc", "ace"},  // 'a'+0, 'b'+1, 'c'+2
        {"123", "135"},  // '1'+0, '2'+1, '3'+2
        {"", ""},        // Empty string
        {"x", "x"},      // Single char
        {"XYZ", "XZ\\"}, // 'X'+0, 'Y'+1, 'Z'+2 (ASCII 90+2=92 → '\')
    };

    int passed = 0;
    int total = sizeof(test_cases) / sizeof(test_cases[0]);

    for (int i = 0; i < total; i++)
    {
        char *result = ft_strmapi(test_cases[i].input, map_func);
        printf("Test %d: ft_strmapi(\"%s\") -> ", i + 1, test_cases[i].input);
        
        if (result && strcmp(result, test_cases[i].expected) == 0)
        {
            printf(GREEN "PASS: \"%s\"\n" RESET, result);
            passed++;
        }
        else
        {
            printf(RED "FAIL: got \"%s\", expected \"%s\"\n" RESET, result ? result : "NULL", test_cases[i].expected);
        }

        free(result); // Free allocated memory
    }

    printf("Summary: %d/%d " GREEN "PASSED" RESET "\n", passed, total);
}

// Helper function for testing ft_striteri
static void iter_func(unsigned int i, char *c) {
    *c = *c + i; // Modify the char in place (same logic as map_func)
}

void test_ft_striteri(void)
{
    printf(YELLOW "\nTESTING ft_striteri():\n" RESET);

    struct {
        char input[32];
        const char *expected;
    } test_cases[] = {
        {"abc", "ace"},  // 'a'+0, 'b'+1, 'c'+2
        {"123", "135"},  // '1'+0, '2'+1, '3'+2
        {"", ""},        // Empty string
        {"x", "x"},      // Single char (unchanged)
        {"XYZ", "XZ\\"}, // 'X'+0, 'Y'+1, 'Z'+2 (ASCII 90+2=92 → '\')
    };

    int passed = 0;
    int total = sizeof(test_cases) / sizeof(test_cases[0]);

    for (int i = 0; i < total; i++)
    {
        char buffer[32];
        strcpy(buffer, test_cases[i].input); // Copy input to mutable buffer
        ft_striteri(buffer, iter_func);
        printf("Test %d: ft_striteri(\"%s\") -> ", i + 1, test_cases[i].input);
        
        if (strcmp(buffer, test_cases[i].expected) == 0)
        {
            printf(GREEN "PASS: \"%s\"\n" RESET, buffer);
            passed++;
        }
        else
        {
            printf(RED "FAIL: got \"%s\", expected \"%s\"\n" RESET, buffer, test_cases[i].expected);
        }
    }

    printf("Summary: %d/%d " GREEN "PASSED" RESET "\n", passed, total);
}

void test_ft_putchar_fd(void) {
    printf(YELLOW "\nTESTING ft_putchar_fd():" RESET);
    printf(BLUE "\n" RESET);

    ft_putchar_fd('a', 1);
    printf(BLUE "\n" RESET);
    ft_putchar_fd('1', 2);

    printf("\n");
}

void test_ft_putstr_fd(void) {
    printf(YELLOW "\nTESTING ft_putstr_fd():" RESET);
    printf(BLUE "\n" RESET);
    
    ft_putstr_fd("Hello World!", 1);
    printf(BLUE "\n" RESET);
    ft_putstr_fd("Hello World!", 2);

    printf("\n");
}

void test_ft_putendl_fd(void) {
    printf(YELLOW "\nTESTING ft_putendl_fd():" RESET);
    printf(BLUE "\n" RESET);
    
    ft_putendl_fd("Hello World!", 1);
    printf(BLUE "" RESET);
    ft_putendl_fd("Hello World!", 2);

    printf("\n");
}

void test_ft_putnbr_fd(void) {
    printf(YELLOW "\nTESTING ft_putnbr_fd():" RESET);
    printf(BLUE "\n" RESET);
    
    ft_putnbr_fd(1234, 1);
    printf(BLUE "\n" RESET);
    ft_putnbr_fd(4321, 2);

    printf("\n");
}

t_list *create_node(int value) {
    t_list *new = malloc(sizeof(t_list));
    if (!new) return NULL;
    new->content = (void*)(long)value;
    new->next = NULL;
    return new;
}

void print_list(t_list *lst) {
    printf(BLUE "[");
    while (lst) {
        printf("%d", (int)(long)lst->content);
        if (lst->next) printf("->");
        lst = lst->next;
    }
    printf("]\n" RESET);
}

void free_list(t_list *lst) {
    while (lst) {
        t_list *tmp = lst;
        lst = lst->next;
        free(tmp);
    }
}

void test_ft_lstnew(void) {
    printf(YELLOW "\nTESTING ft_lstnew()\n" RESET);
    int content = 42;
    t_list *node = ft_lstnew(&content);
    if (node == NULL || *(int *)node->content != 42) {
        printf(RED "FAIL: ft_lstnew() did not create node correctly\n" RESET);
        free(node);
        return;
    }
    free(node);
    printf(GREEN "ft_lstnew: OK!\n" RESET);
}

void test_ft_lstadd_front(void) {
    printf(YELLOW "\n=== Testing ft_lstadd_front ===\n" RESET);
    
    t_list *list = NULL;
    
    // Test 1: Add to empty list
    t_list *node1 = create_node(10);
    ft_lstadd_front(&list, node1);
    printf("After adding 10 to empty list: ");
    print_list(list);  // Expected: [10]
    
    // Test 2: Add to existing list
    t_list *node2 = create_node(20);
    ft_lstadd_front(&list, node2);
    printf("After adding 20 at front:      ");
    print_list(list);  // Expected: [20 -> 10]
    
    free_list(list);
}

void test_ft_lstsize(void) {
    printf(YELLOW "\n=== Testing ft_lstsize ===\n" RESET);
    
    t_list *list = NULL;
    
    // Test 1: Empty list
    printf("Size of empty list: %d (Expected: 0)\n", ft_lstsize(list));
    
    // Test 2: 1-element list
    list = create_node(10);
    printf("Size after adding 10: %d (Expected: 1)\n", ft_lstsize(list));
    
    // Test 3: Multi-element list
    t_list *node = create_node(20);
    ft_lstadd_front(&list, node);
    printf("Size after adding 20: %d (Expected: 2)\n", ft_lstsize(list));
    
    free_list(list);
}

void test_ft_lstlast(void) {
    printf(YELLOW "\n=== Testing ft_lstlast ===\n" RESET);
    
    t_list *list = NULL;
    
    // Test 1: Empty list
    printf("Last of empty list: %s (Expected: NULL)\n", 
           ft_lstlast(list) ? "NOT NULL" : "NULL");
    
    // Test 2: 1-element list
    list = create_node(10);
    printf("Last of [10]: %d (Expected: 10)\n", 
           (int)(long)ft_lstlast(list)->content);
    
    // Test 3: Multi-element list
    t_list *node = create_node(20);
    ft_lstadd_front(&list, node);
    printf("Last of [20->10]: %d (Expected: 10)\n", 
           (int)(long)ft_lstlast(list)->content);
    
    free_list(list);
}

void test_ft_lstadd_back(void) {
    printf(YELLOW "\n=== Testing ft_lstadd_back ===\n" RESET);
    
    t_list *list = NULL;
    
    // Test 1: Add to empty list
    t_list *node1 = create_node(10);
    ft_lstadd_back(&list, node1);
    printf("After adding 10 to empty list: ");
    print_list(list);  // Expected: [10]
    
    // Test 2: Add to existing list
    t_list *node2 = create_node(20);
    ft_lstadd_back(&list, node2);
    printf("After adding 20 at back:       ");
    print_list(list);  // Expected: [10 -> 20]
    
    // Test 3: Add another node
    t_list *node3 = create_node(30);
    ft_lstadd_back(&list, node3);
    printf("After adding 30 at back:       ");
    print_list(list);  // Expected: [10 -> 20 -> 30]
    
    free_list(list);
}

// Sample content deletion function
void del_content(void *content) {
    printf("Deleting content: %d\n", (int)(long)content);
    // If content was malloc'd: free(content);
}

// Sample content modification function
void *map_content(void *content) {
    int value = (int)(long)content;
    return (void *)(long)(value * 10); // Multiply by 10 for testing
}

// Print content function for lstiter
void print_content(void *content) {
    printf("%d -> ", (int)(long)content);
}

void test_ft_lstdelone(void) {
    printf(YELLOW "\n=== Testing ft_lstdelone ===\n" RESET);
    
    // Create and test single node deletion
    t_list *node = create_node(42);
    printf("Before deletion: ");
    print_list(node);
    
    ft_lstdelone(node, del_content);
    printf("After deletion (should see deletion message above)\n");
    
    // Note: Don't access 'node' after deletion!
    printf("Test passed if you saw deletion message\n");
}

void test_ft_lstclear(void) {
    printf(YELLOW "\n=== Testing ft_lstclear ===\n" RESET);
    
    // Create a 3-node list
    t_list *list = create_node(1);
    ft_lstadd_back(&list, create_node(2));
    ft_lstadd_back(&list, create_node(3));
    
    printf("Before clear: ");
    print_list(list);
    
    ft_lstclear(&list, del_content);
    printf("After clear (should see 3 deletion messages above)\n");
    
    if (list == NULL) {
        printf(GREEN "Success: List pointer is now NULL\n" RESET);
    } else {
        printf(RED "Error: List pointer not set to NULL\n" RESET);
    }
}

void test_ft_lstiter(void) {
    printf(YELLOW "\n=== Testing ft_lstiter ===\n" RESET);
    
    // Create a 3-node list
    t_list *list = create_node(10);
    ft_lstadd_back(&list, create_node(20));
    ft_lstadd_back(&list, create_node(30));
    
    printf("Original list: ");
    print_list(list);
    
    printf("Iterating with print: ");
    ft_lstiter(list, print_content);
    printf("NULL\n");
    
    // Expected output: "10 -> 20 -> 30 -> NULL"
    
    ft_lstclear(&list, del_content);
}

void test_ft_lstmap(void) {
    printf(YELLOW "\n=== Testing ft_lstmap ===\n" RESET);
    
    // Create source list
    t_list *src = create_node(1);
    ft_lstadd_back(&src, create_node(2));
    ft_lstadd_back(&src, create_node(3));
    
    printf("Source list: ");
    print_list(src);
    
    // Map each value to value*10
    t_list *new_list = ft_lstmap(src, map_content, del_content);
    
    printf("Mapped list (should be 10,20,30): ");
    print_list(new_list);
    
    // Cleanup
    ft_lstclear(&src, del_content);
    ft_lstclear(&new_list, del_content);
}

int main(void) {
    printf(BLUE "\n=== LIBFT TESTER ===\n" RESET);

    // Part 1: Libc functions
    test_ft_isalpha();
	test_ft_isdigit();
	test_ft_isalnum();
	test_ft_isprint();
    test_ft_isascii();
    test_ft_atoi();
    test_ft_strlen();
	test_ft_memset();
	test_ft_bzero();
	test_ft_memcpy();
	test_ft_memmove();
	test_ft_strlcpy();
	test_ft_strlcat();
	test_ft_toupper();
	test_ft_tolower();
	test_ft_strchr();
	test_ft_strrchr();
	test_ft_strncmp();
	test_ft_memchr();
	test_ft_memcmp();
	test_ft_strnstr();
    test_ft_strdup();
    test_ft_calloc();

    // Part 2: Additional functions
    test_ft_substr();
    test_ft_strjoin();
    test_ft_strtrim();
    test_ft_split();
    test_ft_itoa();
    test_ft_strmapi();
    test_ft_striteri();
    test_ft_putchar_fd();
    test_ft_putstr_fd();
    test_ft_putendl_fd();
    test_ft_putnbr_fd();

    // Bonus: Linked List functions
    test_ft_lstnew();
    test_ft_lstadd_front();
    test_ft_lstsize();
    test_ft_lstlast();
    test_ft_lstadd_back();
    test_ft_lstdelone();
    test_ft_lstclear();
    test_ft_lstiter();
    test_ft_lstmap();

    printf(BLUE "\n=== TESTS COMPLETE ===\n" RESET);
    return (0);
}