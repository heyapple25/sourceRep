#pragma once

#ifndef STRING_H
#define STRING_H

#include "stdafx.h"

/*
���ڿ��� �����ϸ� ���������� �ʿ��� �޸𸮸�
�ڵ����� �����Ҵ��ϰ� ���ڿ��� ����
������ �ڵ����� ����
*/
class CMyString
{
private:
    //���ڿ��� �����ϱ� ���� �����Ҵ��� �޸𸮸� ����Ű�� ������
    char* m_pszData;

    //����� ���ڿ��� ����
    int m_nLength;

public:
    int setString(const char* pszParam);
    int append(const char* pszParam);

    //�迭 ������
    char operator[](int nIndex) const;
    char& operator[](int nIndex);

    const char* getString() const;
    int getLength() const;

    virtual void onSetString(char* pszData);

    void Release();
    //�Ű������� ���� ���ڿ��� ���̸� ����, ��� ���ڿ��� ���̸� �˰���� �� 
    //getLength �Լ� ȣ��
    int strlen(const char* pszParam);

public:

    //���Կ����� �����ε�
    CMyString& operator=(const CMyString& op) {
        this->setString(op.getString());
        return *this;
    }

    //������ �����ε�
    friend CMyString operator+(const char* pszParam, const CMyString& strParam);
    
    const char* operator+(const CMyString& rhs);
     
    CMyString& operator+=(const CMyString& rhs);
    int operator==(const CMyString& rhs);
    int operator!=(const CMyString& rhs);

    //���Ǵ� ��ȯ
    operator const char* () { return getString(); }

    CMyString() : m_pszData(nullptr), m_nLength(0) {}
    explicit CMyString(const char* pszParam) : m_nLength(strlen(pszParam)) {
        setString(pszParam);
    }

    //���������
    CMyString(const CMyString& copyConstructor) {
        this->setString(copyConstructor.getString());
    }

    //�̵�������
    CMyString(CMyString&& rhs);

    virtual ~CMyString() {
    }

};

#endif