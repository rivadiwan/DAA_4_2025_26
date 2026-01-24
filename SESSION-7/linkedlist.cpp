// =================================================

// NAME : ABHINEET
// UID : 24BCS10039

// =================================================

#include<iostream>
using namespace std;

class LinkedList {
    struct Node {
        int value;
        Node* next;
        Node(int val) : value(val), next(nullptr) {}
    };
    
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void addToEnd(int val) {
        Node* freshNode = new Node(val);
        if (head == nullptr) {
            head = freshNode;
            return;
        }
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = freshNode;
    }

    void removeLast() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        Node* current = head;
        while (current->next != nullptr && current->next->next != nullptr) {
            current = current->next;
        }

        delete current->next;
        current->next = nullptr;
    }

    void removeValue(int val) {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }

        if (head->value == val) {
            Node* nodeToRemove = head;
            head = head->next;
            delete nodeToRemove;
            return;
        }

        Node* current = head;
        while (current->next != nullptr && current->next->value != val) {
            current = current->next;
        }

        if (current->next != nullptr && current->next->value == val) {
            Node* nodeToRemove = current->next;
            current->next = current->next->next;
            delete nodeToRemove;
        } else {
            cout << "Value not found\n";
        }
    }

    void showList() const {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        Node* current = head;
        while (current != nullptr) {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }

    void clearList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = nullptr;
    }

    void removeFromMiddle(int val) {
        if (head == nullptr || head->next == nullptr) {
            cout << "List too short\n";
            return;
        }
        
        if (head->value == val) {
            cout << "Cannot remove first node with this function\n";
            return;
        }

        Node* current = head;
        while (current->next != nullptr && current->next->next != nullptr && current->next->value != val) {
            current = current->next;
        }

        if (current->next != nullptr && current->next->value == val && current->next->next != nullptr) {
            Node* nodeToRemove = current->next;
            current->next = current->next->next;
            delete nodeToRemove;
            cout << "Removed from middle: " << val << "\n";
        } else {
            cout << "Node is not in the middle or not found\n";
        }
    }
};

int main() {
    LinkedList myList;
    myList.addToEnd(10);
    myList.addToEnd(20);
    myList.addToEnd(30);
    myList.addToEnd(40);
    myList.showList();

    // Try to remove a middle node (20)
    myList.removeFromMiddle(20);
    myList.showList();

    // Try to remove first node (should not remove)
    myList.removeFromMiddle(10);
    myList.showList();

    // Try to remove last node (should not remove)
    myList.removeFromMiddle(40);
    myList.showList();

    // Try to remove a value not in list
    myList.removeFromMiddle(99);
    myList.showList();

    myList.clearList();
    myList.showList();
    return 0;
}


// ======================================================================
// Time Complexity Of Each Function

// addToEnd:         O(n)   // Traverses the list to add at the end
// removeLast:       O(n)   // Traverses to the second last node
// removeValue:      O(n)   // Traverses to find the value
// showList:         O(n)   // Prints all nodes
// clearList:        O(n)   // Deletes all nodes
// removeFromMiddle: O(n)   // Traverses to find the value (not first/last)