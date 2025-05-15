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
            