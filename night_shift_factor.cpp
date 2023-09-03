#include <queue>
#include <string>
#include <vector>
using namespace std;
long long solution(int n, vector<int> works) {
  long long answer = 0;
  priority_queue<int> q;
  int number;
  for (auto x : works)
    q.push(x);
  while (n-- && !q.empty()) {
    number = q.top();
    q.pop();
    if (number != 1)
      q.push(number - 1);
  }
  while (!q.empty()) {
    answer += (q.top() * q.top());
    q.pop();
  }
  return answer;
}