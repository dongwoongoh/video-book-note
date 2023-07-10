#include <queue>
#include <string>
#include <vector>

using namespace std;

int MAP[102][102];

vector<vector<int>> X2rectangle;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool rectcheck(int nx, int ny) {
  for (auto figure : X2rectangle) {
    if (figure[0] < nx && figure[1] < ny && figure[2] > nx && figure[3] > ny) {
      return true;
    }
  }
  return false;
}

int BFS_Move(int characterX, int characterY, int itemX, int itemY) {
  queue<pair<int, pair<int, int>>> Q;
  Q.push(make_pair(1, make_pair(characterX, characterY)));
  MAP[characterX][characterY] = 1;
  while (!Q.empty()) {
    int cost = Q.front().first;
    int x = Q.front().second.first;
    int y = Q.front().second.second;
    Q.pop();

    if (x == itemX && y == itemY) {
      return (cost - 1) / 2;
    }

    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (MAP[nx][ny] < 0 && !rectcheck(nx, ny)) {
        MAP[nx][ny] = cost;
        Q.push(make_pair(cost + 1, make_pair(nx, ny)));
      }
    }
  }
  return -1;
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY,
             int itemX, int itemY) {

  for (auto figure : rectangle) {
    for (int i = figure[0] * 2; i <= figure[2] * 2; i++)
      MAP[i][figure[1] * 2] = -1;
    for (int i = figure[1] * 2; i <= figure[3] * 2; i++)
      MAP[figure[0] * 2][i] = -1;
    for (int i = figure[0] * 2; i <= figure[2] * 2; i++)
      MAP[i][figure[3] * 2] = -1;
    for (int i = figure[1] * 2; i <= figure[3] * 2; i++)
      MAP[figure[2] * 2][i] = -1;
    X2rectangle.push_back(
        {figure[0] * 2, figure[1] * 2, figure[2] * 2, figure[3] * 2});
  }
  return BFS_Move(characterX * 2, characterY * 2, itemX * 2, itemY * 2);
}