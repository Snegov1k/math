#include <check.h>
#include <math.h>
#include <stdlib.h>

#include "../s21_math.h"

START_TEST(s21_pow_usual_test) {
  double test_values[][2] = {{234, 2}, {-2345, 4}, {-0.4124, 6}, {0.9, 1},
                             {4, 0},   {1, 24},    {123, -2}};
  for (int i = 0; i < (int)(sizeof(test_values) / sizeof(test_values[0]));
       i++) {
    double value_1 = test_values[i][0];
    double value_2 = test_values[i][1];
    ck_assert_double_eq_tol(s21_pow(value_1, value_2), pow(value_1, value_2),
                            1e-6);
  }
}
END_TEST

START_TEST(s21_pow_unusual_test) {
  ck_assert_double_infinite(s21_pow(0, -16));
  ck_assert_double_eq_tol(s21_pow(-1, INFINITY), pow(-1, INFINITY), 1e-6);
  ck_assert_double_infinite(s21_pow(0.234, -INFINITY));
  ck_assert_double_eq_tol(s21_pow(123, -INFINITY), pow(123, -INFINITY), 1e-6);
  ck_assert_double_eq_tol(s21_pow(0.123, INFINITY), pow(0.123, INFINITY), 1e-6);
  ck_assert_double_infinite(s21_pow(234, INFINITY));
  ck_assert_double_eq_tol(s21_pow(-INFINITY, -13), pow(-INFINITY, -13), 1e-6);
  ck_assert_double_eq_tol(s21_pow(-INFINITY, -14), pow(-INFINITY, -14), 1e-6);
  ck_assert_double_infinite(s21_pow(-INFINITY, 123.1243));
  ck_assert_double_eq_tol(s21_pow(INFINITY, -14), pow(INFINITY, -14), 1e-6);
  ck_assert_double_infinite(s21_pow(INFINITY, 2));
  ck_assert_double_infinite(s21_pow(INFINITY, INFINITY));
  ck_assert_double_nan(s21_pow(-12, 2.123));
  ck_assert_double_eq_tol(s21_pow(12, 2.6756), pow(12, 2.6756), 1e-6);
}
END_TEST

Suite *s21_pow_suite() {
  Suite *s = suite_create("s21_pow");
  TCase *tc = tcase_create("s21_pow");

  tcase_add_test(tc, s21_pow_usual_test);
  tcase_add_test(tc, s21_pow_unusual_test);
  suite_add_tcase(s, tc);

  return s;
}

int main() {
  int number_failed;
  SRunner *runner;

  runner = srunner_create(s21_pow_suite());

  srunner_run_all(runner, CK_NORMAL);
  number_failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
