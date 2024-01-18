#include <iostream>
using namespace std;

class LinkedList
{
private:
    struct Node
    {
        float coeff;
        int power;
        Node *next;
    } *start = nullptr;
    Node *array;
    int num;

public:
    LinkedList()
    {
        cout << "Enter the highest Power: ";
        cin >> num;
        array = new Node[num + 1];
    }
    LinkedList(int i)
    {
        start = nullptr;
        cout << "JOJO1" << endl;
    }
    void addValues()
    {
        // For entering values
        for (int i = 0; i < (num + 1); i++)
        {
            cout << "Enter Power: ";
            cin >> array[i].power;
            cout << "Enter Coefficient: ";
            cin >> array[i].coeff;
        }
    }
    void arrangePower()
    {
        // Sorts on the basis of Power
        for (int i = 0; i < (num + 1); i++)
        {
            for (int j = i + 1; j < (num + 1); j++)
            {
                if (array[i].power > array[j].power)
                {
                    Node temp;
                    temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
                }
            }
        }
        // Creates linked list
        for (int i = 0; i < (num + 1); i++)
        {
            Node *newNode = new Node;
            newNode->coeff = array[i].coeff;
            newNode->power = array[i].power;

            newNode->next = start;
            start = newNode;
        }
    }
    void display()
    {
        Node *ptr = start;
        cout << "Equation is: " << endl;
        while (ptr != nullptr)
        {
            cout << " " << ptr->coeff << " x" << ptr->power << " + ";
            ptr = ptr->next;
        }
    }

    LinkedList addition(LinkedList L1, LinkedList L2)
    {
        cout << "JOJO_Addition" << endl;
        LinkedList result(1);
        Node *list_L1 = new Node;
        Node *list_L2 = new Node;
        Node *temp = new Node;
        list_L1 = L1.start;
        list_L2 = L2.start;
        int maxPow = (list_L1->power > list_L2->power) ? list_L1->power : list_L2->power;
        while (list_L1 != nullptr || list_L2 != nullptr)
        {
            Node *Sum = new Node;

            cout << "JOJO_loop" << endl;
            if ((list_L1->power == maxPow) && (list_L2->power == maxPow))
            {
                Sum->coeff = list_L1->coeff + list_L2->coeff;
                Sum->power = maxPow;
                list_L1 = list_L1->next;
                list_L2 = list_L2->next;
            }
            else if ((list_L1->power == maxPow) && (list_L2->power < maxPow))
            {
                Sum->coeff = list_L1->coeff;
                Sum->power = maxPow;
                list_L1 = list_L1->next;
            }
            else if ((list_L1->power < maxPow) && (list_L2->power == maxPow))
            {
                Sum->coeff = list_L2->coeff;
                Sum->power = maxPow;
                list_L2 = list_L2->next;
            }
            else
            {
                cerr << "Both Powers are less. Error in sorting." << endl;
                exit(1);
            }
            if (list_L1 != nullptr || list_L2 != nullptr)
            {
                if (temp == nullptr)
                {
                    temp = Sum; // Assign the first node to temp
                }
                else
                {
                    Sum->next = temp;
                    temp = Sum; // Move temp to the new node
                }

                // Sum = Sum->next;
            }
            else
            {
                temp->next = nullptr;
            }
            maxPow--;
            cout << "JOJO_reached_Loop_end" << endl;
        }
        result.start = temp;
        return result;
    }
};
int main()
{
    cout << "For polynomial 1: " << endl;
    LinkedList L1;
    L1.addValues();
    L1.arrangePower();
    L1.display();
    cout << "For polynomial 2: " << endl;
    LinkedList L2;
    L2.addValues();
    L2.arrangePower();
    L2.display();

    LinkedList L3(1);
    L3 = L3.addition(L1, L2);
    L3.display();
    L3.arrangePower();
    L3.display();
    return 0;
}
