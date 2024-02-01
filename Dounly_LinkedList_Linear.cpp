#include <iostream>
using namespace std;

struct Node
{
    float data;
    Node *next, *previous;
} *start = nullptr;

void InsertStart()
{
    float val;
    cout << "Enter value";
    cin >> val;
    Node *ptr = new Node;
    ptr->data = val;
    if (start == nullptr)
    {
        ptr->next = nullptr;
    }
    else
    {
        start->previous = ptr;
        ptr->next = start;
    }
    ptr->previous = nullptr;
    start = ptr;
}
void InsertEnd()
{
    float val;
    cout << "Enter value: ";
    cin >> val;
    Node *ptr = new Node;
    ptr->data = val;
    if (start == nullptr)
    {
        ptr->next = nullptr;
        ptr->previous = nullptr;
        start = ptr;
    }
    else
    {
        ptr = start;
        Node *temp = new Node;
        temp->data = val;
        while (ptr->next != nullptr)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
        temp->previous = ptr;
        temp->next = nullptr;
    }
}
void InsertAfter(float chk)
{
    float val;
    cout << "Enter value: ";
    cin >> val;
    // float chk
    // cout<<"Enter value to insert after: ";
    // cin>>chk
    Node *ptr = new Node;
    Node *temp = new Node;
    temp->data = val;
    if (start == nullptr)
    {
        cerr << "Empty list" << endl;
    }
    else
    {
        ptr = start;
        while (ptr->data != chk && ptr->next != nullptr)
        {
            ptr = ptr->next;
        }
        if (ptr->data != chk)
        {
            cerr << "Value to insert after not found." << endl;
        }
        else
        {
            temp->previous = ptr;
            cout << "JOJO";
            temp->next = ptr->next;
            cout << "JOJO";
            if (ptr->next != nullptr)
            {
                ptr->next->previous = temp;
                cout << "JOJO";
            }

            ptr->next = temp;
            cout << "JOJO";
        }
    }
}
void InsertBefore(float chk)
{
    float val;
    cout << "Enter value: ";
    cin >> val;
    // float chk
    // cout<<"Enter value to insert after: ";
    // cin>>chk
    Node *ptr = new Node;
    Node *temp = new Node;
    temp->data = val;
    if (start == nullptr)
    {
        cerr << "Empty list" << endl;
    }
    else
    {
        ptr = start;
        while (ptr->data != chk && ptr->next != nullptr)
        {
            ptr = ptr->next;
        }
        if (ptr->data != chk)
        {
            cerr << "Value to insert after not found" << endl;
        }
        else
        {
            temp->next = ptr;
            if (ptr == start)
            {
                start = temp;
                temp->previous = nullptr;
            }
            if (ptr->previous != nullptr)
            {
                ptr->previous->next = temp;
            }
            ptr->previous = temp;
            temp->previous = ptr->previous;
        }
    }
}
void DeleteStart()
{
    Node *temp = new Node;
    if (start == nullptr)
    {
        cerr << "Empty list." << endl;
    }
    else
    {
        temp = start;
        start = start->next;
        if (start != nullptr)
        {
            start->previous = nullptr;
        }
        delete temp;
        cout << "Deleted sucessfully" << endl;
    }
}
void DeleteEnd()
{
    Node *temp = new Node;
    if (start == nullptr)
    {
        cerr << "Empty list" << endl;
    }
    else
    {
        temp = start;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        if (temp->previous != nullptr)
        {
            temp->previous->next = nullptr;
        }
        else
        {
            start = nullptr;
        }
        delete temp;
    }
}
void DeleteBefore(float chk)
{
    Node *temp = new Node;
    if (start == nullptr)
    {
        cerr << "Empty List" << endl;
    }
    else
    {
        temp = start;
        while (temp->data != chk && temp->next != nullptr)
        {
            temp = temp->next;
        }
        if (temp->data != chk)
        {
            cerr << "Data to delete before not found";
        }
        else
        {
            if (temp->previous == nullptr)
            {
                cerr << "No available data" << endl;
            }
            else
            {
                temp = temp->previous;
                if (temp->previous == nullptr)
                {
                    start = temp->next;
                    temp->next->previous = nullptr;
                }
                else
                {
                    temp->previous->next = temp->next;
                    temp->next->previous = temp->previous;
                }
                delete temp;
            }
        }
    }
}
void DeleteAfter(float chk)
{
    Node *temp = new Node;
    if (start == nullptr)
    {
        cerr << "Empty List" << endl;
    }
    else
    {
        temp = start;
        while (temp->data != chk && temp->next != nullptr)
        {
            temp = temp->next;
        }
        if (temp->data != chk)
        {
            cerr << "Value to delete after not found" << endl;
        }
        else
        {
            if (temp->next == nullptr)
            {
                cerr << "No data found" << endl;
            }
            else
            {
                temp = temp->next;
                if (temp->next == nullptr)
                {
                    temp->previous->next = nullptr;
                }
                else
                {
                    temp->previous->next = temp->next;
                    temp->next->previous = temp->previous;
                }
                delete temp;
            }
        }
    }
}
void display()
{
    Node *ptr = new Node;
    ptr = start;
    cout << "List is:" << endl;
    while (ptr != nullptr)
    {
        cout << ptr->data << "\t";
        ptr = ptr->next;
    }
}
int main()
{
    InsertStart();
    // InsertStart();
    InsertEnd();
    // InsertEnd();
    // InsertEnd();
    InsertEnd();

    // InsertAfter(22);
    // InsertBefore(22);
    // DeleteStart();
    // DeleteEnd();
    // DeleteBefore(22);
    DeleteAfter(22);

    display();
}