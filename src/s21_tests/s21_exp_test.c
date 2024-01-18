#include <check.h>
#include <math.h>
#include <stdlib.h>

#include "../s21_math.h"

START_TEST(s21_exp_usual_test) {
  double test_values[] = {-12.52446, 0.0, 3.23453, -4.32535};
  for (int i = 0; i < (int)(sizeof(test_values) / sizeof(test_values[0]));
       i++) {
    ck_assert_double_eq_tol(s21_exp(test_values[i]), exp(test_values[i]), 1e-6);
  }

  for (int i = -20.0; i <= 20.0; i++) {
    ck_assert_double_eq_tol(s21_exp(i), exp(i), 1e-6);
  }
}
END_TEST

START_TEST(s21_exp_unusual_test) {
  ck_assert_float_infinite(s21_exp(823949754));
  ck_assert_float_infinite(s21_exp(S21_INF));
  ck_assert_ldouble_eq(s21_exp(-S21_INF), 0.0);
  ck_assert_ldouble_nan(s21_exp(S21_NAN));
  ck_assert_ldouble_nan(s21_exp(-S21_NAN));
}
END_TEST

Suite *s21_exp_suite() {
  Suite *s = suite_create("s21_exp");
  TCase *tc = tcase_create("s21_exp");

  tcase_add_test(tc, s21_exp_usual_test);
  tcase_add_test(tc, s21_exp_unusual_test);
  suite_add_tcase(s, tc);

  return s;
}

int main() {
  int number_failed;
  SRunner *runner;

  runner = srunner_create(s21_exp_suite());

  srunner_run_all(runner, CK_NORMAL);
  number_failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
