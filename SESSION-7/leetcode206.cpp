#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* previous = NULL;
        ListNode* current = head;
        ListNode* nextNode = NULL;

        while(current != NULL) {
            nextNode = current->next;
            current->next = previous;
            previous = current;
            current = nextNode;
        }

        return previous;
    }
};

int main() {
    ListNode* firstNode = new ListNode(1);
    ListNode* secondNode = new ListNode(2);
    ListNode* thirdNode = new ListNode(3);
    
    firstNode->next = secondNode;
    secondNode->next = thirdNode;

    cout << "Original list: ";
    printList(firstNode);

    Solution solutionObj;
    ListNode* reversedList = solutionObj.reverseList(firstNode);

    cout << "Reversed list: ";
    printList(reversedList);

    return 0;
}

