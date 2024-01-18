#include "../s21_math.h"

long double s21_sqrt(double x) {
  if (x < 0.0) {
    return S21_NAN;
  } else if (x == 0.0 || x == S21_INF || S21_isNAN(x)) {
    return x;
  }

  long double answer = 1.0;

  while (s21_fabs(answer * answer - x) > S21_EXP) {
    answer = (answer + x / answer) / 2;
  }

  return answer;
}
