
#include "MyStringEx.h"
#include "MyString.h"
#include <iostream>

using namespace std;

int main()
{
    CMyStringEx strTest;
    strTest.setString("I am a boy");
    cout << strTest.getString() << endl;

    int nIndex = strTest.find("boy");
    cout << "Index : " << nIndex << endl;

    return 0;
}

