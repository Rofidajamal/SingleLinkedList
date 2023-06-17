#include <iostream>

using namespace std;

template <typename T>
struct node {
    node* link;
    T info;
};

template <class T>
class LinkedList {
private:
    node<T>* head;
    node<T>* last;
    int length;

public:
    LinkedList() {
        head = NULL;
        last = NULL;
        length = 0;
    }

    bool isEmpty() {
        return length == 0;
    }

    void insertFirst(T item) {
        node<T>* newNode = new node<T>;
        newNode->info = item;
        if (isEmpty()) {
            head = last = newNode;
            newNode->link = NULL;
        }
        else {
            newNode->link = head;
            head = newNode;
        }
        length++;
    }

    void insertLast(T item) {
        node<T>* newNode = new node<T>;
        newNode->info = item;
        if (isEmpty()) {
            head = last = newNode;
            newNode->link = NULL;
        }
        else {
            last->link = newNode;
            newNode->link = NULL;
            last = newNode;
        }
        length++;
    }

    void insertAtPosition(int pos, T item) {
        if (pos < 0 || pos > length) {
            cout << "Invalid position";
        }
        else if (pos == 0) {
            insertFirst(item);
        }
        else if (pos == length) {
            insertLast(item);
        }
        else {
            node<T>* newNode = new node<T>;
            newNode->info = item;
            node<T>* current = head;

            for (int i = 1; i < pos; i++) {
                current = current->link;
            }
            newNode->link = current->link;
            current->link = newNode;
            length++;
        }
    }

    void removeFirst() {
        if (isEmpty()) {
            cout << "Can't remove as list is Empty.\n";
        }
        else if (length == 1) {
            delete head;
            head = last = NULL;
            length--;
        }
        else {
            node<T>* current = head;
            head = head->link;
            delete current;
            length--;
        }
    }

    void removeLast() {
        if (isEmpty()) {
            cout << "Can't remove as list is Empty.\n";
        }
        else if (length == 1) {
            delete head;
            head = last = NULL;
            length--;
        }
        else {
            node<T>* current = head->link;
            node<T>* prev = head;

            while (current != last) {
                prev = current;
                current = current->link;
            }

            delete current;
            prev->link = NULL;
            last = prev;
            length--;
        }
    }

    void removeElement(T item) {
        if (isEmpty()) {
            cout << "Can't remove as list is Empty.\n";
        }
        else {
            node<T>* curr;
            node<T>* prev;
            // Check if the item is in the first node
            if (head->info == item) {
                curr = head;
                head = head->link;
                delete curr;
                length--;
                if (length == 0) {
                    last = NULL;
                }
            }
            else {
                curr = head->link;
                prev = head;

                while (curr != NULL && curr->info != item) {
                    prev = curr;
                    curr = curr->link;
                }

                if (curr == NULL) {
                    cout << "Element not found \n";
                }
                else {
                    prev->link = curr->link;
                    if (last == curr) {
                        last = prev;
                    }
                    delete curr;
                    length--;
                }
            }
        }
    }

    int Search(T item) {
        int pos = 0;
        node<T>* curr = head;
        while (curr != NULL) {
            if (curr->info == item)
                return pos;
            curr = curr->link;
            pos += 1;
        }
        return -1;
    }

    void Traverse() {
        node<T>* current = head;
        cout<< "[";
        while (current != NULL) {
            cout << current->info << " ";
            current = current->link;
        }
        cout<<"]";
    }

    int Size() {
        return length;
    }
};



int main() {
    LinkedList<int> linked;
    int numbers=0;
    int element = -1;
    int pos =0;

    cout<<"Here is your start to make an integer linked list \n============================================\n";

    while (true){

        char choice;

        cout<<"Menu : \n1- Insert Forward -at the start- \n2- Insert Backward -at the end-\n3- Insert at a specific position \n4- Remove the first element\n5-Remove the last element\n";
        cout<<"6- Remove a specific element\n7- Search for an element\n8- Print the size of the linked list\n9- print the Linked list elements\n10- enter e to Exit\n";
        cin>> choice;
        cout<<"\n============================================\n\n";

        if(choice == 'e' || choice == 'E'){
            break;
        }

        else if (choice == '1' ){
            cout<<"How many elements you want to add \n";
            cin>> numbers;
            cout<<"\nEnter the elements \n";
            for(int i =0; i<numbers;i++){
                cin>>element;
                linked.insertFirst(element);
            }
            cout<<"\nLinked list after adding :\n";
            linked.Traverse();
            cout<<"\n============================================\n\n";
        }
        else if (choice == '2'){
            cout<<"How many elements you want to add \n";
            cin>> numbers;
            cout<<"\nEnter the elements \n";
            for(int i =0; i<numbers;i++){
                cin>>element;
                linked.insertLast(element);
            }
            cout<<"\nLinked list after adding :\n";
            linked.Traverse();
            cout<<"\n============================================\n\n";

        }

        else if( choice == '3'){
            cout<<"Enter the position\n";
            cin>>pos;
            cout<<"Enter the element\n";
            cin>>element;
            linked.insertAtPosition(pos,element);
            cout<<"\nLinked list after adding :\n";
            linked.Traverse();
            cout<<"\n============================================\n\n";


        }
        else if(choice == '4'){
            cout<<"Linked list before removing\n";
            linked.Traverse();
            linked.removeFirst();
            cout<<"\nLinked list after removing the first element :\n";
            linked.Traverse();
            cout<<"\n============================================\n\n";

        }
        else if(choice == '5'){
            cout<<"Linked list before removing\n";
            linked.Traverse();
            linked.removeLast();
            cout<<"\nLinked list after removing the last element :\n";
            linked.Traverse();
            cout<<"\n============================================\n\n";

        }
        else if (choice == '6'){
            cout<<"Enter the element you want to remove it \n";
            cin>>element;
            cout<<"\nLinked list before removing\n";
            linked.Traverse();
            linked.removeElement(element);
            cout<<"\nLinked list after removing the last element :\n";
            linked.Traverse();
            cout<<"\n============================================\n\n";

        }
        else if (choice == '7'){
            cout<<"Enter the element you want to search for\n";
            cin>>element;
            pos = linked.Search(element);
            if (pos == -1){
                cout<<"Not Found \n";
            }
            else {
                cout<<element<<" at position "<<pos<<endl;
            }
        }
        else if (choice == '8'){
            int s = linked.Size();
            cout<<"The size of linked list is" << s<<endl;
            cout<<"\n============================================\n\n";
        }
        else if (choice == '9'){
            cout<<"Linked list Elements: \n";
            linked.Traverse();
            cout<<"\n============================================\n\n";
        }

    }


    return 0;
}
