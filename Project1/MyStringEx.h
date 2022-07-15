#pragma once

#ifndef CHILD_STRING
#define CHILD_STRING

#include "MyString.h"

class CMyStringEx : public CMyString
{
public:

    //CMyString의 함수를 오버라이딩, 나쁜말 필터를 추가
    //int setString(const char* pszParam);
    int find(const char* pszParam);

public:
    CMyStringEx() : CMyString(){}
    CMyStringEx(const char* pszParam) : CMyString(pszParam){}
    ~CMyStringEx()
    {
        Release();
    }

    void onSetString(char* pszData) override;
};

#endif