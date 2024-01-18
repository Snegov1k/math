#include <check.h>
#include <math.h>
#include <stdlib.h>

#include "../s21_math.h"

START_TEST(s21_cos_usual_test) {
  for (double i = -10 * M_PI; i <= 10 * M_PI; i += 0.1) {
    ck_assert_double_eq_tol(s21_cos(i), cos(i), 1e-6);
  }
}
END_TEST

START_TEST(s21_cos_unusual_test) {
  double test_values[] = {100.0, -100.0, 1.0, M_PI, -M_PI};
  for (int i = 0; i < (int)(sizeof(test_values) / sizeof(test_values[0]));
       i++) {
    ck_assert_double_eq_tol(s21_cos(i), cos(i), 1e-6);
  }
}
END_TEST

Suite *s21_cos_suite() {
  Suite *s = suite_create("s21_cos");
  TCase *tc = tcase_create("s21_cos");

  tcase_add_test(tc, s21_cos_usual_test);
  tcase_add_test(tc, s21_cos_unusual_test);
  suite_add_tcase(s, tc);

  return s;
}

int main() {
  int number_failed;
  SRunner *runner;

  runner = srunner_create(s21_cos_suite());

  srunner_run_all(runner, CK_NORMAL);
  number_failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
