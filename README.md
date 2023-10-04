---
# 🛠 Unit Test Framework (C)

A user-friendly and robust Unit Test Framework to make your development easier and less error-prone.

## 📦 Installation

1. **Include the .h File:** Add the `.h` file to your project to get started.

## 🚀 Usage

To use the framework, you'll need to declare some macros within the scope you're looking to test.

### Step-by-Step Guide

1. **Initialize Test Famework**: Add the `UNIT_TESTS_INIT` macro at the beginning of the file with unit tests.
2. **Setup Test Famework**: Add the `UNIT_TESTS_BEGIN` macro at the beginning of the function with unit tests.
2. **Assertions**: Use `ASSERT` and `ASSERT_EQUAL` macros to perform various tests.

#### Macros:

- `ASSERT(func, args, expected)`: Use this macro to test if a function returns the expected value.
- `ASSERT_EQUAL(lvalue, rvalue)`: Use this macro to test if two variables are equal.

## 📝 Example

Here's a quick example to get you started:

```C
UNIT_TESTS_INIT;

void test_all() {
  UNIT_TESTS_BEGIN;
  // Your code for testing goes here
  ASSERT(sqr, (2), 4);
  ASSERT_EQUAL(2, 2);
  UNIT_TESTS_END;
}
```

## 🎯 What Happens Next?

- **Success**: If there are no assertion errors, your program will continue as expected.
- **Failure**: If an assertion fails, you will see error messages with the filename and line number. The program will stop execution after all unit tests are run.

---