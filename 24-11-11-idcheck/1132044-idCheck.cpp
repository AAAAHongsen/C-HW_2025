#include <iostream>
#include <string>
using namespace std;

//檢查長度是否等於10
bool checklength(string L) //字串長度是否等於10
{
    if (L.length() == 10) return true;
    else return false;
}

//檢查英文大寫是否首碼
bool checkAlpha(char c) //檢查字元是否為大寫英文
{
    if (c >= 'A' && c <= 'Z') return true;
    else return false;
}
bool checkLocation(string L) //檢查字串第一個字元
{
    if (checkAlpha(L[0])) return true;
    else return false;
}

//檢查第三碼後是否都數字
bool checkDigit(char c) //檢查字元是否為數字
{
    if (c >= '0' and c <= '9') return true;
    else return false;
}
bool checkAllDigit(string L) //檢查字串第三個以後的字元
{
    for (int i = 2; i < 10; i++)
    {
        if (!checkDigit(L[i]))return false;        
    }
    return true;
}

//檢查性別
bool checkGender(string L) //檢查字串第二個字元是否為1或2
{
    if (!(L[1] == '1' or L[1] == '2')) return false;
    else return true;
}

//檢查檢查碼
int changeEn(string L)
{
    int En = 0;
    if (L[0] == 'A')En = 1;//10 => 1*1 + 0*9
    else if (L[0] == 'B')En = 10;
    else if (L[0] == 'C')En = 19;
    else if (L[0] == 'D')En = 28;
    else if (L[0] == 'E')En = 37;
    else if (L[0] == 'F')En = 46;
    else if (L[0] == 'G')En = 55;
    else if (L[0] == 'H')En = 64;
    else if (L[0] == 'I')En = 39;
    else if (L[0] == 'J')En = 73;
    else if (L[0] == 'K')En = 82;
    else if (L[0] == 'L')En = 2;
    else if (L[0] == 'M')En = 11;
    else if (L[0] == 'N')En = 20;
    else if (L[0] == 'O')En = 48;
    else if (L[0] == 'P')En = 29;
    else if (L[0] == 'Q')En = 38;
    else if (L[0] == 'R')En = 47;
    else if (L[0] == 'S')En = 56;
    else if (L[0] == 'T')En = 65;
    else if (L[0] == 'U')En = 74;
    else if (L[0] == 'V')En = 83;
    else if (L[0] == 'W')En = 21;
    else if (L[0] == 'X')En = 3;
    else if (L[0] == 'Y')En = 12;
    else if (L[0] == 'Z')En = 21;
    return En;
}
bool countID(string L)
{
    int n=0;
    for (int i = 1; i < 9; i++)
    {
        n += ((L[i] - '0') * (9 - i));
    }
    n += changeEn(L);
    n = (10 - (n % 10));
    if (L[9] == n + 48)return true;
    else return false;
}

//檢查全部
int checkID(string L)
{
    if (!checklength(L)) return 1; //長度錯誤
    else if (!checkLocation(L)) return 2; //首碼出生地英文錯誤
    else if (!checkGender(L)) return 3; //第二碼性別錯誤
    else if (!checkAllDigit(L)) return 4; //第三碼後非數字
    else if (!countID(L)) return 5; //檢查碼錯誤
    else return 0; //ID正確
}

//各式測資
void testlength()
{
    cout << "-------test length (字串長度是否為10)-----" << endl;
    string data[] = { "abc","a123456789","asdfghjklqwertyuiop" };
    for (int i = 0; i < 3; i++)
        cout << data[i] << ":" << (checklength(data[i]) ? "yes" : "no") << endl;
}
void testAlpha()
{
    cout << "-------test Alpha (是否為大寫英文)-----" << endl;
    char data[] = { 'a','B','1','@','~' };
    for (int i = 0; i < 5; i++)
        cout << data[i] << ":" << (checkAlpha(data[i]) ? "yes" : "no") << endl;
}
void testLocation()
{
    cout << "-------test Location (第一碼是否為大寫英文)-----" << endl;
    string data[] = { "a123456789","D123456789","%123456789","0123456789" };
    for (int i = 0; i < 4; i++)
        cout << data[i] << ":" << (checkLocation(data[i]) ? "yes" : "no") << endl;
}
void testDigit()
{
    cout << "-------test Digit (是否為數字)-----" << endl;
    char data[] = { 'a','B','1','@','~' };
    for (int i = 0; i < 5; i++)
        cout << data[i] << ":" << (checkDigit(data[i]) ? "yes" : "no") << endl;
}
void testAllDigit()
{
    cout << "-------test All Digit (第三碼後是否為數字)-----" << endl;
    string data[] = { "a123456789","a1#3456789","a1234d6789","a12345678A" };
    for (int i = 0; i < 4; i++)
        cout << data[i] << ":" << (checkAllDigit(data[i]) ? "yes" : "no") << endl;
}
void testGender()
{
    cout << "-------test Gender (第二碼是否為1或2)-----" << endl;
    string data[] = { "a123456789","a223456789","a323456789","ab23456789" };
    for (int i = 0; i < 4; i++)
        cout << data[i] << ":" << (checkGender(data[i]) ? "yes" : "no") << endl;
}
void testcountID()
{
    cout << "-------test count ID (檢查碼是否正確)-----" << endl;
    string data[] = { "A123456789","S154678925" };
    for (int i = 0; i < 2; i++)
    {
        cout << data[i] << ":" << (countID(data[i]) ? "yes" : "no") << endl;       
    }
}
void testAllID()
{
    cout << "-------test All ID -----" << endl;
    string data[] = { "ABC","1234567890","A123456789","asdfghjklqwertyuiopzxcvbnm","A323456789","A123456#$%","A123456780"};
    for (int i = 0; i < 7; i++)
    {
        if (checkID(data[i]) == 0)cout << data[i] << ":yes" << endl;
        else if (checkID(data[i]) == 1)cout << data[i] << ":長度錯誤" << endl;
        else if (checkID(data[i]) == 2)cout << data[i] << ":首碼非英文或非大寫英文" << endl;
        else if (checkID(data[i]) == 3)cout << data[i] << ":第二碼性別錯誤" << endl;
        else if (checkID(data[i]) == 4)cout << data[i] << ":第三碼後非數字" << endl;
        else if (checkID(data[i]) == 5)cout << data[i] << ":檢查碼錯誤" << endl;
    }
}
//全部測資
void testCase()
{
    testlength();
    testAlpha();
    testLocation();
    testDigit();
    testAllDigit();
    testGender();
    testcountID();
    testAllID();
}

void IDcard()
{
    string L;
    cin >> L;
    if (checkID(L) == 0)cout << L << ":yes" << endl;
    else if (checkID(L) == 1)cout << L << ":長度錯誤" << endl;
    else if (checkID(L) == 2)cout << L << ":首碼非英文或非大寫英文" << endl;
    else if (checkID(L) == 3)cout << L << ":第二碼性別錯誤" << endl;
    else if (checkID(L) == 4)cout << L << ":第三碼後非數字" << endl;
    else if (checkID(L) == 5)cout << L << ":檢查碼錯誤" << endl;
}
#define __TEST__
int main()
{
#ifdef __TEST__
    testCase();
#else
    IDcard();
#endif
}