// qualA_a.cpp
// CODE FESTIVAL 2015 予選A A - CODE FESTIVAL 2015

#include <iostream>
#include <string>
using namespace std;


int main() {

  string str;

  cin >> str;
  str.replace(str.end() - 4, str.end(), "2015");
  cout << str << endl;

  return 0;
}
