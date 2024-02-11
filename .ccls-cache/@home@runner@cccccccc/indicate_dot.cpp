#include <vector>
using namespace std;

int func(long long i, long long d) {
  long long left = 1, right = d, mid;
  int res;
  while (left <= right) {
    mid = (left + right) / 2;
    if (mid * mid + i * i <= d * d) {
      left = mid + 1;
      res = mid;
    } else
      right = mid - 1;
  }
  return res;
}

long long solution(int k, int d) {
  long long answer = d / k + 1;
  for (long long i = 0; i < d; i += k)
    answer += func(i, d) / k;
  return answer;
}