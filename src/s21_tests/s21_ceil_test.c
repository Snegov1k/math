#include <check.h>
#include <math.h>
#include <stdlib.h>

#include "../s21_math.h"

START_TEST(s21_ceil_usual_test) {
  double test_values[] = {0.112, -0.32, -0.4124, 0.9};
  for (int i = 0; i < (int)(sizeof(test_values) / sizeof(test_values[0]));
       i++) {
    ck_assert_double_eq_tol(s21_ceil(test_values[i]), ceil(test_values[i]),
                            1e-6);
  }
}
END_TEST

START_TEST(s21_ceil_unusual_test) {
  ck_assert_double_infinite(s21_ceil(INFINITY));
  ck_assert_double_infinite(s21_ceil(-INFINITY));
  ck_assert_double_nan(s21_ceil(NAN));
}
END_TEST

Suite *s21_ceil_suite() {
  Suite *s = suite_create("s21_ceil");
  TCase *tc = tcase_create("s21_ceil");

  tcase_add_test(tc, s21_ceil_usual_test);
  tcase_add_test(tc, s21_ceil_unusual_test);
  suite_add_tcase(s, tc);

  return s;
}

int main() {
  int number_failed;
  SRunner *runner;

  runner = srunner_create(s21_ceil_suite());

  srunner_run_all(runner, CK_NORMAL);
  number_failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
