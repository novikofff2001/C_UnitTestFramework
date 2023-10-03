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
	ASSERT(double_sum, 4, 2, 2);
	ASSERT(double_sum, 10, 5, 5);
}

void test_triple_sum() {
	ASSERT(triple_sum, 6, 2, 2, 2);
	ASSERT(triple_sum, 20, 10, 5, 5);
}

void test_pointer_creation() {
	{
		int* a = NULL;
		ASSERT(make_another_pointer, a, a);
		ASSERT(make_another_pointer, NULL, a);
	};

	{
		int* a = (int*)malloc(sizeof(int));
		ASSERT(make_another_pointer, a, a);
		ASSERT(make_another_pointer, NULL, NULL);
		free(a);
	};
}

void test_wrong() {
	ASSERT(double_sum, 11, 5, 5);
	ASSERT(triple_sum, 5, 1, 1, 1);
	{
		int* a = (int*)malloc(sizeof(int));
		ASSERT(make_another_pointer, NULL, a);
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