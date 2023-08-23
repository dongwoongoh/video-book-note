#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
  int answer = 0;

  int answers[m][n];

  vector<pair<int, int>> puddle;

  for (int i = 0; i < puddles.size(); i++) {
    puddle.push_back(make_pair(puddles[i][0] - 1, puddles[i][1] - 1));
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (i == 0 && j == 0) {
        answers[i][j] = 1;
      } else if (find(puddle.begin(), puddle.end(), make_pair(i, j)) !=
                 puddle.end()) {
        answers[i][j] = 0;
      } else if (i == 0) {
        answers[i][j] = answers[i][j - 1] % 1000000007;
      } else if (j == 0) {
        answers[i][j] = answers[i - 1][j] % 1000000007;
      } else {
        answers[i][j] = (answers[i - 1][j] + answers[i][j - 1]) % 1000000007;
      }
    }
  }
  answer = answers[m - 1][n - 1];
  return answer;
}