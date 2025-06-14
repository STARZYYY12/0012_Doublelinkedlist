#include <iostream>
#include <string>
using namespace std;

class Node
{
    public:
        int noMhs;
        Node *next;
        Node *prev;
};

class DoubleLinkedList
{
    private:
        Node *START;

    public:
        DoubleLinkedList()
        {
            START = NULL;
        }

        void addNode()
        {
            int nim;
            string nm;
            cout << "\nEnter the roll number of the student";
            cin >> nim;

            // Step 1: Allcate memory for new node
            Node *newNode = new Node();

            
            // Step 2: Assign value to the data fields
            newNode->noMhs = nim;

            //Step 3 Insert at beginning if list is empty or nim is smallest
            if (START == NULL || nim <= START->noMhs)
            {
                if (START != NULL && nim == START->noMhs)
                {
                    cout << "\nDuplicate number not allowed" << endl;
                    return;
                }
                
            //step 4
            newNode->next = START;

            //step5
            if (START != NULL)
                START->prev = newNode;

            //step 6
            newNode->prev = NULL;
            
            //step 7
            START = newNode;
            return;
            } 

            //insert om between node
            //step 8
            Node *current = START;
            while (current->next !=NULL && current->next->noMhs < nim)
            {
                current = current->next;    
            }

            if (current->next !=NULL && nim == current->next->noMhs)
            {
                cout << "\nDuplicate roll number not allowed" << endl;
                return;

            }

            //step 9
            newNode->next = current->next; //part A
            newNode->prev = current; //part B

            //insert last node
            if (current->next != NULL)
                current->next->prev = newNode; //part C
            
            current->next = newNode; //part D
        }

        void hapus()
        {
            if (START == NULL)
           {
            cout << "nList is empty" << endl;
            return;
           }
           cout << "\nEnter the roll number of the student whose record is to be deleted: ";
           int rollNo;
           cin >> rollNo;

           Node *current = START;

           //step 1 traverse the lost tp final node
           while (current != NULL && current->noMhs != rollNo)
                current = current->next;

            if (current == NULL)
            {
                cout << "Record not found" << endl;
                return;
            }

            //step 2 if node is at the beginning\

            if (current == START)
            
        {
                 START = current->next;
                 if (START != NULL)
                 START->prev = NULL;

        }
        else
        {
            //step3 link previous node
            current->prev->next = current->next;

            //step 4 of cirrent os not the last node
            if (current->next != NULL)
                current->next->prev = current->prev;

        }

            //step5 delete the node
            delete current;
            cout << "Record with roll number " << rollNo << " deleted" << endl;

        }
    void traverse ()
    {
        if (START == NULL)
        {
            cout << "nList is empty" << endl;
            return;
        }

        //step 1 mark first node a currentNode
        Node *currentNode = START;
        //step2 repeat until currentNode = NULL
        cout << "\nRecord is ascending order of roll number are:\n";
        int i = 0;
        while (currentNode != NULL)
        {
           cout << i + i << ". " << currentNode->noMhs << " " << endl;

        //step3 move to the next node
        currentNode = currentNode->next;
        i++;
        }
    } 
    void revTraverse()
    {
        if (START = NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }

        //step 1 move to the last node
        Node *currentNode = START;
        int i = 0;
        while (currentNode->next != NULL)
        {
            currentNode = currentNode->prev;
            i--;
            
        }
        //step 2 traverse backward
        cout << "\nRecords in descending order of roll number are:\n";
        while (currentNode != NULL)
        {
            cout << i + i << ". " << currentNode->noMhs << " " << endl;

            //step 3
            currentNode = currentNode->prev;
            i--;

        }


    }


    void searchData()
    {
        if (START == NULL)
        {
            cout << "nList is empty" << endl;
            return;
        }

        int rollNo;
        cout << "\nEnter the roll number to search: ";
        cin >> rollNo;

        Node *current = START;

        //step 1 traverse to find

        while (current != NULL && current->noMhs != rollNo)
            current = current->next;

        // step 2 output result
        if (current == NULL)
        {
            cout << "Record not found\n";

        }
        else
        {
            cout << "Record found\n";
            cout << "Roll Number: " << current->noMhs << endl;
            

        }
    }
};

        int main()
        {
            DoubleLinkedList list;
            char choice;

            do 
            {
                
                 cout << "\nMenu: \n";
                 cout << "1. Add Record\n";
                 cout << "2. Delete Record\n";
                 cout << "3. View Ascending\n";
                 cout << "4. View Descending\n";
                 cout << "5. Search Record\n";
                 cout << "6. exit\n"; 
                 cout << "Enter The Number: ";
                cin >> choice;
                 switch (choice)
                 {
                    case '1':
                    list.addNode();
                    break;
                    case '2':
                    list.hapus();
                    break;
                    case '3':
                    list.traverse();
                    break;
                    case '4':
                    list.revTraverse();
                    break;
                    case '5':
                    list.searchData();
                    break;
                    case '6':
                    return 0;
                    default:
                        cout << "Invalid Option\n";        

                 }
                    cout << "\n Press enter to continue...";
                    cin.ignore();
                    cin.get();
                    cout << endl;
                    system("clear");
                  
                 }  while (choice != '6');
        }
    