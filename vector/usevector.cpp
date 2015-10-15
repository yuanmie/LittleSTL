#include "vector.h"
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::size_t;
using std::string;


int main()
{
/*
	vector<int> v1;
	int number;

	while (cin >> number)
		v1.push_back(number);

	cout << v1.size() << " " << v1.capacity() << endl;
	

	v1.reserve(50);
	
	cout << v1.size() << " " << v1.capacity() << endl;

	v1.resize(4);
	cout << v1.size() << " " << v1.capacity() << endl;

	for(vector<int>::iterator first = v1.begin(); first != v1.End(); ++first)
		cout << *first << " ";

	v1.erase(v1.begin(), v1.begin() + 2);
	cout << endl;
	cout << v1.size() << endl;
	for(vector<int>::iterator first = v1.begin(); first != v1.End(); ++first)
		cout << *first << " ";

	vector<int> v2(v1);
	cout << v2.size() << " " << v2.capacity() << endl;

	vector<int> v3(v1.begin(), v1.End());
	cout << v3.size() << " " << v3.capacity() << endl;

	
	vector<int> v4(10, 2);
	cout << v4.size() << " " << v4.capacity() << endl;

	//vector<int> v5(20);
	//cout << v5.size() << " " << v5.capacity() << endl;
	cout << endl;
*/


	vector<string> v;
	string s;
	while(cin >> s)
		v.push_back(s);

	for(vector<string>::iterator iter = v.begin(); iter != v.End();
		++iter)
		cout << *iter << " ";
	cout << endl;
	return 0;
}
