/*
Insert a node at the
head of a linked list
You’re given the pointer to the head node of a linked list and an integer to add to the list. Create a new
node with the given integer, insert this node at the head of the linked list and return the new head node.
The head pointer given may be null meaning that the initial list is empty.
Input Format
You have to complete the Node* Insert(Node* head, int data) method which takes two arguments - the
head of the linked list and the integer to insert. You should NOT read any input from stdin/console.
Output Format
Insert the new node at the head and return the head of the updated linked list. Do NOT print anything to
stdout/console.
Sample Input
NULL , data = 1
1 --> NULL , data = 2
Sample Output
1 --> NULL
2 --> 1 --> NULL
Explanation
1. We have an empty list, on inserting 1, 1 becomes new head.
2. We have a list with 1 as head, on inserting 2, 2 becomes the new head.
Video lesson
This challenge is part of a tutorial track byMyCodeSchool and is accompanied by a video lesson.

solution:
*/

#include <bits/stdc++.h>

using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

// Complete the insertNodeAtHead function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* insertNodeAtHead(SinglyLinkedListNode* llist, int data) {
SinglyLinkedListNode* tem=new SinglyLinkedListNode(data);
tem->next=llist;
llist=tem;
return llist;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    SinglyLinkedList* llist = new SinglyLinkedList();

    int llist_count;
    cin >> llist_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < llist_count; i++) {
        int llist_item;
        cin >> llist_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
      	SinglyLinkedListNode* llist_head = insertNodeAtHead(llist->head, llist_item);
        llist->head = llist_head;
    }

    print_singly_linked_list(llist->head, "\n", fout);
    fout << "\n";

    free_singly_linked_list(llist->head);

    fout.close();

    return 0;
}
