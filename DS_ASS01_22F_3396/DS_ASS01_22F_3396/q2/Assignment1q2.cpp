#include <iostream>
using namespace std;
class List 
{
private:
    int* arr;
    int capacity;
    int size;

public:
    // default constructor
    List()
    {
        arr = new int[3];
        for (int i = 0; i < 3; i++)
        {
            arr[i] = i + 1;
        }
        size = 0;
    }
    // Constructors 
    List(int capacity ) 
    {
        this->capacity = capacity;
        arr = new int[capacity];
        for (int i = 0; i < capacity; i++)
        {
            arr[i] = i + 1;
        }
        size = 0;
    }
    //copy constructor
    List(const List& listObj) 
    {
        capacity = listObj.capacity;
        size = listObj.size;
        arr = new int[capacity];
        for (int i = 0; i < size; ++i) 
        {
            arr[i] = listObj.arr[i];
        }
    }
    //destructor
    ~List() {
        delete[] arr;
    }

    // display function
    void printList(List obj) 
    {
        for (int i = 0; i < size; ++i) 
        {
            cout << obj.arr[i] << " ";
        }
            cout << endl;
    }
    //search funciton
    int searchElement(int X) 
    {
        for (int i = 0; i < size; ++i)
        {
            if (arr[i] == X) {
                return i; 
            }
        }
        cout << "Element is not in the List" << endl;
    }
    // insert function
    void insertElementAt(int X, int pos)
    {
        if (isFull()) 
        {
            
            int newCapacity = capacity * 2; 
            int* newArr = new int[newCapacity];

            for (int i = 0; i < size; ++i) 
            {
                newArr[i] = arr[i];
            }

            delete[] arr; 
            arr = newArr; 
            capacity = newCapacity; 
        }

        if (pos < 0 || pos > size) 
        {
            cout << "Error: Invalid position for insertion." << endl;
            return;
        }

        for (int i = size; i > pos; --i) 
        {
            arr[i] = arr[i - 1];
        }
        arr[pos] = X;
        ++size;
    }

    // delete function
    bool deleteElement(int X)
    {
        int pos = searchElement(X);
        if (pos != -1) 
        {
            for (int i = pos; i < size - 1; ++i) 
            {
                arr[i] = arr[i + 1];
            }
            --size;
            return true; 
        }
        return false; 
    }
    // function to check if list is full
    bool isFull()
    {
        if (size == capacity)
        {
            return true;
        }
        else
            return false;
    }
    // function to check if list is empty
    bool isEmpty() const
    {
        if (size == 0)
        {
            return true;
        }
        else
            return false;
    }
    // function to display length of the list
    int length() 
    {
        return size;
    }
    // function to reverse the list
    void reverseList() 
    {
        int start = 0;
        int end = size - 1;
        while (start < end) 
        {
            swap(arr[start], arr[end]);
            ++start;
            --end;
        }
    }
    // function to empty the list
    void emptyList() 
    {
        for (int i = 0; i < size; ++i)
        {
            arr[i] = -1;
        }
        cout << "List Emptied" << endl;
    }
    // function to copy the list into anothe list
    void copyList(const List& other) 
    {
        if (this != &other) 
        {
            delete[] arr;
            capacity = other.capacity;
            size = other.size;
            arr = new int[capacity];
            for (int i = 0; i < size; ++i) 
            {
                arr[i] = other.arr[i];
            }
        }
    }
};


int main() 
{
    List myList(10);

    int choice;
    while (true) 
    {
        cout << "\nMenu:\n";
        cout << "1. Print List\n";
        cout << "2. Search Element\n";
        cout << "3. Insert Element\n";
        cout << "4. Delete Element\n";
        cout << "5. Reverse List\n";
        cout << "6. Empty List\n";
        cout << "7. Copy List\n";
        cout << "8. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
        case 1:
            myList.printList(myList);
            break;

        case 2:
            int searchValue;
            cout << "Enter the value to search: ";
            cin >> searchValue;
            cout << "Element found at position " << myList.searchElement(searchValue) << endl;
            break;

        case 3:
            int val, pos;
            cout << "Enter the value to insert: ";
            cin >> val;
            cout << "Enter the position to insert: ";
            cin >> pos;
            myList.insertElementAt(val, pos);
            break;

        case 4:
            int deleteval;
            cout << "Enter the value to delete: ";
            cin >> deleteval;
            if (myList.deleteElement(deleteval)) 
            {
                cout << "Element deleted from the list." << endl;
            }
            else 
            {
                cout << "Element not found in the list." << endl;
            }
            break;

        case 5:
            myList.reverseList();
            cout << "List reversed." << endl;
            break;

        case 6:
            myList.emptyList();
            cout << "List emptied." <<endl;
            break;

        case 7:
        {
            List copyList;
            copyList.copyList(myList);
            cout << "List copied to another list." << endl;
        }
        break;

        case 8:
            return 0;

        default:
            cout << "The choice entered is wrong" << endl;
            break;
        }
    }

    return 0;
}
