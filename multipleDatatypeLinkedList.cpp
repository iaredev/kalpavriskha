#include <iostream>
#include <string>
using namespace std;

class node {
public:
    node* nextptr;
    int data;
    string ss;
    char cc;
    double dd;
    bool stringTrue = false;
    bool intTrue = false;
    bool charTrue = false;
    bool doubleTrue = false;
    
    node() {
        nextptr = NULL;
    }
    
    node(int d) {
        data = d;
        nextptr = NULL;
        intTrue = true;
    }

    node(string s) {
        ss = s;
        nextptr = NULL;
        stringTrue = true;
    }
    
    node(char c) {
        cc = c;
        nextptr = NULL;
        charTrue = true;
    }
    
    node(double d) {
        dd = d;
        nextptr = NULL;
        doubleTrue = true;
    }

    int getintData() {
        return data;
    }

    string getstringData() {
        return ss;
    }

    double getdoubleData() {
        return dd;
    }

    char getcharData() {
        return cc;
    }

    void setintData(int d) {
        data = d;
    }

    void setstringData(string s) {
        ss = s;
    }

    void setdoubleData(double d) {
        dd = d;
    }

    void setcharData(char c) {
        cc = c;
    }

    char checkWhichInput() {
        if (intTrue) {
            return 'i';
        }
        else if (stringTrue) {
            return 's';
        }
        else if (doubleTrue) {
            return 'd';
        }
        else if (charTrue) {
            return 'c';
        }
    }

    node* getNextptr() {
        return nextptr;
    }

    void setnextptr(node* nptr) {
        nextptr = nptr;
    }
};


class linkedlist {
    node* headptr;
    node* addnodeatspecificpoition;
    
public:
    linkedlist() {
        headptr = NULL;
    }
    
    void insertionAtTail(node* n) {
        if (headptr == NULL) {
            headptr = n;
        }
        else {
            node* rptr = headptr;
            while (rptr->getNextptr() != NULL) {
                rptr = rptr->getNextptr();
            }
            rptr->setnextptr(n);
        }
    }

    void insertionAtHead(node *n) {
        node* tmp = n;
        tmp->setnextptr(headptr);
        headptr = tmp;
    }

    int sizeOfLinkedList() {
        int i = 0;
        node* ptr = headptr;
        while (ptr != NULL) {
            ++i;
            ptr = ptr->getNextptr();
        }
        return i;
    }

    bool isListEmpty() {
        return headptr == NULL;
    }

    void insertionAtAnyPoint(node* n, int position) {
        if (position <= 0 || position > sizeOfLinkedList() + 1) {
            cout << "\n\nInvalid insertion at index: " << position;
            cout << ". There is no index " << position << " in the linked list. ERROR.\n\n";
            return;
        }

        addnodeatspecificpoition = n;
        addnodeatspecificpoition->setnextptr(NULL);

        if (headptr == NULL) {
            headptr = addnodeatspecificpoition;
        }
        else if (position == 1) {
            addnodeatspecificpoition->setnextptr(headptr);
            headptr = addnodeatspecificpoition;
        }
        else {
            node* current = headptr;
            int i = 1;
            while (i < position - 1) {
                current = current->getNextptr();
                i++;
            }
            addnodeatspecificpoition->setnextptr(current->getNextptr());
            current->setnextptr(addnodeatspecificpoition);
        }
    }

    void removeAtHead() {
        if (headptr == NULL) {
            cout << "\nCannot remove from an empty list.\n";
            return;
        }
        node* temp = headptr;
        headptr = headptr->getNextptr();
        delete temp;
    }

    void removeAtTail() {
        if (headptr == NULL) {
            cout << "\nCannot remove from an empty list.\n";
            return;
        }
        if (headptr->getNextptr() == NULL) {
            delete headptr;
            headptr = NULL;
            return;
        }
        node* current = headptr;
        while (current->getNextptr()->getNextptr() != NULL) {
            current = current->getNextptr();
        }
        delete current->getNextptr();
        current->setnextptr(NULL);
    }

