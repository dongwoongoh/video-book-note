#include <queue>
#include <string>
#include <vector>
#define MAX 100

using namespace std;

int n, m;
int answer = 2147000000;
pair<int, int> start;
pair<int, int> goal;
bool visited[MAX][MAX];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs(vector<string> &board) {
  queue<pair<pair<int, int>, int>> q;

  q.push({{start.first, start.second}, 0});
  visited[start.first][start.second] = true;

  while (!q.empty()) {
    int cx = q.front().first.first;
    int cy = q.front().first.second;
    int cnt = q.front().second;
    q.pop();

    if (cx == goal.first && cy == goal.second) {
      answer = min(answer, cnt);
    }

    for (int i = 0; i < 4; i++) {
      int nx = cx + dx[i];
      int ny = cy + dy[i];

      if ((nx < 0 || n <= nx || ny < 0 || m <= ny) || board[nx][ny] == 'D')
        continue;

      while (true) {
        nx += dx[i];
        ny += dy[i];

        if ((nx < 0 || n <= nx || ny < 0 || m <= ny) || board[nx][ny] == 'D') {
          nx -= dx[i];
          ny -= dy[i];
          break;
        }
      }

      if (visited[nx][ny])
        continue;

      q.push({{nx, ny}, cnt + 1});
      visited[nx][ny] = true;
    }
  }
}

int solution(vector<string> board) {
  n = board.size();
  m = board[0].size();

  int findCnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (findCnt == 2)
        break;

      if (board[i][j] == 'R') {
        findCnt++;
        start = {i, j};
      } else if (board[i][j] == 'G') {
        findCnt++;
        goal = {i, j};
      }
    }
  }

  bfs(board);

  if (answer == 2147000000)
    return -1;
  return answer;
}