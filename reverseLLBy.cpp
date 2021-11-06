/*
Reverse a linked list
You’re given the pointer to the head node of a linked list. Change the next pointers of the nodes so that
their order is reversed. The head pointer given may be null meaning that the initial list is empty.
Input Format
You have to complete the Node* Reverse(Node* head) method which takes one argument - the head of
the linked list. You should NOT read any input from stdin/console.
Output Format
Change the next pointers of the nodes that their order is reversed and return the head of the reversed
linked list. Do NOT print anything to stdout/console.
Sample Input
NULL
2 --> 3 --> NULL
Sample Output
NULL
3 --> 2 --> NULL
Explanation
1. Empty list remains empty
2. List is reversed from 2,3 to 3,2
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

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
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

/*
 * Complete the 'reverse' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts INTEGER_SINGLY_LINKED_LIST llist as parameter.
 */

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

SinglyLinkedListNode* reverse(SinglyLinkedListNode* llist) {
    SinglyLinkedListNode* prev=NULL;
    SinglyLinkedListNode* next;
    while(llist!=NULL){
        next=llist->next;
        llist->next=prev;
        prev=llist;
        llist=next;
    }
    llist=prev;
    return llist;
}

int main()