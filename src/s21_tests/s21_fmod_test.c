#include <check.h>
#include <math.h>
#include <stdlib.h>

#include "../s21_math.h"

START_TEST(s21_fmod_usual_test) {
  double test_values[][2] = {{234, 2}, {-2345, 4}, {-0.4124, 6}, {0.9, 1}};
  for (int i = 0; i < (int)(sizeof(test_values) / sizeof(test_values[0]));
       i++) {
    double value_1 = test_values[i][0];
    double value_2 = test_values[i][1];
    ck_assert_double_eq_tol(s21_fmod(value_1, value_2), fmod(value_1, value_2),
                            1e-6);
  }
}
END_TEST

START_TEST(s21_fmod_unusual_test) {
  ck_assert_double_nan(s21_fmod(INFINITY, 2));
  ck_assert_double_nan(s21_fmod(4, 0));
  ck_assert_double_nan(s21_fmod(INFINITY, INFINITY));
  ck_assert_double_eq_tol(s21_fmod(4, INFINITY), fmod(4, INFINITY), 1e-6);
}
END_TEST

Suite *s21_fmod_suite() {
  Suite *s = suite_create("s21_fmod");
  TCase *tc = tcase_create("s21_fmod");

  tcase_add_test(tc, s21_fmod_usual_test);
  tcase_add_test(tc, s21_fmod_unusual_test);
  suite_add_tcase(s, tc);

  return s;
}

int main() {
  int number_failed;
  SRunner *runner;

  runner = srunner_create(s21_fmod_suite());

  srunner_run_all(runner, CK_NORMAL);
  number_failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
