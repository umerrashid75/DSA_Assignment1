#include <iostream>
using namespace std;


struct Message 
{
    int id;
    Message* next;
    Message(int id)
    {
        this->id = id;
        next = nullptr;
    }
};


class Gmail 
{
private:
    Message* unreadHead;
    Message* readHead;
    Message* trashHead;

public:
    Gmail()
    {
        unreadHead = nullptr;
        readHead = nullptr;
        trashHead = nullptr;
    }

    
    void move(int id, Message*& prevlocation, Message*& newlocation) 
    {
        if (prevlocation->id == id) 
        {
            Message* movedMessage = prevlocation;
            prevlocation = prevlocation->next;
            movedMessage->next = newlocation;
            newlocation = movedMessage;
        }
        else 
        {
            Message* prev = nullptr;
            Message* current = prevlocation;
            while (current && current->id != id)
            {
                prev = current;
                current = current->next;
            }

            if (current)
            {
                prev->next = current->next;
                current->next = newlocation;
                newlocation = current;
            }
        }
    }

    
    void addUnreadMessage(int id) 
    {
        Message* newMessage = new Message(id);
        newMessage->next = unreadHead;
        unreadHead = newMessage;
    }

    
    void printSection(Message* section) 
    {
        if (!section)
        {
            cout << "EMPTY";
        }
        else
        {
            while (section)
            {
                cout << section->id << " ";
                section = section->next;
            }
        }
        cout << endl;
    }

    
    void handleQuery(int queryType, int id) 
    {
        switch (queryType)
        {
        case 1:  
            move(id, unreadHead, readHead);
            break;
        case 2:  
            move(id, readHead, trashHead);
            break;
        case 3:  
            move(id, unreadHead, trashHead);
            break;
        case 4:  
            move(id, trashHead, readHead);
            break;
        }
    }

    
    void printAllSections() 
    {
        printSection(unreadHead);
        printSection(readHead);
        printSection(trashHead);
    }
};

int main() 
{
    Gmail mailbox;
    int N;
    cout << "Enter the number of initial messages: ";
    cin >> N;

    
    for (int i = N; i >=1; i--) 
    {
        mailbox.addUnreadMessage(i);
    }

    int Q;
    cout << "Enter the number of queries: ";
    cin >> Q;

    for (int i = 0; i < Q; i++) 
    {
        cout << "Menu:\n";
        cout << "1. Move a message from UNREAD to READ\n";
        cout << "2. Move a message from READ to TRASH\n";
        cout << "3. Move a message from UNREAD to TRASH\n";
        cout << "4. Move a message from TRASH to READ\n";
        cout << "Enter query type and message ID : ";

        int type, id;
        cin >> type >> id;
        mailbox.handleQuery(type, id);
        cout << "Updated sections:\n";
        mailbox.printAllSections();
    }

    return 0;
}

