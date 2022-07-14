
#ifndef CHILD_STRING
#define CHILD_STRING

#include "MyString.h"

class CMyStringEx : public CMyString
{
    public:
        CMyStringEx();
        ~CMyStringEx();
        int find(const char* pszParam);
};

#endif