    void displayList() {
        node* ptr = headptr;
        while (ptr != NULL) {
            switch (ptr->checkWhichInput()) {
                case 'i':
                    cout << ptr->getintData() << endl;
                    break;
                case 's':
                    cout << ptr->getstringData() << endl;
                    break;
                case 'd':
                    cout << ptr->getdoubleData() << endl;
                    break;
                case 'c':
                    cout << ptr->getcharData() << endl;
                    break;
                default:
                    break;
            }
            ptr = ptr->getNextptr();
        }
    }
};


int main() {
    linkedlist L1;

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Insert at tail\n";
        cout << "2. Insert at head\n";
        cout << "3. Insert at any position\n";
        cout << "4. Remove from head\n";
        cout << "5. Remove from tail\n";
        cout << "6. Display\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int dataChoice;
                cout << "\nSelect data type for insertion:\n";
                cout << "1. Integer\n";
                cout << "2. String\n";
                cout << "3. Character\n";
                cout << "4. Double\n";
                cout << "Enter your choice: ";
                cin >> dataChoice;

                switch (dataChoice) {
                    case 1: {
                        int value;
                        cout << "Enter integer value to insert: ";
                        cin >> value;
                        L1.insertionAtTail(new node(value));
                        break;
                    }
                    case 2: {
                        string value;
                        cout << "Enter string value to insert: ";
                        cin >> value;
                        L1.insertionAtTail(new node(value));
                        break;
                    }
                    case 3: {
                        char value;
                        cout << "Enter character value to insert: ";
                        cin >> value;
                        L1.insertionAtTail(new node(value));
                        break;
                    }
                    case 4: {
                        double value;
                        cout << "Enter double value to insert: ";
                        cin >> value;
                        L1.insertionAtTail(new node(value));
                        break;
                    }
                    default:
                        cout << "Invalid choice.\n";
                        break;
                }
                break;
            }
            case 2: {
                int dataChoice;
                cout << "\nSelect data type for insertion:\n";
                cout << "1. Integer\n";
                cout << "2. String\n";
                cout << "3. Character\n";
                cout << "4. Double\n";
                cout << "Enter your choice: ";
                cin >> dataChoice;

                switch (dataChoice) {
                    case 1: {
                        int value;
                        cout << "Enter integer value to insert: ";
                        cin >> value;
                        L1.insertionAtHead(new node(value));
                        break;
                    }
                    case 2: {
                        string value;
                        cout << "Enter string value to insert: ";
                        cin >> value;
                        L1.insertionAtHead(new node(value));
                        break;
                    }
                    case 3: {
                        char value;
                        cout << "Enter character value to insert: ";
                        cin >> value;
                        L1.insertionAtHead(new node(value));
                        break;
                    }
                    case 4: {
                        double value;
                        cout << "Enter double value to insert: ";
                        cin >> value;
                        L1.insertionAtHead(new node(value));
                        break;
                    }
                    default:
                        cout << "Invalid choice.\n";
                        break;
                }
                break;
            }
            case 3: {
                int position;
                cout << "Enter position to insert: ";
                cin >> position;
                int dataChoice;
                cout << "\nSelect data type for insertion:\n";
                cout << "1. Integer\n";
                cout << "2. String\n";
                cout << "3. Character\n";
                cout << "4. Double\n";
                cout << "Enter your choice: ";
                cin >> dataChoice;

                switch (dataChoice) {
                    case 1: {
                        int value;
                        cout << "Enter integer value to insert: ";
                        cin >> value;
                        L1.insertionAtAnyPoint(new node(value), position);
                        break;
                    }
                    case 2: {
                        string value;
                        cout << "Enter string value to insert: ";
                        cin >> value;
                        L1.insertionAtAnyPoint(new node(value), position);
                        break;
                    }
                    case 3: {
                        char value;
                        cout << "Enter character value to insert: ";
                        cin >> value;
                        L1.insertionAtAnyPoint(new node(value), position);
                        break;
                    }
                    case 4: {
                        double value;
                        cout << "Enter double value to insert: ";
                        cin >> value;
                        L1.insertionAtAnyPoint(new node(value), position);
                        break;
                    }
                    default:
                        cout << "Invalid choice.\n";
                        break;
                }
                break;
            }
            case 4:
                L1.removeAtHead();
                break;
            case 5:
                L1.removeAtTail();
                break;
            case 6:
                L1.displayList();
                break;
            case 7:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
                break;
        }

    } while (choice != 7);

    return 0;
}
