#include <ctest.h>
#include <input_circles.h>

CTEST(input_number_circles, correct_number_1)
{
    const int a = 1;
    const int result = check(a);
    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}
CTEST(input_number_circles, correct_number_2)
{
    const int a = 10;
    const int result = check(a);
    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}
CTEST(input_number_circles, correct_number_3)
{
    const int a = 40;
    const int result = check(a);
    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}
CTEST(input_number_circles, correct_number_4)
{
    const int a = 6;
    const int result = check(a);
    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}
CTEST(input_number_circles, correct_number_5)
{
    const int a = 100;
    const int result = check(a);
    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}
CTEST(input_number_circles, incorrect_number_1)
{
    const int a = 0;
    const int result = check(a);
    const int expected = 1;
    ASSERT_EQUAL(expected, result);
}
CTEST(input_number_circles, incorrect_number_2)
{
    const float a = 1.5;
    const int result = check(a);
    const int expected = 1;
    ASSERT_EQUAL(expected, result);
}
CTEST(input_number_circles, incorrect_number_3)
{
    const int a = -5;
    const int result = check(a);
    const int expected = 1;
    ASSERT_EQUAL(expected, result);
}
CTEST(input_number_circles, incorrect_number_4)
{
    const float a = 467.23;
    const int result = check(a);
    const int expected = 1;
    ASSERT_EQUAL(expected, result);
}
CTEST(input_number_circles, incorrect_number_5)
{
    const int a = -1000;
    const int result = check(a);
    const int expected = 1;
    ASSERT_EQUAL(expected, result);
}
CTEST(input_number_circles, incorrect_number_6)
{
    const float a = -0.6;
    const int result = check(a);
    const int expected = 1;
    ASSERT_EQUAL(expected, result);
}
CTEST(input_radius_circles, correct_number_1)
{
    const int a = 1;
    const int result = check(a);
    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}
CTEST(input_radius_circles, correct_number_2)
{
    const int a = 4567;
    const int result = check(a);
    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}
CTEST(input_radius_circles, correct_number_3)
{
    const int a = 28;
    const int result = check(a);
    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}
CTEST(input_radius_circles, correct_number_4)
{
    const float a = 34.5;
    const int result = check(a);
    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}
CTEST(input_radius_circles, correct_number_5)
{
    const float a = 234.523;
    const int result = check(a);
    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}
CTEST(input_radius_circles, incorrect_number_1)
{
    const int a = -1;
    const int result = check(a);
    const int expected = 1;
    ASSERT_EQUAL(expected, result);
}
CTEST(input_radius_circles, incorrect_number_2)
{
    const float a = -453.2334;
    const int result = check(a);
    const int expected = 1;
    ASSERT_EQUAL(expected, result);
}
CTEST(input_radius_circles, incorrect_number_3)
{
    const int a = 0;
    const int result = check(a);
    const int expected = 1;
    ASSERT_EQUAL(expected, result);
}
CTEST(input_radius_circles, incorrect_number_4)
{
    const float a = 0.3232241;
    const int result = check(a);
    const int expected = 1;
    ASSERT_EQUAL(expected, result);
}
CTEST(input_radius_circles, incorrect_number_1)
{
    const int a = -0.234234;
    const int result = check(a);
    const int expected = 1;
    ASSERT_EQUAL(expected, result);
}
