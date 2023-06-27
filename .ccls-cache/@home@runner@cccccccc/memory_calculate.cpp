#include <algorithm>
#include <string>
#include <vector>
using namespace std;

vector<int> solution(int e, vector<int> starts) {
  vector<int> answer, v(e + 1, 1), dp(e + 1, 0);
  int s = *min_element(starts.begin(), starts.end());
  for (int i = 2; i <= e; i++)
    for (int j = i; j <= e; j += i)
      v[j]++;
  dp[e] = e;
  for (int i = e - 1; i >= s; i--) {
    if (v[i] >= v[dp[i + 1]])
      dp[i] = i;
    else
      dp[i] = dp[i + 1];
  }
  for (auto s : starts)
    answer.push_back(dp[s]);
  return answer;
}