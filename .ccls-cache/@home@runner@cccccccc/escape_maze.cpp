#include <string>
#include <vector>

using namespace std;

bool OOB(int x, int y, int n, int m) {
  if (0 < x && x <= n && 0 < y && y <= m) {
    return false;
  } else {
    return true;
  }
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
  string answer = "";

  string command = "dlru";
  vector<int> dx{1, 0, 0, -1};
  vector<int> dy{0, -1, 1, 0};

  bool flag = false;

  int dist = abs(x - r) + abs(y - c);
  if ((k - dist) % 2 != 0 || dist > k) {
    return "impossible";
  }

  while (k--) {
    for (int d = 0; d < 4; d++) {
      printf("i: %d, k: %d \n", d, k);
      int nx = x + dx[d];
      int ny = y + dy[d];

      if (OOB(nx, ny, n, m))
        continue;

      int remain = abs(nx - r) + abs(ny - c);
      if (remain > k)
        continue;

      x = nx;
      y = ny;
      answer += command[d];
      break;
    }
  }
  return answer;
}