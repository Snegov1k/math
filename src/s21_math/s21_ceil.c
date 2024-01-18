#include "../s21_math.h"

long double s21_ceil(double x) {
  if (s21_fabs(x) == S21_INF) {
    return x;
  } else if (S21_isNAN(x)) {
    return S21_NAN;
  }

  int temp = (int)x;
  return (x == temp) ? x
         : (x < 0)   ? (long double)temp
                     : (long double)(temp + 1);
}
