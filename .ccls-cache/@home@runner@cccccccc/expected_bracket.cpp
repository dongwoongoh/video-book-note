using namespace std;

int solution(int n, int a, int b) {
  int cnt = 0;
  a--;
  b--;

  while (a != b) {
    a = a / 2;
    b = b / 2;
    cnt++;
  }

  return cnt;
}