#include <algorithm>
#include <string>
#include <vector>
using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
  string answer = "";

  int start_t = 540, wait_t = 0, wait_h = 0, wait_m = 0;
  int cnt = 0;
  bool flag = true;

  sort(timetable.begin(), timetable.end(), greater<string>());

  for (int i = 0; i < n; i++) {
    cnt = 0;

    while (cnt < m) {
      if (!timetable.empty()) {
        wait_h = stoi(timetable.back().substr(0, 2));
        wait_m = stoi(timetable.back().substr(3, 2));
        wait_t = (60 * wait_h) + wait_m;

        if (wait_t <= start_t) {
          if (i == n - 1 && cnt == m - 1) {
            start_t = wait_t - 1;
            flag = false;
            break;
          } else {
            cnt++;
            timetable.pop_back();
          }
        } else {
          if (i == n - 1) {
            start_t = 540 + (n - 1) * t;
            flag = false;
            break;
          }
          start_t += t;
          break;
        }
      } else {
        start_t = 540 + (n - 1) * t;
        flag = false;
        break;
      }
    }
    if (flag = false)
      break;
    if (cnt == m)
      start_t += t;
  }

  if (start_t / 60 < 10)
    answer = "0" + to_string(start_t / 60);
  else
    answer = to_string(start_t / 60);

  answer += ":";

  if (start_t % 60 < 10)
    answer += "0" + to_string(start_t % 60);
  else
    answer += to_string(start_t % 60);

  return answer;
}
