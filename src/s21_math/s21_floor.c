#include "../s21_math.h"

long double s21_floor(double x) {
  if (s21_fabs(x) == S21_INF) {
    return x;
  } else if (S21_isNAN(x)) {
    return S21_NAN;
  }

  long double temp = (long long int)x;
  return (x != temp && x < 0) ? temp - 1 : temp;
}
