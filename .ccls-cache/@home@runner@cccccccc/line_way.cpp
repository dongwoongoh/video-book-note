#include <algorithm>
#include <vector>

std::vector<int> solution(int n, long long k) {
  std::vector<int> answer;
  std::vector<int> numbers(n);
  long long factorial = 1;

  for (int i = 0; i < n; ++i) {
    numbers[i] = i + 1;
    factorial *= (i + 1);
  }

  k -= 1;

  while (n > 0) {
    factorial /= n;
    int index = k / factorial;
    answer.push_back(numbers[index]);

    numbers.erase(numbers.begin() + index);
    k %= factorial;
    n--;
  }

  return answer;
}
