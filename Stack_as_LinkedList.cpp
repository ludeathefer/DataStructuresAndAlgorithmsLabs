#include <iostream>
using namespace std;

struct Node
{
    float data;
    Node *next;
} *start = nullptr;

void push(float n)
{
    Node *ptr = new Node;
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
}
void pop()
{
    Node *ptr = new Node;
    float val;
    if (start == nullptr)
    {
        cerr << "Empty stack." << endl;
    }
    else
    {
        ptr = start;
        val = ptr->data;
        if (ptr->next == nullptr)
        {
            start = nullptr;
        }
        else
        {
            start = ptr->next;
        }
        // cout << "jojo" << endl;
        delete ptr;
        cout << "\n"
             << val << " is popped." << endl;
    }
}
void enqueue(float val)
{
    Node *ptr = new Node;
    ptr->data = val;
    if (start == nullptr)
    {
        start = ptr;
        ptr->next = nullptr;
    }
    else
    {
        ptr->next = start;
        start = ptr;
    }
}

void dequeue()
{
    Node *ptr = new Node;
    float val;
    if (start == nullptr)
    {
        cerr << "Empty queue" << endl;
    }
    else
    {
        ptr = start;
        if (ptr->next == nullptr)
        {
            // for only one node check
            val = ptr->data;
            delete ptr;
            start = nullptr;
        }
        else
        { // for more than one node
            while (ptr->next->next != nullptr)
            {
                ptr = ptr->next;
            }
            val = ptr->next->data;
            Node *temp = new Node;
            temp = ptr->next;
            ptr->next = nullptr;
            delete temp;
        }
        cout << "\n"
             << val << " is dequeued." << endl;
    }
}
void display()
{
    Node *ptr = new Node;
    cout << "stack is:" << endl;
    ptr = start;
    while (ptr != nullptr)
    {
        cout << ptr->data << "\t";
        ptr = ptr->next;
    }
}

int main()
{
    // push(2);
    // push(3);
    // push(4);
    // push(5);

    // display();
    // pop();
    // pop();
    // pop();
    // pop();
    // pop();

    // pop();
    enqueue(3);
    enqueue(4);
    enqueue(5);
    display();
    // dequeue();
    // dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();

    display();
    return 0;
}