#include <iostream>
using namespace std;


struct Node 
{
    int coefficient;
    int exponent;
    Node* next;
};
class List {

public:
    List()
    {

    }
    ~List()
    {

    }
    void insert(Node*& head, int c, int e)
    {
        Node* newNode = new Node;
        newNode->coefficient = c;
        newNode->exponent = e;
        newNode->next = nullptr;
        if (!head)
        {
            head = newNode;
        }
        else
        {
            Node* current = head;
            Node* prev = nullptr;
            while (current && current->exponent > e)
            {
                prev = current;
                current = current->next;
            }
            if (current && current->exponent == e)
            {
                current->coefficient += c;
                delete newNode;
            }
            else
            {
                if (prev)
                {
                    prev->next = newNode;
                }
                else
                {
                    head = newNode;
                }
                newNode->next = current;
            }
        }
    }

    Node* addNumbers(Node* num1, Node* num2) 
    {
        Node* result = nullptr;
        while (num1 || num2) 
        {
            int c1 = num1->coefficient;
            int e1 = num1->exponent;
            int c2 = num2->coefficient;
            int e2 = num2->exponent;
        if (e1 > e2) 
            {
                insert(result, c1, e1);
                num1 = num1->next;
            }
            else if (e2 > e1) 
            {
                insert(result, c2, e2);
                num2 = num2->next;
            }
            else 
            {
                insert(result, c1 + c2, e1);
                num1 = num1->next;
                num2 = num2->next;
            }
        }
        return result;
    }

    void display(Node* head)
    {
        while (head)
        {
            cout << head->coefficient;
            if (head->exponent >= 0)
            {
                cout << "x^" << head->exponent;
            }
            if (head->next)
            {
                cout << " + ";
            }
            head = head->next;
        }
        cout << endl;
    }
};
int main()
{
    List list;
    Node* num1 = nullptr;
    Node* num2 = nullptr;
    //5x^3 + 4x^2 + 2x^0
    list.insert(num1, 5, 3);
    list.insert(num1, 4, 2);
    list.insert(num1, 2, 0);
     //5x^1 + 5x^0
    list.insert(num2, 5, 1);
    list.insert(num2, 5, 0);
     cout << "Number 1: ";
    list.display(num1);
    cout << "Number 2: ";
    list.display(num2);
    Node* result = list.addNumbers(num1, num2);
    cout << "Result: ";
    list.display(result);

    return 0;
}
