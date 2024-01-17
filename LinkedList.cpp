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
list *addFront()
{
    float n;
    cout << "Enter to add Front" << endl;
    cin >> n;
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
list *addBack()
{
    float n;
    cout << "Enter to add Back" << endl;
    cin >> n;
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
list *addAfter()
{
    float n;
    cout << "Enter to add" << endl;
    cin >> n;
    float check;
    cout << "Enter to add After" << endl;
    cin >> check;

    list *newNode = new list;
    list *ptr = new list;
    if (start == nullptr)
    {
        cerr << "EmptyList" << endl;
        // exit(1);
        return start;
    }
    else
    {
        ptr = start;
        while (ptr->data != check && ptr->next != nullptr)
        {

            ptr = ptr->next;
            // cout << "jojo" << endl;
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
list *addBefore()
{
    float n;
    cout << "Enter to add" << endl;
    cin >> n;
    float check;
    cout << "Enter to add Before" << endl;
    cin >> check;
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
void deleteStart()
{
    list *ptr = new list;
    // newNode = new list;
    if (start == nullptr)
    {
        cerr << "Empty List" << endl;
    }
    else
    {
        ptr = start;
        start = ptr->next;
        delete ptr;
    }
    // return ;
}
void deleteEnd()
{
    list *ptr = new list;
    bool onlyOneNode = false;

    if (start == nullptr)
    {
        cerr << "Empty List" << endl;
    }
    else
    {
        ptr = start;
        if (ptr->next == nullptr)
        {
            onlyOneNode = true;
            delete ptr;
            start = nullptr;
        }
        if (!onlyOneNode)
        {
            while (ptr->next->next != nullptr)
            {
                ptr = ptr->next;
            }
            list *temp = ptr->next;

            ptr->next = nullptr;
            delete temp;
        }
    }
    // return ;
}
void deleteAfter()
{
    float check;
    cout << "Enter to delete after" << endl;
    cin >> check;
    list *ptr = new list;
    bool onlyOneNode = false;
    bool notFound = false;
    // float check;
    if (start == nullptr)
    {
        cerr << "Empty list" << endl;
    }
    else
    {
        ptr = start;
        if (ptr->next == nullptr)
        {
            onlyOneNode = true;
            cout << "Only one node" << endl;
        }
        if (!onlyOneNode)
        {
            while (ptr->data != check)
            {
                ptr = ptr->next;
                if (ptr->next == nullptr)
                    break;
            }
            notFound = !(ptr->data == check);
            if (notFound)
            {
                cout << "Value to delete after not found" << endl;
            }
            else
            {
                list *temp = new list;
                temp = ptr->next;
                ptr->next = temp->next;
                delete temp;
            }
        }
    }
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
    cout << "Sucessful Display" << endl;
}
void displayMenu()
{
    cout << "1. Add Front\t2. Add Back\t3. Add Before\t4. Add After\n5. Delete Start\t6. Delete End\t7. Delete After\t8. Display List\n9. Exit" << endl;
}

int main()
{
    int choice;
    displayMenu();
    do
    {
        cout << "Your response: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            addFront();
            break;

        case 2:
            addBack();
            break;

        case 3:
            addBefore();
            break;

        case 4:
            addAfter();
            break;

        case 5:
            deleteStart();
            break;

        case 6:
            deleteEnd();
            break;

        case 7:
            deleteAfter();
            break;

        case 8:
            display();
            break;

        case 9:
            // exit(0);
            break;

        default:
            break;
        }
    } while (choice != 9);
    return 0;
}
