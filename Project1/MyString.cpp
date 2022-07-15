#include "MyString.h"


CMyString operator+(const char* pszParam, const CMyString& strParam)
{
    //friend ������ �߱� ������ private�� ������ ������
    CMyString strResult(pszParam);
    strResult.append(strParam.m_pszData);

    return strResult;
}

CMyString::CMyString(CMyString&& rhs) :m_pszData(nullptr), m_nLength(0)
{
    cout << "CMyString �̵������� ȣ��" << endl;
}

void TestFunc(const CMyString& strParam)
{
    cout << strParam[0] << endl;
    cout << strParam[strParam.getLength() - 2] << endl;
}


int CMyString::operator==(const CMyString& rhs)
{
    if (strlen(m_pszData) == 0 || strlen(rhs.getString()) == 0)
        return 0;

    if (strlen(m_pszData) != strlen(rhs.getString()))
        return 0;

    for (int i = 0; i < strlen(m_pszData); i++)
    {
        if (m_pszData[i] != rhs.getString()[i])
            return 0;
    }
    return 1;
}

int CMyString::operator!=(const CMyString& rhs)
{
    return !operator==(rhs);
}

char CMyString::operator[](int nIndex) const
{
    if (nIndex > m_nLength - 1)
        return m_pszData[0];
    return m_pszData[nIndex];
}

char& CMyString::operator[](int nIndex)
{
    if (nIndex > m_nLength - 1)
        return m_pszData[0];
    return m_pszData[nIndex];
}

const char* CMyString::operator+(const CMyString& rhs)
{
    CMyString c(getString());
    c.append(rhs.getString());
    return c;
}


CMyString& CMyString::operator+=(const CMyString& rhs)
{
    append(rhs.getString());
    return *this;
}

//�Ű������� ���� ���ڿ��� �ڿ� �߰��ϴ� �Լ�
int CMyString::append(const char* pszParam)
{
    
    //��ȿ�� �˻�
    if (pszParam == nullptr || strlen(pszParam) == 0)
        return 0;

    if (getLength() == 0)
        return 0;

    int tmpLength = strlen(pszParam);
    

    int newStringLength = getLength() + tmpLength - 1; //�� ���ڰ� �ߺ���
    //�Ҵ� ����������� �ϴ� �ӽú���
    char* tmp;

    tmp = new char[newStringLength];

    for (int i = 0; i < getLength() - 1; i++)
    {
        tmp[i] = getString()[i]; //���⿡���� �� ���ڸ� �����ϰ� �޾ƾߵ�
    }

    for (int i = 0; i < tmpLength; i++)
    {
        tmp[i + getLength() - 1] = pszParam[i];
    }

    Release();
    m_pszData = tmp;
    m_nLength = newStringLength;

    return 1;
}

int CMyString::getLength() const {
    return m_nLength;
}



int CMyString::setString(const char* pszParam) {
    //�̹� �Ҵ�� ���ڿ��� �ִٸ� ���� �� ���Ҵ�
    if (this->m_pszData != nullptr)
        Release();

    this->m_nLength = strlen(pszParam);

    //���ڿ��� ���̰� 0�̰ų� nullptr�� ��� Ż��
    if (pszParam == nullptr || this->m_nLength == 0)
        return 0;

    //���ڿ� �������(null����)
    m_pszData = new char[this->m_nLength];
    for (int i = 0; i < m_nLength; i++)
    {
        m_pszData[i] = pszParam[i];
    }

    onSetString(m_pszData);

    return 1;
}

const char* CMyString::getString() const {
    return m_pszData;
}

void CMyString::Release()
{
    delete this->m_pszData;
    this->m_nLength = 0;
}

//Null���ڸ� ������ ���ڿ��� ���� ��ȯ
int CMyString::strlen(const char* pszParam)
{
    int size = 0;

    while (pszParam[size] != 0) { size++; }
    //NULL���ڸ� ���ܽ�Ű���� size�� ��ȯ�ϸ� ��
    return size + 1;
}

void CMyString::onSetString(char* pszData)
{
    //������ ���� ����
}