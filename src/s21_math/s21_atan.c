#include "../s21_math.h"

long double s21_atan(double x) {
  long double res = 0.0;

  if (x == 0.0)
    res = 0.0;
  else if (x == -S21_INF)
    res = -S21_PI / 2;
  else if (x == S21_INF)
    res = S21_PI / 2;
  else if (x == -1.0)
    res = -S21_PI / 4.0;
  else if (x == 1.0)
    res = S21_PI / 4.0;
  else if (S21_isNAN(x))
    res = S21_NAN;
  else {
    int in_range = (x > -1 && x < 1);
    res = in_range ? x : 1.0 / x;
    int precision = 150;

    if ((x > 0.9 && x < 1.1) || (x < -0.9 && x > -1.1)) precision = 10000;

    for (int i = 1; i < precision; i++) {
      long double exponent = (1 + 2 * i) * (in_range ? 1 : -1);
      long double step = s21_pow(x, exponent) / (1 + 2 * i);
      res += (i & 1 ? -1 : 1) * step;
    }

    if (!in_range) res = (S21_PI * s21_fabs(x) / (2.0 * x)) - res;
  }
  return res;
}
