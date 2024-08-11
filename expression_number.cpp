#include <string>
#include <vector>

using namespace std;

int solution(int n) {
  int answer = 1;

  for (int i = 1; i < n; ++i) {
    int number = i;
    for (int j = i + 1; j < n; ++j) {
      number += j;
      if (number == n)
        ++answer;
      else if (number > n)
        break;
    }
  }

  return answer;
}