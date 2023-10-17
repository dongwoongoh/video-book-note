#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> solution(long long begin, long long end) {
  vector<int> answer;
  answer.resize(end - begin + 1, 0);

  for (int i = begin; i <= end; ++i) {
    int num = 0;

    for (int j = 2; j <= sqrt(i); ++j) {

      if (i % j == 0 && i / j <= 10000000) {
        answer[i - begin] = i / j;
        break;
      }
    }
    if (answer[i - begin] == 0) {
      answer[i - begin] = 1;
    }
  }

  if (begin == 1) {
    answer[0] = 0;
  }

  return answer;
}