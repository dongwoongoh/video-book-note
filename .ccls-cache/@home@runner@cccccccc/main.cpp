#include <iostream>
#include <math.h>
using namespace std;

int max_mul;

int count_mul(int n) { return log(n) / log(3); }

int solve(int add, int mul, int n) {
  int result = 0;

  if (2 * max_mul < add) {
    return 0;
  }

  if (n == 1) {
    return 1;
  }

  if (n % 3 == 0) {
    if (2 * (mul + 1) <= add) {
      result += solve(add, mul + 1, n / 3);
    }

    result += solve(add + 3, mul, n - 3);
  } else if (n % 3 != 0) {
    result += solve(add + (n % 3), mul, n - (n % 3));
  }

  return result;
}

int solution(int n) {
  int answer = 0;

  max_mul = count_mul(n);
  answer = solve(0, 0, n);

  return answer;
}
