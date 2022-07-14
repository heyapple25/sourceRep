#include "MyStringEx.h"

int CMyStringEx::find(const char* pszParam)
{
    int check=0;
    for(int i=0;i<strlen(getString());i++)
    {
        if(pszParam[i]==getString()[i])
            check++;
        else
            check=0;
        
        if(check==strlen(pszParam)-1)
            return (i+1)-check;
    }
    return 0;
}