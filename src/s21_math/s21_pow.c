#include "../s21_math.h"

long double s21_pow_int(double base, int exp);

void s21_check_pow_arguments(double base, double exp, long double *result);

long double s21_pow(double base, double exp) {
  long double result = 21;

  s21_check_pow_arguments(base, exp, &result);

  if (result == 21) {
    if (exp == (int)exp) {
      result = s21_pow_int(base, (int)exp);
    } else {
      if (base < 0) {
        result = S21_NAN;
      } else {
        result = s21_exp(exp * s21_log(base));
      }
    }
  }

  return result;
}

long double s21_pow_int(double base, int exp) {
  double result = 1.0;

  if (exp < 0) {
    base = 1.0 / base;
    exp = -exp;
  }

  for (int i = 0; i < exp; i++) {
    result *= base;
  }

  return result;
}

void s21_check_pow_arguments(double base, double exp, long double *result) {
  if (base == 0.0 && exp < 0.0) *result = S21_INF;

  if (base == -1 && s21_fabs(exp) == S21_INF) *result = 1.0;

  if (base == 1.0) *result = 1.0;

  if (exp == -S21_INF && s21_fabs(base) < 1) *result = S21_INF;

  if (exp == -S21_INF && s21_fabs(base) > 1) *result = 0;

  if (exp == S21_INF && s21_fabs(base) < 1) *result = 0;

  if (exp == S21_INF && s21_fabs(base) > 1) *result = S21_INF;

  if (base == -S21_INF) {
    if (exp < 0.0 && exp == (int)exp && (int)exp % 2 != 0) *result = -0.0;

    if (exp < 0.0 &&
        (exp != (int)exp || (exp == (int)exp && (int)exp % 2 == 0)))
      *result = 0;

    if (exp > 0.0 && exp != (int)exp) *result = S21_INF;
  }

  if (base == S21_INF && exp < 0.0) *result = 0;
}
