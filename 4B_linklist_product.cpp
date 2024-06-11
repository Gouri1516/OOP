#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node() {
        data = 0;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    // Attach a node at the end of the list
    void attachEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Attach a node at the beginning of the list
    void attachBeginning(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    // Detach a node from the end of the list
    void detachEnd() {
        if (head == nullptr) {
            std::cout << "List is empty.\n";
            return;
        }

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    // Detach a node from the beginning of the list
    void detachBeginning() {
        if (head == nullptr) {
            std::cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Traverse and print the list
    void traverse() {
        if (head == nullptr) {
            std::cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    LinkedList list;

    int choice, value;
    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Attach at the end\n";
        std::cout << "2. Attach at the beginning\n";
        std::cout << "3. Detach from the end\n";
        std::cout << "4. Detach from the beginning\n";
        std::cout << "5. Traverse the list\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter value to attach at the end: ";
                std::cin >> value;
                list.attachEnd(value);
                break;
            case 2:
                std::cout << "Enter value to attach at the beginning: ";
                std::cin >> value;
                list.attachBeginning(value);
                break;
            case 3:
                list.detachEnd();
                break;
            case 4:
                list.detachBeginning();
                break;
            case 5:
                std::cout << "List contents: ";
                list.traverse();
                break;
            case 6:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}

