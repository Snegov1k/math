#include <check.h>
#include <math.h>
#include <stdlib.h>

#include "../s21_math.h"

START_TEST(s21_abs_usual_test) {
  int test_values[] = {1, -23, 100, 0, -100};
  for (int i = 0; i < (int)(sizeof(test_values) / sizeof(test_values[0]));
       i++) {
    ck_assert_int_eq(s21_abs(test_values[i]), abs(test_values[i]));
  }
}
END_TEST

Suite *s21_abs_suite() {
  Suite *s = suite_create("s21_abs");
  TCase *tc = tcase_create("s21_abs");

  tcase_add_test(tc, s21_abs_usual_test);
  suite_add_tcase(s, tc);

  return s;
}

int main() {
  int number_failed;
  SRunner *runner;

  runner = srunner_create(s21_abs_suite());

  srunner_run_all(runner, CK_NORMAL);
  number_failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
