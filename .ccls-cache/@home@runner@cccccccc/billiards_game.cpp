#include <string>
#include <vector>

using namespace std;

int pow(int n) { return n * n; }

vector<int> solution(int m, int n, int startX, int startY,
                     vector<vector<int>> balls) {
  vector<int> answer;
  int cnt = balls.size();
  for (int i = 0; i < cnt; i++) {
    int len, a, b;
    if (balls[i][0] == startX) {
      a = abs(startY - balls[i][1]);
      b = 2 * min(m - startX, startX);
      if (startY > balls[i][1])
        len = pow(a + 2 * (n - startY));
      else
        len = pow(a + 2 * startY);
    } else if (balls[i][1] == startY) {
      a = abs(startX - balls[i][0]);
      b = 2 * min(n - startY, startY);
      if (startX > balls[i][0])
        len = pow(a + 2 * (m - startX));
      else
        len = pow(a + 2 * startX);
    } else {
      a = min(startX + balls[i][0], 2 * m - startX - balls[i][0]);
      b = abs(startY - balls[i][1]);
      len = pow(a) + pow(b);
      a = min(startY + balls[i][1], 2 * n - startY - balls[i][1]);
      b = abs(startX - balls[i][0]);
    }
    len = min(len, pow(a) + pow(b));
    answer.push_back(len);
  }
  return answer;
}