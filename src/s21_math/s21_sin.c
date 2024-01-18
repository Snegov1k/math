#include "../s21_math.h"

long double s21_sin(double x) {
  while (s21_fabs(x) - 2 * S21_PI > 0) {
    x += 2 * S21_PI * x / s21_fabs(x) * -1;
  }

  long double result = x;
  int sign = -1;

  for (int i = 3; i <= 100; i += 2) {
    result += sign * s21_pow(x, i) / s21_fact(i);
    sign *= -1;
  }

  return result;
}
