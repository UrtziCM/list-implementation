#ifndef List_e
#define List_e

#include <ostream>

namespace Euneiz
{
    struct Node
    {
        // Constructor and destructor
        Node(int data);
        ~Node();

        // Struct data
        Node* next;
        int data;
    };

    struct List
    {
    public:
        // Constructor and destructor
        List();
        ~List();

        // List methods
        void PushBack(int data);
        void PushFront(int data);
        void PopFront();
        bool Empty();
        int Size();
        void Clear();
        void Insert(int data, int index);
        void Erase(int index);

        // To print the list using the << operator and std::cout
        friend std::ostream & operator<<(std::ostream & os, const List &list);

    private:
        // Helper internal methods
        Node* CreateNode(int data);

        // List internal data
        Node* head;
        Node* tail;
        int size;
    };
}

#endif