#include <vector>
using namespace std;

int solution(vector<int> a) {
  int answer = 0;
  int len = a.size();
  vector<int> left(len);
  vector<int> right(len);

  int MIN = a[0];
  for (int i = 0; i < len; i++) {
    if (MIN > a[i])
      MIN = a[i];
    left[i] = MIN;
  }

  MIN = a[len - 1];
  for (int i = len - 1; i >= 0; i--) {
    if (MIN > a[i])
      MIN = a[i];
    right[i] = MIN;
  }

  for (int i = 0; i < len; i++) {
    if (a[i] <= left[i] || a[i] <= right[i])
      answer++;
  }
  return answer;
}