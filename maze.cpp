#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;
typedef pair<int, int> point;

int mat[101][101];
bool vis[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int answer, N, M;
point s, e, l;
int bfs(point src, point dest) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++)
      vis[i][j] = false;
  }
  queue<pair<point, int>> q;
  q.push(make_pair(src, 0));
  vis[src.first][src.second] = true;
  while (!q.empty()) {
    int curx = q.front().first.first;
    int cury = q.front().first.second;
    int curt = q.front().second;
    q.pop();
    for (int k = 0; k < 4; k++) {
      if (curx + dx[k] == dest.first && cury + dy[k] == dest.second)
        return curt + 1;
      if (curx + dx[k] >= 0 && curx + dx[k] < N && cury + dy[k] >= 0 &&
          cury + dy[k] < M) {
        if (!vis[curx + dx[k]][cury + dy[k]] &&
            mat[curx + dx[k]][cury + dy[k]] != 1) {
          vis[curx + dx[k]][cury + dy[k]] = true;
          q.push(make_pair(make_pair(curx + dx[k], cury + dy[k]), curt + 1));
        }
      }
    }
  }
  return 0;
}

int solution(vector<string> maps) {
  int cnt;
  N = maps.size();
  M = maps[0].size();
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (maps[i][j] == 'S') {
        s = make_pair(i, j);
        mat[i][j] = 2;
      } else if (maps[i][j] == 'E') {
        e = make_pair(i, j);
        mat[i][j] = 3;
      } else if (maps[i][j] == 'L') {
        l = make_pair(i, j);
        mat[i][j] = 4;
      } else if (maps[i][j] == 'O') {
        mat[i][j] = 0;
      } else if (maps[i][j] == 'X') {
        mat[i][j] = 1;
      }
    }
  }

  if (!(cnt = bfs(s, l)))
    return -1;
  else
    answer += cnt;
  if (!(cnt = bfs(l, e)))
    return -1;
  else
    answer += cnt;

  return answer;
}