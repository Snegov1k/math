#include "../s21_math.h"

long double s21_log(double x) {
  int exp_pow = 0;
  long double step = 0;
  long double res = 0;
  long double result = x;

  if (!(S21_isNAN(x)) && x != S21_INF) {
    result = 0;
    if (x > 0) {
      while (x >= S21_E) {
        x /= S21_E;
        exp_pow++;
      }
      for (int i = 0; i < 200; i++) {
        step = res;
        res = step + 2 * (x - s21_exp(step)) / (x + s21_exp(step));
      }
      result = res + exp_pow;
    } else if (s21_fabs(x) < 1e-15)
      result = -S21_INF;
  }
  result = x < 0 ? S21_NAN : result;

  return result;
}
