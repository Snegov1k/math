#include <check.h>
#include <math.h>
#include <stdlib.h>

#include "../s21_math.h"

START_TEST(s21_fabs_usual_test) {
  double test_values[] = {1.2453, -423.24154, 124.425, -3.315134};
  for (int i = 0; i < (int)(sizeof(test_values) / sizeof(test_values[0]));
       i++) {
    ck_assert_ldouble_eq(s21_fabs(test_values[i]), fabs(test_values[i]));
  }
}
END_TEST

START_TEST(s21_fabs_unusual_test) {
  ck_assert_ldouble_eq(s21_fabs(INFINITY), fabs(INFINITY));
  ck_assert_ldouble_eq(s21_fabs(-INFINITY), fabs(-INFINITY));
  ck_assert_double_nan(s21_fabs(NAN));
}
END_TEST

Suite *s21_fabs_suite() {
  Suite *s = suite_create("s21_fabs");
  TCase *tc = tcase_create("s21_fabs");

  tcase_add_test(tc, s21_fabs_usual_test);
  tcase_add_test(tc, s21_fabs_unusual_test);
  suite_add_tcase(s, tc);

  return s;
}

int main() {
  int number_failed;
  SRunner *runner;

  runner = srunner_create(s21_fabs_suite());

  srunner_run_all(runner, CK_NORMAL);
  number_failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
