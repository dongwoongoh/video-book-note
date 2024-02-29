#include  < map>
#include  < string>
#include  < vector>

using namespace std;

int Num = 1;
map<string, int> Dict;

void Make_Default_Dictionary() {
for
   (char C = 'A'; C <= 'Z'; C++) {
    string Str = "";
     Str += C;
    Dict[Str] = Num++;
  }
}

void Compression(string Str, vector<int> &answer) {
  string Cur = "";
for
   (int i = 0; i < Str.length(); i++) {
    Cur += Str[i];
    if
       (Dict[Cur] == 0) {
        Dict[Cur] = Num++;
        Cur = Cur.substr(0, Cur.length() - 1);
        answer.push_back(Dict[Cur]);
        Cur = "";
        i--;
      }
  }
answer.push_back(Dict[Cur]);
}

vector<int> solution(string msg) {
  vector<int> answer;
  Make_Default_Dictionary();
  Compression(msg, answer);
  return answer;
}
