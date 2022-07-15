#pragma once

#ifndef STRING_H
#define STRING_H

#include "stdafx.h"

/*
문자열을 설정하면 내부적으로 필요한 메모리를
자동으로 동적할당하고 문자열을 저장
해제도 자동으로 수행
*/
class CMyString
{
private:
    //문자열을 저장하기 위해 동적할당한 메모리를 가리키는 포인터
    char* m_pszData;

    //저장된 문자열의 길이
    int m_nLength;

public:
    int setString(const char* pszParam);
    int append(const char* pszParam);

    //배열 연산자
    char operator[](int nIndex) const;
    char& operator[](int nIndex);

    const char* getString() const;
    int getLength() const;

    virtual void onSetString(char* pszData);

    void Release();
    //매개변수로 들어온 문자열의 길이를 구함, 멤버 문자열의 길이를 알고싶을 시 
    //getLength 함수 호출
    int strlen(const char* pszParam);

public:

    //대입연산자 오버로딩
    CMyString& operator=(const CMyString& op) {
        this->setString(op.getString());
        return *this;
    }

    //연산자 오버로딩
    friend CMyString operator+(const char* pszParam, const CMyString& strParam);
    
    const char* operator+(const CMyString& rhs);
     
    CMyString& operator+=(const CMyString& rhs);
    int operator==(const CMyString& rhs);
    int operator!=(const CMyString& rhs);

    //허용되는 반환
    operator const char* () { return getString(); }

    CMyString() : m_pszData(nullptr), m_nLength(0) {}
    explicit CMyString(const char* pszParam) : m_nLength(strlen(pszParam)) {
        setString(pszParam);
    }

    //복사생성자
    CMyString(const CMyString& copyConstructor) {
        this->setString(copyConstructor.getString());
    }

    //이동생성자
    CMyString(CMyString&& rhs);

    virtual ~CMyString() {
    }

};

#endif