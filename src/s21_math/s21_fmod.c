#include "../s21_math.h"

long double s21_fmod(double x, double y) {
  if (s21_fabs(x) == S21_INF && !S21_isNAN(y)) {
    return S21_NAN;
  } else if (!S21_isNAN(x) && y == 0.0) {
    return S21_NAN;
  } else if (s21_fabs(x) != S21_INF && s21_fabs(y) == S21_INF) {
    return x;
  }

  long long int devided = x / y;
  long double result = (long double)x - devided * (long double)y;

  return result;
}
