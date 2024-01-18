#include <check.h>
#include <math.h>
#include <stdlib.h>

#include "../s21_math.h"

START_TEST(s21_sqrt_usual_test) {
  for (double i = 0; i <= 100; i += 0.1) {
    ck_assert_double_eq_tol(s21_sqrt(i), sqrt(i), 1e-6);
  }
}
END_TEST

START_TEST(s21_sqrt_unusual_test) {
  ck_assert_double_nan(s21_sqrt(-234));
  ck_assert_double_eq_tol(s21_sqrt(0.0), sqrt(0.0), 1e-6);
  ck_assert_double_infinite(s21_sqrt(INFINITY));
  ck_assert_double_nan(s21_sqrt(NAN));
}
END_TEST

Suite *s21_sqrt_suite() {
  Suite *s = suite_create("s21_sqrt");
  TCase *tc = tcase_create("s21_sqrt");

  tcase_add_test(tc, s21_sqrt_usual_test);
  tcase_add_test(tc, s21_sqrt_unusual_test);
  suite_add_tcase(s, tc);

  return s;
}

int main() {
  int number_failed;
  SRunner *runner;

  runner = srunner_create(s21_sqrt_suite());

  srunner_run_all(runner, CK_NORMAL);
  number_failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
