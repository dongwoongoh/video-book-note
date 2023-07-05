#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool isOutOfBounds(pair<long long, long long> row,
                   pair<long long, long long> col, int n, int m) {
  return row.first >= n || row.second < 0 || col.first >= m || col.second < 0;
}

long long solution(int n, int m, int x, int y, vector<vector<int>> queries) {
  pair<long long, long long> row, col;
  row.first = x, row.second = x;
  col.first = y, col.second = y;

  for (int i = queries.size() - 1; i >= 0; i--) {
    int dx = queries[i][1];

    switch (queries[i][0]) {
    case 0:
      if (col.first != 0) {
        col.first += dx;
      }

      col.second = min(col.second + dx, (m - 1) * 1LL);

      break;
    case 1:
      col.first = max(col.first - dx, (long long)0);

      if (col.second != m - 1) {
        col.second -= dx;
      }

      break;
    case 2:
      if (row.first != 0) {
        row.first += dx;
      }

      row.second = min(row.second + dx, (n - 1) * 1LL);

      break;
    case 3:
      row.first = max(row.first - dx, (long long)0);

      if (row.second != n - 1) {
        row.second -= dx;
      }

      break;
    }

    if (isOutOfBounds(row, col, n, m)) {
      return 0;
    }
  }

  return (row.second - row.first + 1) * (col.second - col.first + 1);
}