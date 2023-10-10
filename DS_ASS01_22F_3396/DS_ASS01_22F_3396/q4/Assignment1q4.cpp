#include <iostream>
using namespace std;

struct Node 
{
    int data;
    Node* next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};
class CircularLL
{
private:
    int N;
    int M;
public:
    Node* circularlist(int N)
    {
        this->N = N;
        int j = 1;
        Node* head = new Node(j);
        Node* current = head;

        for (int i = j + 1; i <= N; ++i)
        {
            current->next = new Node(i);
            current = current->next;
        }
        current->next = head;

        return head;
    }

    int Last(int N, int M)
    {
        this->N = N;
        this->M = M;
        Node* head = circularlist(N);
        Node* current = head;
        Node* prev = current;

        while (current->next != current)
        {
            int count = 1;
            while (count < M)
            {
                prev = current;
                current = current->next;
                count++;
            }

            prev->next = current->next;
            Node* temp = current;
            current = current->next;
            delete temp;
        }

        return current->data;
    }
};
int main() 
{
    int N, M; 
    CircularLL Object;
    cout << "Enter the value ot N: ";
    cin >> N;
    cout << "Enter the value of M: ";
    cin >> M;
    int last = Object.Last(N, M);

    cout << "The last remaining person is: " << last << endl;

    return 0;
}
