#include "MyStringEx.h"
/*
int CMyStringEx::setString(const char* pszParam)
{   
    CMyStringEx tmp(pszParam);
    if (tmp.find("¸Û¸ÛÀÌ¾Æµé"))
        CMyString::setString("ÂøÇÑ »ç¶÷");
    else
        CMyString::setString(pszParam);

    return 1;
}
*/
int CMyStringEx::find(const char* pszParam)
{
    int check = 0, tmpLength = strlen(pszParam)-1;
    for (int i = 0; i < strlen(getString()); i++)
    {
        if (pszParam[check] == getString()[i])
            check++;
        else
            check = 0;
        cout << strlen(pszParam) <<" "<<strlen(getString()) << endl;
        if (check == tmpLength)
            return 1;
    }
    return 0;
}

void CMyStringEx::onSetString(char* pszData)
{
    CMyStringEx tmp(pszData);
    if(tmp.find("¸Û¸ÛÀÌ¾Æµé"))
        CMyString::setString("ÂøÇÑ »ç¶÷");

}