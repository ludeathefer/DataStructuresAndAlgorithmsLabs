#include <iostream>
using namespace std;

struct list
{
    float data;
    list *next;
} *start = nullptr;
// start = nullptr;
list *create(float n)
{
    list *ptr;
    ptr = new list;
    if (ptr == nullptr)
    {
        cout << "Overflow" << endl;
        exit(1);
    }
    else
    {
        ptr->data = n;
        ptr->next = nullptr;
    }
    return ptr;
}
list *addFront(float n)
{
    list *ptr;
    ptr = new list;
    ptr->data = n;
    if (start == nullptr)
    {
        ptr->next = nullptr;
        start = ptr;
    }
    else
    {

        ptr->next = start;
        start = ptr;
    }
    return ptr;
}
list *addBack(float n)
{
    list *ptr;
    list *newNode = new list;
    newNode->data = n;
    newNode->next = nullptr;
    if (start == nullptr)
    {
        start = newNode;
    }
    else
    {
        ptr = start;
        while (ptr->next != nullptr)
        {
            ptr = ptr->next;
        }
        ptr->next = newNode;
    }
    return newNode;
}
list *addAfter(int n, int check)
{
    bool notfound = true;
    list *newNode = new list;
    list *ptr = new list;
    if (start == nullptr)
    {
        cerr << "EmptyList" << endl;
        exit(1);
    }
    else
    {
        ptr = start;
        while (ptr->data != check && ptr->next != nullptr)
        {

            ptr = ptr->next;
            cout << "jojo" << endl;
        }
        if (ptr->data == check)
        {
            newNode->data = n;
            newNode->next = ptr->next;
            ptr->next = newNode;
        }
        else
        {
            cerr << "Value to insert after not found" << endl;
        }
    }
    return newNode;
}
list *addBefore(float n, float check)
{
    bool onlyOneNode = false;
    bool notFound = true;
    list *ptr = new list;
    list *newNode = new list;

    if (start == nullptr)
    {
        cerr << "Empty list" << endl;
        exit(1);
    }
    else
    {

        ptr = start;
        if (ptr->next == nullptr)
        {
            onlyOneNode = true;
        }
        if (ptr->data == check)
        {
            newNode->data = n;
            newNode->next = ptr;
            start = newNode;
            notFound = false;
            // ptr = ptr->next;
        }
        else
        {

            while (!onlyOneNode && ptr->next->data != check && ptr->next != nullptr)
            {
                ptr = ptr->next;
            }

            if (!onlyOneNode && (ptr->next->data == check || ptr->data == check))
            {
                newNode->data = n;
                newNode->next = ptr->next;
                ptr->next = newNode;
                notFound = false;
            }
        }
    }
    if (notFound)
    {
        cout << "InsertBefore value not found" << endl;
    }
    return newNode;
}
void display()
{
    list *current = start;
    cout << "List is:" << endl;
    while (current != nullptr)
    {
        cout << current->data << "\t";
        current = current->next;
    }
}

int main()
{
    // addFront(20);
    // addBack(5);
    // addBack(4);
    // addFront(2);
    // addFront(3);
    // addFront(5);
    // addBack(6);
    // addAfter(10, 5);
    // addFront(2);
    addFront(3);
    addFront(7);
    addBack(5);
    addBefore(10, 5);
    display();
    return 0;
}