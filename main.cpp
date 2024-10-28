#include <iostream>
#include <Windows.h>
#include "MyString.h"
using namespace std;

int MyString::objectCount = 0;

int main()
{
    MyString obj1("Hello");
    obj1.Print();
    MyString obj2(obj1);
    obj2.Print();

    MyString::ShowObjectCount();

}