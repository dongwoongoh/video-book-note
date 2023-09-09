#include <queue>
#include <string>
#include <vector>

using namespace std;

struct ROBOT {
  int x;
  int y;
  int Dir;
  int Cnt;
};

int N;
bool Visit[110][110][4];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int Reverse(int Dir) {
  if (Dir == 0)
    return 1;
  else if (Dir == 1)
    return 0;
  else if (Dir == 2)
    return 3;
  else if (Dir == 3)
    return 2;
}

int BFS(vector<vector<int>> board) {
  queue<ROBOT> Q;
  Q.push({0, 1, 1, 0});
  Visit[0][0][0] = Visit[0][1][1] = true;

  while (Q.empty() == 0) {
    int x = Q.front().x;
    int y = Q.front().y;
    int Dir = Q.front().Dir;
    int Cnt = Q.front().Cnt;
    int xx = x + dx[Dir];
    int yy = y + dy[Dir];
    Q.pop();

    if ((x == N - 1 && y == N - 1) || (xx == N - 1 && yy == N - 1))
      return Cnt;

    for (int i = 0; i < 4; i++) {
      if (i == Dir) {
        int nx = xx + dx[i];
        int ny = yy + dy[i];
        if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
          if (board[nx][ny] == 0 && Visit[nx][ny][Reverse(Dir)] == false &&
              Visit[xx][yy][Dir] == false) {
            Visit[x][y][Reverse(Dir)] = true;
            Visit[xx][yy][Dir] = true;
            Q.push({xx, yy, Dir, Cnt + 1});
          }
        }
      } else if (i == Reverse(Dir)) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
          if (board[nx][ny] == 0 && Visit[nx][ny][Dir] == false &&
              Visit[x][y][Reverse(Dir)] == false) {
            Visit[nx][ny][Dir] = true;
            Visit[x][y][Reverse(Dir)] = true;
            Q.push({nx, ny, Dir, Cnt + 1});
          }
        }
      } else {
        int nx = x + dx[i];
        int ny = y + dy[i];
        int nxx = xx + dx[i];
        int nyy = yy + dy[i];
        if (nx >= 0 && ny >= 0 && nx < N && ny < N && nxx >= 0 && nyy >= 0 &&
            nxx < N && nyy < N) {
          if (board[nx][ny] == 0 && board[nxx][nyy] == 0) {
            if (Visit[nx][ny][Dir] == false &&
                Visit[nxx][nyy][Reverse(Dir)] == false) {
              Visit[nx][ny][Dir] = true;
              Visit[nxx][nyy][Reverse(Dir)] = true;
              Q.push({nx, ny, Dir, Cnt + 1});
            }
          }
        }
      }
    }

    if (Dir == 0 || Dir == 1) {
      int cx = x - 1;
      int cxx = xx - 1;
      if (cx >= 0 && cxx >= 0 && cx < N && cxx < N) {
        if (board[cx][y] == 0 && board[cxx][yy] == 0) {
          if (Visit[x][y][3] == false && Visit[cx][y][2] == false) {
            Visit[x][y][3] = true;
            Visit[cx][y][2] = true;
            Q.push({x, y, 3, Cnt + 1});
          }

          if (Visit[cxx][yy][2] == false && Visit[xx][yy][3] == false) {
            Visit[cxx][yy][2] = true;
            Visit[xx][yy][3] = true;
            Q.push({cxx, yy, 2, Cnt + 1});
          }
        }
      }

      cx = x + 1;
      cxx = xx + 1;
      if (cx >= 0 && cxx >= 0 && cx < N && cxx < N) {
        if (board[cx][y] == 0 && board[cxx][yy] == 0) {
          if (Visit[x][y][2] == false && Visit[cx][y][3] == false) {
            Visit[x][y][2] = true;
            Visit[cx][y][3] = true;
            Q.push({x, y, 2, Cnt + 1});
          }

          if (Visit[cxx][yy][3] == false && Visit[xx][yy][2] == false) {
            Visit[cxx][yy][3] = true;
            Visit[xx][yy][2] = true;
            Q.push({cxx, yy, 3, Cnt + 1});
          }
        }
      }
    } else {
      int cy = y - 1;
      int cyy = yy - 1;
      if (cy >= 0 && cyy >= 0 && cy < N && cyy < N) {
        if (board[x][cy] == 0 && board[xx][cyy] == 0) {
          if (Visit[x][y][1] == false && Visit[x][cy][0] == false) {
            Visit[x][y][1] = true;
            Visit[x][cy][0] = true;
            Q.push({x, y, 1, Cnt + 1});
          }

          if (Visit[xx][yy][1] == false && Visit[xx][cyy][0] == false) {
            Visit[xx][yy][1] = true;
            Visit[xx][cyy][0] = true;
            Q.push({xx, cyy, 0, Cnt + 1});
          }
        }
      }

      cy = y + 1;
      cyy = yy + 1;
      if (cy >= 0 && cyy >= 0 && cy < N && cyy < N) {
        if (board[x][cy] == 0 && board[xx][cyy] == 0) {
          if (Visit[x][y][0] == false && Visit[x][cy][1] == false) {
            Visit[x][y][0] = true;
            Visit[x][cy][1] = true;
            Q.push({x, y, 0, Cnt + 1});
          }

          if (Visit[xx][yy][0] == false && Visit[xx][cyy][1] == false) {
            Visit[xx][yy][0] = true;
            Visit[xx][cyy][1] = true;
            Q.push({xx, cyy, 1, Cnt + 1});
          }
        }
      }
    }
  }
  return 0;
}

int solution(vector<vector<int>> board) {
  N = board.size();
  int answer = BFS(board);
  return answer;
}