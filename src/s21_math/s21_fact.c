#include "../s21_math.h"

long double s21_fact(double x) {
  double result = 1;

  for (int i = 2; i <= x; i++) {
    result *= i;
  }

  return result;
}
