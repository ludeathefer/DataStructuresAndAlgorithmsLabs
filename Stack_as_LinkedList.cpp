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
        cerr << "Empty stack" << endl;
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
    }
    cout << val << " is popped" << endl;
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
    push(2);
    push(3);
    push(4);

    // display();
    // pop();
    pop();
    // Note- my pop is working like dequeue operation. Make new pop and rename current pop as dequeue.
    display();
}