#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

string largest_number(vector<string> a) {
  //write your code here
  string ret = "",f="",s="";
  for(int i=0;i<a.size()-1;i++){
    for(int j=i+1;j<a.size();j++){
      f = a[i]+a[j];
      s = a[j]+a[i];
      if(f>s)continue;
      else{
        swap(a[i],a[j]);
      }
    }
  }

  for(int i=0;i<a.size();i++)ret+=a[i];

  return ret;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a)<<"\n";
}
