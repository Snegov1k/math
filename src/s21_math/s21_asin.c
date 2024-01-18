#include "../s21_math.h"

long double s21_asin(double x) {
  if (s21_fabs(x) > 1) {
    return S21_NAN;
  }

  if (s21_fabs(x) == 1.0) {
    return x * S21_PI / 2;
  }

  return 2 * s21_atan(x / (1 + s21_sqrt(1 - x * x)));
}
