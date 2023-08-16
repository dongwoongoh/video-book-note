#include <algorithm>
#include <map>
#include <string>
#include <vector>
using namespace std;

struct PAGE {
  int Idx;
  int Basic_Point;
  vector<string> Out_Link_List;
  double Link_Point;
  double Match_Point;
};

string Word;
map<string, int> Page_Num;
vector<PAGE> Page;

bool Cmp(PAGE A, PAGE B) {
  if (A.Match_Point >= B.Match_Point) {
    if (A.Match_Point == B.Match_Point) {
      if (A.Idx < B.Idx) {
        return true;
      }
      return false;
    }
    return true;
  }
  return false;
}

string To_Upper(string Str) {
  transform(Str.begin(), Str.end(), Str.begin(), ::toupper);
  return Str;
}

string Find_URL(string Str) {
  string Target = "<META PROPERTY=\"OG:URL\" CONTENT=\"HTTPS://";
  int Idx = Str.find(Target);
  Idx += Target.length();
  string URL = "";
  while (Str[Idx] != '\"')
    URL += Str[Idx++];
  return URL;
}

int Find_Word(string Str) {
  string Target1 = "<BODY>";
  string Target2 = "/<BODY>";
  int Idx1 = Str.find(Target1);
  Idx1 += Target1.length();
  int Idx2 = Str.find(Target2);
  Str = Str.substr(Idx1, Idx2 - Idx1);

  string Cur = "";
  int Cnt = 0;
  for (int i = 0; i < Str.length(); i++) {
    if (isalpha(Str[i]) == 0) {
      if (Cur == Word)
        Cnt++;
      Cur = "";
    } else
      Cur += Str[i];
  }
  return Cnt;
}

vector<string> Find_Out_Link(string Str) {
  vector<string> Result;
  string Target = "<A HREF=\"HTTPS://";
  int Idx = Str.find(Target);
  while (Idx != -1) {
    Idx += Target.length();
    string Cur = "";
    while (Str[Idx] != '\"')
      Cur += Str[Idx++];
    Result.push_back(Cur);
    Str = Str.substr(Idx);
    Idx = Str.find(Target);
  }
  return Result;
}

void Calculate_Link_Point() {
  for (int i = 0; i < Page.size(); i++) {
    vector<string> V = Page[i].Out_Link_List;
    int Size = V.size();
    for (int j = 0; j < V.size(); j++) {
      string Str = V[j];
      if (Page_Num[Str] == 0)
        continue;
      int Target_Idx = Page_Num[Str] - 1;
      Page[Target_Idx].Link_Point +=
          ((double)Page[i].Basic_Point / (double)Size);
    }
  }
  for (int i = 0; i < Page.size(); i++) {
    Page[i].Match_Point =
        (double)Page[i].Basic_Point + (double)Page[i].Link_Point;
  }
  sort(Page.begin(), Page.end(), Cmp);
}

void Function(vector<string> V) {
  for (int i = 0; i < V.size(); i++) {
    string Str = To_Upper(V[i]);
    string URL = Find_URL(Str);
    Page_Num[URL] = i + 1;
    int BP = Find_Word(Str);
    vector<string> Out_Link = Find_Out_Link(Str);
    Page.push_back({i, BP, Out_Link, 0.0, 0.0});
  }
  Calculate_Link_Point();
}

int solution(string word, vector<string> pages) {
  int answer = 0;
  Word = To_Upper(word);
  Function(pages);
  answer = Page[0].Idx;
  return answer;
}
