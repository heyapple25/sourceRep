
#include "MyStringEx.h"
#include "MyString.h"
#include <iostream>

using namespace std;

int main()
{
	CMyString b("World"), c;
	c = "Hello" + b;

	cout << c.getString() << endl;
	return 0;
}

