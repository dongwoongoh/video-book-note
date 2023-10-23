#include <cmath>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long begin, long long end) {
  vector<int> answer;

  for (long long i = begin; i <= end; i++) {
    if (i == 1) {
      answer.push_back(0);
      continue;
    }
    long long n = 1;
    for (long long j = 2; j <= sqrt(i); j++) {
      if (i % j == 0 && i / j <= 10000000) {
        n = j;
        break;
      }
    }

    if (n == 1) {
      answer.push_back(1);
    } else {
      answer.push_back(i / n);
    }
  }

  return answer;
}