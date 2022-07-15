#pragma once

#ifndef CHILD_STRING
#define CHILD_STRING

#include "MyString.h"

class CMyStringEx : public CMyString
{
public:

    //CMyString�� �Լ��� �������̵�, ���۸� ���͸� �߰�
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