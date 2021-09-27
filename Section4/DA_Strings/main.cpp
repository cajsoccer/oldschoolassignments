#include <iostream>

int findLen(char* A, int size)
{
    int length = 0;
    for (int i = 0; i < size; i++)
    {
        if (A[i] == '\0')
            break;
        else
            length++;
    }
    return length;
}

void changeCase(char *A, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (A[i] <= 90 && A[i] >= 65)
            A[i] += 32;
        else if (A[i] <= 122 && A[i] >= 97)
            A[i] -= 32;
    }
}

void countVCW(char *A, int size, int &v, int &c, int &w)
{
    for (int i = 0; i < size; i++)
    {
        if (A[i] == 'a' || A[i] == 'e' || A[i] == 'i' || A[i] == 'o' || A[i] == 'u' || A[i] == 'A' || A[i] == 'E' || A[i] == 'I' || A[i] == 'O' || A[i] == 'U')
            v++;
        else if ((A[i] <= 90 && A[i] >=65) || (A[i] <= 122 && A[i] >= 97))
            c++;
        else if (A[i] == ' ' && A[i-1] != ' ')
            w++;
    }
}

void revStr(char *A)
{
    int length = 0;
    for (int i = 0; A[i] != '\0'; i++)
        length++;
    char temp;
    for (int i = 0; i < length/2; i++)
    {
        temp = A[i];
        A[i] = A[length - i - 1];
        A[length - i - 1] = temp;
    }
}

bool stringCmpr(const char* A, const char* B)
{
    bool same = true;
    int alen = 0;
    int blen = 0;
    for (int i = 0; A[i] != '\0'; i++)
        alen++;
    for (int i = 0; B[i] != '\0'; i++)
        blen++;
    if (alen != blen)
        same = false;
    else
    {
        for (int i = 0; i < alen; i++)
            if (A[i] != B[i])
            {
                same = false;
                break;
            }
    }
    return same;
}

bool isPal(const char* A)
{
    bool isPal = true;
    int length = 0;
    for (int i = 0; A[i] != '\0'; i++)
        length++;
    char B[length];
    for (int i = 0; i < length; i++)
        B[length - 1 - i] = A[i];
    for (int i = 0; i < length; i++)
        if (A[i] != B[i])
            isPal = false;
    return isPal;
}

void findDup(const char* A, char* dupList)
{
    int len = 0;
    for (int i = 0; A[i] != '\0'; i++)
        len++;
    for (int i = 0; i < len; i++)
        dupList[A[i]]++;
}

bool isAnagram(const char* A, const char* B)
{
    bool isAn = true;
    int alen = 0;
    int blen = 0;
    for (int i = 0; A[i] != '\0'; i++)
        alen++;
    for (int i = 0; B[i] != '\0'; i++)
        blen++;
    if (alen != blen)
        isAn = false;
    int hashListA[256];
    int hashListB[256];
    for (int i = 0; i < 256; i++)
    {
        hashListA[i] = 0;
        hashListB[i] = 0;
    }
    for (int i = 0; i < alen; i++)
    {
        hashListA[(int)A[i]]++;
        hashListB[(int)B[i]]++;
    }
    for (int i = 0; i < 256; i++)
        if (hashListA[i] != hashListB[i])
            isAn = false;
    return isAn;
}

int main()
{
    /*char s1[20] = "painting";
    char s2[10] = "painter";
    char s3[10] = "dovod";
    std::cout << stringCmpr(s1,s2) << std::endl;
    std::cout << isPal(s3) << std::endl;
    char s4[20] = "finding";
    char dupList[256];
    for (int i = 0; i < 256; i++)
        dupList[i] = 0;
    findDup(s4,dupList);
    for (int i = 0; i < 256; i++)
        if (dupList[i] > 1)
            std::cout << (char)i << ": apppears " << (int)dupList[i] << " number of times." << std::endl;*/
    char str1[20] = "verbose";
    char str2[20] = "observe";
    bool r = true;
    std::cout << isAnagram(str1, str2) << std::endl;
    return 0;
}