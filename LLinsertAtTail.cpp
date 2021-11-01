/*
Insert a Node at the
Tail of a Linked List
You are given the pointer to the head node of a linked list and an integer to add to the list. Create a new
node with the given integer. Insert this node at the tail of the linked list and return the head node of the
linked list formed after inserting this new node. The given head pointer may be null, meaning that the
initial list is empty.
Input Format
You have to complete the Node* Insert(Node* head, int data) method. It takes two arguments: the head
of the linked list and the integer to insert. You should not read any input from the stdin/console.
Output Format
Insert the new node at the tail and just return the head of the updated linked list. Do not print anything
to stdout/console.
Sample Input
NULL, data =
--> NULL, data =
Sample Output
2 -->NULL
2 --> 3 --> NULL
Explanation
1. We have an empty list, and we insert .
2. We start with a in the tail. When is inserted, then becomes the tail.
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

        SinglyLinkedList() {
            this->head = nullptr;
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

// Complete the insertNodeAtTail function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {
SinglyLinkedListNode* item=new SinglyLinkedListNode(data);
SinglyLinkedListNode* tem=head;
if(head==NULL)
{
    head=item;
    return head;
}
while(tem->next!=NULL)
{
    tem=tem->next;
}
tem->next=item;
return head;
}

int main()