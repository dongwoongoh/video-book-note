#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<pair<int, int>> dir = {
    make_pair(-1, 0), make_pair(-1, 1), make_pair(0, 1),  make_pair(1, 1),
    make_pair(1, 0),  make_pair(1, -1), make_pair(0, -1), make_pair(-1, -1)};

int isWin(int y, int x, char turn, vector<string> board);
int solution(vector<string> board) {
  int answer = 1;
  int allX = 0, allO = 0, winO = 0, winX = 0;
  for (string s : board) {
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == 'X')
        allX += 1;
      else if (s[i] == 'O')
        allO += 1;
    }
  }
  if (allX > allO || allO - allX > 1)
    return 0;
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board.size(); j++) {
      if (board[i][j] == 'O') {
        winO += isWin(i, j, 'O', board);

        if (winX && winO)
          return 0;
      } else if (board[i][j] == 'X') {
        winX += isWin(i, j, 'X', board);

        if (winO && winX)
          return 0;
      }
    }
  }

  if (((winX == winO) && (winO == 0)) || ((winX / 2 == 1) && (allO == allX)) ||
      ((winO / 2 == 1) && (allO - allX == 1)) ||
      ((allO == 5) && (winO / 2 == 2)))
    return 1;
  else
    return 0;
}

int isWin(int y, int x, char turn, vector<string> board) {
  int cnt = 0;

  for (int d = 0; d < 8; d++) {
    int i;

    for (i = 1; i <= 2; i++) {
      int nextY = y + (dir[d].first * i), nextX = x + (dir[d].second * i);

      if ((nextX >= 0 && nextX < 3) && (nextY >= 0 && nextY < 3)) {
        if (board[nextY][nextX] != turn)
          break;
      } else
        break;
    }

    if (i == 3)
      cnt += 1;
  }

  return cnt;
}