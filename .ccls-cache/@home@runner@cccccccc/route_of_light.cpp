#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int N, M;
bool Visit[510][510][4];
vector<string> MAP;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int Change_Dir(char C, int Dir) {
  if (C == 'L') {
    if (Dir == 0)
      return 3;
    if (Dir == 1)
      return 2;
    if (Dir == 2)
      return 0;
    if (Dir == 3)
      return 1;
  }

  if (Dir == 0)
    return 2;
  if (Dir == 1)
    return 3;
  if (Dir == 2)
    return 1;
  if (Dir == 3)
    return 0;
}

int Simulation(int x, int y, int Dir, int Len) {
  if (Visit[x][y][Dir] == true)
    return Len;

  Visit[x][y][Dir] = true;

  int nx = x;
  int ny = y;
  int nd = Dir;

  if (MAP[x][y] != 'S')
    nd = Change_Dir(MAP[x][y], Dir);
  nx = x + dx[nd];
  ny = y + dy[nd];
  if (nx < 0)
    nx = N - 1;
  if (ny < 0)
    ny = M - 1;
  if (nx == N)
    nx = 0;
  if (ny == M)
    ny = 0;

  return Simulation(nx, ny, nd, Len + 1);
}

vector<int> solution(vector<string> grid) {
  vector<int> answer;
  N = grid.size();
  M = grid[0].length();
  MAP = grid;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      for (int k = 0; k < 4; k++) {
        int Result = Simulation(i, j, k, 0);
        if (Result != 0)
          answer.push_back(Result);
      }
    }
  }
  sort(answer.begin(), answer.end());
  return answer;
}
