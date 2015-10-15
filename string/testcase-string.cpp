#include <iostream>
#include "MString.h"

using namespace std;

int main()
{
  String s;
  cin>> s;
  cout << s << ":" << s.size() << endl;

  char a[] = "Hello", b[] = "World!";
  String s1(a), s2(b);
  cout << "----------" << s1 + s2 << endl;
  cout << s1 << " + " << s2 << " = " << s1 + s2<<endl;

  String s3 = s1 + s2;
  if (s1 == s3)
    cout << "First:s1 == s3" << endl;

  s1 += s2;
  if (s1 == s3)
    cout << "Second s1 == s3" << endl;

  return 0;
}
