#include "UnitTestFramework.h"

UNIT_TESTS_INIT;

int double_sum(int a, int b) {
	return a + b;
}

int triple_sum(int a, int b, int c) {
	return a + b + c;
}

int* make_another_pointer(int* p) {
	int* another = p;
	return another;
}

void test_double_sum() {
	ASSERT(double_sum, (2, 2), 4);
	ASSERT(double_sum, (5, 5), 10);
}

void test_triple_sum() {
	ASSERT(triple_sum, (2, 2, 2), 6);
	ASSERT(triple_sum, (5, 5, 5), 15);
}

void test_pointer_creation() {
	{
		int* a = NULL;
		ASSERT(make_another_pointer, (a), a);
		ASSERT(make_another_pointer, (NULL), a);
	};

	{
		int* a = (int*)malloc(sizeof(int));
		ASSERT(make_another_pointer, (a), a);
		ASSERT(make_another_pointer, (NULL), NULL);
		free(a);
	};
}

void test_wrong() {
	ASSERT_EQUAL(5, 6);
	ASSERT(double_sum, (1, 2), 5);
	ASSERT(double_sum, (5, 5), 15);
	ASSERT(triple_sum, (1, 1, 1), 5);
	{
		int* a = (int*)malloc(sizeof(int));
		ASSERT(make_another_pointer, (NULL), a);
		free(a);
	}
}

void test_all() {
	UNIT_TESTS_BEGIN;
	test_double_sum();
	test_triple_sum();
	test_pointer_creation();
	test_wrong();
	UNIT_TESTS_END;
}

int main() {
	test_all();
	printf("If you can read this message, it means that all unit tests passed successfully!\n");
}