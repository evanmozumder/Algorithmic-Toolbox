#include<bits/stdc++.h>
using namespace std;

int ascii(string s){
  int sum=0;
  for(int i=0;i<s.size();i++)sum+=(int)s[i];

  return sum;
}

int main() {
  vector<string>ch;
  ch.push_back("9");
  ch.push_back("23");
  cout<<int(ch[0][0])<<endl;
  string f = "330",s="303";
  cout<<(f>s)<<endl;
}