#ifndef UNIT_TEST_FRAMEWORK
#define UNIT_TEST_FRAMEWORK

#include <stdio.h>
#include <stdlib.h>

typedef struct UnitTestFramework {
    int err_count;
} UnitTestFramework;

UnitTestFramework* _UnitTestFramework_new();

void _UnitTestFramework_delete(UnitTestFramework* fw);

#define EVAL(type, func, ...) type result = func(__VA_ARGS__)

#define GET_EVAL(val) val
#define GET_LINE GET_EVAL(__LINE__)
#define GET_FILE GET_EVAL(__FILE__)

#define UNIT_TEST_FRAMEWORK_VAR_NAME _unit_t_f
#define UNIT_TESTS_INIT              UnitTestFramework* UNIT_TEST_FRAMEWORK_VAR_NAME = NULL
#define UNIT_TESTS_BEGIN             UNIT_TEST_FRAMEWORK_VAR_NAME = _UnitTestFramework_new()

#define UNIT_TESTS_END                                                                  \
    if (UNIT_TEST_FRAMEWORK_VAR_NAME->err_count) {                                      \
        printf("\n\n%d unit tests failed\n", UNIT_TEST_FRAMEWORK_VAR_NAME->err_count);  \
        _UnitTestFramework_delete(UNIT_TEST_FRAMEWORK_VAR_NAME);                        \
        exit(1);                                                                        \
    }                                                                              

#define ASSERT_PRINT(x) { _Generic((x),               \
    int:            fprintf(stderr, "%d", x),         \
    int*:           fprintf(stderr, "%p", (void*)x),  \
    float:          fprintf(stderr, "%f", x),         \
    float*:         fprintf(stderr, "%p", (void*)x),  \
    double:         fprintf(stderr, "%f", x),         \
    double*:        fprintf(stderr, "%p", (void*)x),  \
    char:           fprintf(stderr, "%c", x),         \
    char*:          fprintf(stderr, "%p", (void*)x),  \
    const char*:    fprintf(stderr, "%s", x),         \
    default:        fprintf(stderr, "%p", (void*)x)   \
); }                                                  
                                
#define ASSERT_EQUAL(lvalue, rvalue) {                                 \
    if ((lvalue) != (rvalue)) {                                        \
        fprintf(stderr, "Assertion failed: ");                         \
        fprintf(stderr, "%s = ", #lvalue);                             \
        ASSERT_PRINT(lvalue);                                          \
        fprintf(stderr, ", expected: ");                               \
        ASSERT_PRINT(rvalue);                                          \
        fprintf(stderr, ". File: %s, Line: %d\n", GET_FILE, GET_LINE); \
        UNIT_TEST_FRAMEWORK_VAR_NAME->err_count++;                     \
    }; }

#define ASSERT(func, args, expected) {                                 \
    ASSERT_EQUAL(func args, expected);                                 \
}

#endif // !UNIT_TEST_FRAMEWORK

