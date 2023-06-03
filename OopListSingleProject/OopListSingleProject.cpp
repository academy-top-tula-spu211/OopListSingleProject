#include <iostream>
#include "ListSimple.h"

int main()
{
    ListSimple<int> list;

    list.PushBack(100);
    list.PushBack(200);
    list.PushBack(300);

    list.PushFront(400);
    list.PushFront(500);

    list.Insert(600, 3);

    list.Print();

    std::cout << "pop back " << list.PopBack() << "\n";

    list.Print();

    std::cout << "pop front " << list.PopFront() << "\n";

    list.Print();

    list[1] = 700;

    list.Print();

    ListSimple<int> list2;
    list2.PushBack(1);
    list2.PushBack(2);
    list2.Print();

    

    try
    {
        std::cout << "pop: " << list2.PopFront() << "\n";
        std::cout << "pop: " << list2.PopFront() << "\n";
        //std::cout << "pop: " << list2.PopFront() << "\n";

        list2.Print();
    }
    catch (ListException* e)
    {
        std::cout << e->Message() << "\n";
    }
}
