#include <iostream>
#include "List.h"

void TestPushBack(void)
{
    std::cout << "TestPushBack in process" << std::endl;

    int size = 10;
    Euneiz::List list;
    for(int i = 0; i < size; i++)
    {
        list.PushBack(i);
    }

    std::cout << "List: " << list;
    std::cout << "Items in the list: " << list.Size() << std::endl;
    std::cout << std::endl;
}

void TestPushFront(void)
{
    std::cout << "TestPushFront in process" << std::endl;

    int size = 10;
    Euneiz::List list;
    for(int i = 0; i < size; i++)
    {
        list.PushFront(i);
    }

    std::cout << "List: " << list;
    std::cout << "Items in the list: " << list.Size() << std::endl;
    std::cout << std::endl;
}

void TestPushBackFront(void)
{
    std::cout << "TestPushBackFront in process" << std::endl;

    int size = 10;
    Euneiz::List list;
    for(int i = 0; i < size; i++)
    {
        list.PushBack(i);
        list.PushFront(i * 10);
    }

    std::cout << "List: " << list;
    std::cout << "Items in the list: " << list.Size() << std::endl;
    std::cout << std::endl;
}

void TestPopFront(void)
{
    std::cout << "TestPopFront in process" << std::endl;

    int size = 10;
    Euneiz::List list;
    for(int i = 0; i < size; i++)
    {
        list.PushBack(i);
    }
    std::cout << "List: " << list;

    // Pop 5 items
    for(int i = 0; i < 5; i++)
    {
        list.PopFront();
    }

    std::cout << "List: " << list;
    std::cout << "Items in the list: " << list.Size() << std::endl;
    std::cout << std::endl;
}

void TestClear(void)
{
    std::cout << "TestClear in process" << std::endl;

    int size = 10;
    Euneiz::List list;
    for(int i = 0; i < size; i++)
    {
        list.PushBack(i);
    }
    std::cout << "List: " << list;

    list.Clear();
    std::cout << "List: " << list;
    std::cout << "Items in the list: " << list.Size() << std::endl;
    std::cout << std::endl;
}

void TestInsert(void)
{
    std::cout << "TestInsert1 in process" << std::endl;

    int size = 10;
    Euneiz::List list;
    for(int i = 0; i < size; i++)
    {
        list.Insert(i, i);
    }

    std::cout << "List: " << list;
    std::cout << "Items in the list: " << list.Size() << std::endl;
    std::cout << std::endl;

    std::cout << "TestInsert2 in process" << std::endl;
    list.Insert(42, 5);
    list.Insert(100, 10);
    list.Insert(14, 0);
    
    std::cout << "List: " << list;
    std::cout << "Items in the list: " << list.Size() << std::endl;
    std::cout << std::endl;
}

void TestErase(void)
{
    std::cout << "TestErase1 in process" << std::endl;

    int size = 10;
    Euneiz::List list;
    for(int i = 0; i < size; i++)
    {
        list.PushBack(i);
    }
    std::cout << "List: " << list;

    list.Erase(0);
    list.Erase(4);
    list.Erase(7);
    std::cout << "List: " << list;
    std::cout << "Items in the list: " << list.Size() << std::endl;
    std::cout << std::endl;

    std::cout << "TestErase2 in process" << std::endl;
    for(int i = list.Size() - 1; i >= 0; i--)
    {
        list.Erase(i);
    }
    
    std::cout << "List: " << list;
    std::cout << "Items in the list: " << list.Size() << std::endl;
    std::cout << std::endl;
}

int main(void)
{
    try
    {
        TestPushBack();		
    }
    catch(...)
    {
        std::cout << "TestPushBack ha fallado: error en las funciones implicadas" << std::endl;
    }
	
    try
    {
        TestPushFront();
    }
    catch(...)
    {
        std::cout << "TestPushFront ha fallado: error en las funciones implicadas" << std::endl;
    }

    try
    {
        TestPushBackFront();
    }
    catch(...)
    {
        std::cout << "TestPushBackFront ha fallado: error en las funciones implicadas" << std::endl;
    }

    try
    {
        TestPopFront();
    }
    catch(...)
    {
        std::cout << "TestPopFront ha fallado: error en las funciones implicadas" << std::endl;
    }
    
    try
    {
        TestClear();
    }
    catch(...)
    {
        std::cout << "TestClear ha fallado: error en las funciones implicadas" << std::endl;
    }
    
    try
    {
        TestInsert();
    }
    catch(...)
    {
        std::cout << "TestInsert ha fallado: error en las funciones implicadas" << std::endl;
    }
    
    try
    {
        TestErase();
    }
    catch(...)
    {
        std::cout << "TestErase ha fallado: error en las funciones implicadas" << std::endl;
    }

    std::cout << "Todos los test completados correctamente" << std::endl;
    
    return 0;
}