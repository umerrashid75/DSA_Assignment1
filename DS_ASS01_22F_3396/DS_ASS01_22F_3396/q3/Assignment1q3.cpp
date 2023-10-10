#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Employee 
{
public:
	string name;
	int workingHours;
    int wages;
public:
    Employee()
    {
        workingHours = 0;
    }
	Employee(string name, int workingHours)
	{
		this->name = name;
		this->workingHours = workingHours;
	}
	~Employee()
	{

	}
	int calculateWage(int workingHours)
	{

		wages= 50 * workingHours;
        return wages;
	}
};

struct Node
{
	Employee data;
	Node* next;

    Node(Employee value)
    {
        data = value;
        next = nullptr;

    }
};

class List {
private:
    Node* head;

public:
    List() {
        head = nullptr;
    }

    void insertAtBeginning(Employee value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

   


    void insertAtEnd(Employee value) {
        Node* newNode = new Node(value);
        //statement for starting condition
        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    void displayList() {
        Node* current = head;
        cout << "Name" << "\t" << "Wage" << endl;

        while (current != nullptr) {
            cout << current->data.name << "\t" << current->data.calculateWage(current->data.workingHours) << "\n";
            current = current->next;
        }
    }


};

int main()
{
    List list;
    ifstream fin("Employee.txt");
    ofstream fout("Wages.txt");

    if (!fin)
    {
        cout << "Failed to open the file." << endl;
        return 1;
    }

    fout << "Name" << "\t" << "Wage" << endl;

    while (!fin.eof()) 
    {
        Employee employee;
        getline(fin, employee.name, ',');
        fin >> employee.workingHours;
        fin.ignore(); 
        if (!fin.eof()) 
        {
            list.insertAtEnd(employee);
            fout << employee.name << "\t" << employee.calculateWage(employee.workingHours) << "\n";
        }
    }
    list.displayList();
    fin.close();
    fout.close();
    return 0;
}

