#include<iostream>
#include <cstring>
#include "MyString.h"
using namespace std;

MyString::MyString(int size) : length(size) 
{
    str = new char[length + 1];
    strcpy_s(str, length + 1, "");
    objectCount++;
}

MyString::MyString()
{
    length = 80;
    str = new char[length];
    objectCount++;
}

MyString::MyString(const char* obj) 
{
    length = strlen(obj);
    str = new char[length + 1];
    strcpy_s(str, length + 1, obj);
    objectCount++;
}

MyString::MyString(const MyString& obj)
{
    length = obj.length;
    str = new char[length + 1];
    strcpy_s(str, length + 1, obj.str);
    objectCount++;
}

MyString::~MyString()
{
    delete[] str;
    objectCount--;
}

void MyString::Input() 
{
    cout << "Input string: ";
    cin.getline(str, length);
}

void MyString::Print() const
{
    cout << str << endl;
}

void MyString::MyStrcpy(MyString& obj) 
{
    delete[] str;
    length = obj.length;
    str = new char[length + 1];
    strcpy_s(str, length + 1, obj.str);
}

bool MyString::MyStrStr(const char* substr) 
{
    return strstr(str, substr) != nullptr;
}

int MyString::MyChr(char c) 
{
    for (int i = 0; i < length; ++i) 
    {
        if (str[i] == c) 
        {
            return i;
        }
    }
    return -1;
}

int MyString::MyStrLen() 
{
    return length;
}

void MyString::MyStrCat(MyString& b) 
{
    char* newStr = new char[length + b.length + 1];
    strcpy_s(newStr, length + 1, str);
    strcat_s(newStr, length + b.length + 1, b.str);
    delete[] str;
    str = newStr;
    length += b.length;
}

void MyString::MyDelChr(char c) 
{
    int newLength = 0;
    for (int i = 0; i < length; ++i)
    {
        if (str[i] != c) 
        {
            str[newLength++] = str[i];
        }
    }
    str[newLength] = '\0';
    length = newLength;
}

int MyString::MyStrCmp(MyString& b) 
{
    int comparison = strcmp(str, b.str);
    if (comparison < 0)
    {
        return -1;
    }
    else if (comparison > 0) 
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void MyString::ShowObjectCount()
{
    cout << "Number: " << objectCount << endl;
}