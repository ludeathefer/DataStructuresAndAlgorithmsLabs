#include <iostream>
using namespace std;

struct Node
{
    float data;
    Node *next;
} *start = nullptr;

void push()
{
    float n;
    cout << "Enter val: ";
    cin >> n;
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
void enqueue()
{
    float val;
    cout << "Enter val: ";
    cin >> val;
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
void displayMenu()
{
    cout << "1. Stack\t2. Queue\t3. Exit" << endl;
}
void displayStack()
{
    cout << "1. Push\t2. Pop\t3. Display\t4. Exit" << endl;
}

void displayQueue()
{
    cout << "1. Enqueue\t2. Dequeue\t3. Display\t4. Exit" << endl;
}

int main()
{
    int _choice;
    int choice;
    displayMenu();
    do
    {

        cout << "Choice: ";
        cin >> _choice;
        if (_choice == 1)
        {
            displayStack();
            do
            {
                choice = 0;
                cout << "choice: ";
                cin >> choice;
                if (choice == 1)
                {
                    push();
                }
                else if (choice == 2)
                {
                    pop();
                }
                else if (choice == 3)
                {
                    display();
                }
                else
                {
                    displayMenu();
                    break;
                }

            } while (choice != 4);
        }
        else if (_choice == 2)
        {
            displayQueue();
            do
            {
                choice = 0;
                cout << "choice: ";
                cin >> choice;
                if (choice == 1)
                {
                    enqueue();
                }
                else if (choice == 2)
                {
                    dequeue();
                }
                else if (choice == 3)
                {
                    display();
                }
                else
                {
                    displayMenu();
                    break;
                }

            } while (choice != 4);
        }

        else
        {

            break;
        }

    }

    while (_choice != 3);

    return 0;
}
