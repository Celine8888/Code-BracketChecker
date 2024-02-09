#include <iostream>
#include <algorithm>

#include "DSList.h"
#include "DSStack.h"

using namespace std;

int main()
{

    DSStack<int> list1;
    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(3);
    list1.push_back(4);

    list1.display();

    DSStack<int> list2;
    list2 = list1;

    list2.display();

    list1 = list1;
}