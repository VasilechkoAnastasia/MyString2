#pragma once

class MyString
{
    char* str;
    int length;

    static int objectCount;

public:
    MyString();
    MyString(int size);
    MyString(const char* obj);
    MyString(const MyString& obj);
    ~MyString();
    void Input();
    void Print() const;
    void MyStrcpy(MyString& obj);
    bool MyStrStr(const char* substr);
    int MyChr(char c);
    int MyStrLen();
    void MyStrCat(MyString& b);
    void MyDelChr(char c);
    int MyStrCmp(MyString& b);
    static void ShowObjectCount();
};

