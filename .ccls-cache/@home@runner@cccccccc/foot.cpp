#include <vector>

using namespace std;

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};
int N, M;

bool safe(int y, int x) { return y >= 0 && x >= 0 && y < N && x < M; }

bool cant_move(vector<vector<int>> &board, int y, int x) {
  for (int d = 0; d < 4; ++d) {
    int ny = y + dy[d];
    int nx = x + dx[d];

    if (safe(ny, nx) && board[ny][nx])
      return false;
  }
  return true;
}

pair<bool, int> func(vector<vector<int>> &board, int y1, int x1, int y2,
                     int x2) {
  if (cant_move(board, y1, x1))
    return {false, 0};

  pair<bool, int> ret = {false, 0};
  if (board[y1][x1]) {
    int minT = 1e9, maxT = 0;
    for (int d = 0; d < 4; ++d) {
      int ny = y1 + dy[d];
      int nx = x1 + dx[d];

      if (!safe(ny, nx) || !board[ny][nx])
        continue;

      board[y1][x1] = 0;
      auto [win, move] = func(board, y2, x2, ny, nx);
      board[y1][x1] = 1;

      if (!win) {
        ret.first = true;
        minT = min(minT, move);
      } else if (!ret.first) {
        maxT = max(maxT, move);
      }
    }

    ret.second = ret.first ? minT + 1 : maxT + 1;
  }

  return ret;
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
  N = board.size(), M = board[0].size();
  return func(board, aloc[0], aloc[1], bloc[0], bloc[1]).second;
}