#include <string>
#include <vector>

using namespace std;

int Find_Last_Zero(string Str) {
  for (int i = Str.length() - 1; i >= 0; i--) {
    if (Str[i] == '0')
      return i;
  }
  return -1;
}

vector<string> solution(vector<string> s) {
  vector<string> answer;
  for (int i = 0; i < s.size(); i++) {
    string Str = "";
    int Cnt = 0;
    for (int j = 0; j < s[i].length(); j++) {
      Str += s[i][j];
      if (Str.length() >= 3) {
        if (Str.substr(Str.length() - 3, 3) == "110") {
          Cnt++;
          Str.erase(Str.length() - 3, Str.length());
        }
      }
    }

    int LZI = Find_Last_Zero(Str);
    if (LZI == -1) {
      string Result = "";
      while (Cnt--)
        Result += "110";
      Result += Str;
      answer.push_back(Result);
    } else {
      string Result = "";
      for (int j = 0; j < Str.length(); j++) {
        if (j == LZI) {
          Result += Str[j];
          while (Cnt--)
            Result += "110";
        } else
          Result += Str[j];
      }
      answer.push_back(Result);
    }
  }
  return answer;
}
