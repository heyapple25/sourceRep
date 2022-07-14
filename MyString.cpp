#include "MyString.h"


CMyString::CMyString(CMyString&&rhs):m_pszData(nullptr),m_nLength(0)
{
    cout<<"CMyString 이동생성자 호출"<<endl;
}

void TestFunc(const CMyString &strParam)
{
    cout<<strParam[0]<<endl;
    cout<<strParam[strParam.getLength()-2]<<endl;
}


int CMyString::operator==(const CMyString& rhs)
{
    if(strlen(m_pszData)==0 || strlen(rhs.getString())==0)
        return 0;
    
    if(strlen(m_pszData)!=strlen(rhs.getString()))
        return 0;

    for(int i=0;i<strlen(m_pszData);i++)
    {
        if(m_pszData[i]!=rhs.getString()[i])
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
    if(nIndex>m_nLength-1)
        return m_pszData[0];
    return m_pszData[nIndex];
}

char& CMyString::operator[](int nIndex)
{
    if(nIndex>m_nLength-1)
        return m_pszData[0];
    return m_pszData[nIndex];
}

CMyString CMyString::operator+(const CMyString& rhs)
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

//매개변수로 들어온 문자열을 뒤에 추가하는 함수
int CMyString::append(const char*pszParam)
{   
    int tmpLength=strlen(pszParam);
    //유효성 검사
    if(tmpLength==0 || pszParam==nullptr)
        return 0;
    
    if(getLength()==0)
        return 0;

    int newStringLength=getLength()+tmpLength-1; //널 문자가 중복됨
    //할당 해제시켜줘야 하는 임시변수
    char *tmp;

    tmp=new char[newStringLength];

    for(int i=0;i<getLength()-1;i++)
    {
        tmp[i]=getString()[i]; //여기에서는 널 문자를 제거하고 받아야됨
    }
    
    for(int i=0;i<tmpLength;i++)
    {
        tmp[i+getLength()-1]=pszParam[i];
    }

    Release();
    m_pszData=tmp;
    m_nLength=newStringLength;

    return 1;
}

int CMyString::getLength() const {
    return m_nLength;
}

int CMyString::setString(const char*pszParam){
    //이미 할당된 문자열이 있다면 해제 후 재할당
    if(this->m_pszData!=nullptr)
        Release();
    
    this->m_nLength=strlen(pszParam);

    //문자열의 길이가 0이거나 nullptr인 경우 탈출
    if(pszParam==nullptr || this->m_nLength==0)
        return 0;
    
    //문자열 복사수행(null포함)
    m_pszData=new char[this->m_nLength];
    for(int i=0;i<=m_nLength;i++)
    {
        m_pszData[i]=pszParam[i];
    }

    return 1;
}

const char* CMyString::getString() const {
    return m_pszData;
}

void CMyString::Release()
{
    delete this->m_pszData;
    this->m_nLength=0;
}

//Null문자를 포함한 문자열의 길이 반환
int CMyString::strlen(const char*pszParam)
{
    int size=0;

    while(pszParam[size]!=0){ size++; }
    //NULL문자를 제외시키려면 size를 반환하면 됨
    return size+1;
}