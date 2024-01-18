#include <check.h>
#include <math.h>
#include <stdlib.h>

#include "../s21_math.h"

START_TEST(s21_floor_usual_test) {
  for (double i = -2.0; i <= 2.0; i += 0.1) {
    ck_assert_double_eq(s21_floor(i), floor(i));
  }
}
END_TEST

START_TEST(s21_floor_unusual_test) {
  ck_assert_double_infinite(s21_floor(INFINITY));
  ck_assert_double_infinite(s21_floor(-INFINITY));
  ck_assert_double_nan(s21_floor(NAN));
}
END_TEST

Suite *s21_floor_suite() {
  Suite *s = suite_create("s21_floor");
  TCase *tc = tcase_create("s21_floor");

  tcase_add_test(tc, s21_floor_usual_test);
  tcase_add_test(tc, s21_floor_unusual_test);
  suite_add_tcase(s, tc);

  return s;
}

int main() {
  int number_failed;
  SRunner *runner;

  runner = srunner_create(s21_floor_suite());

  srunner_run_all(runner, CK_NORMAL);
  number_failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
