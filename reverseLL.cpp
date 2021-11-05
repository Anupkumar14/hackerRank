/*
Print in Reverse
You are given the pointer to the head node of a linked list and you need to print all its elements in reverse
order from tail to head, one element per line. The head pointer may be null meaning that the list is empty
- in that case, do not print anything!
Input Format
You have to complete the void ReversePrint(Node* head) method which takes one argument - the head
of the linked list. You should NOT read any input from stdin/console.
Output Format
Print the elements of the linked list in reverse order to stdout/console (using printf or cout) , one per line.
Sample Input
1 --> 2 --> NULL
2 --> 1 --> 4 --> 5 --> NULL
Sample Output
2
1
5
4
1
2
Explanation
1. First list is printed from tail to head hence 2,1
2. Similarly second list is also printed from tail to head.
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

void print_singly_linked_list(SinglyLinkedListNode* node, string sep) {
    while (node) {
        cout << node->data;

        node = node->next;

        if (node) {
            cout << sep;
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
 * Complete the 'reversePrint' function below.
 *
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

void reversePrint(SinglyLinkedListNode* llist) {
    SinglyLinkedListNode* prev= NULL;
    // SinglyLinkedListNode* curr=llist;
    SinglyLinkedListNode* next;
    while(llist!=NULL){
        next=llist->next;
        llist->next=prev;
        prev=llist;
        llist=next;
    }
    llist=prev;
    while (llist!=NULL) {
    cout<<llist->data<<endl;
    llist=llist->next;
    }
}

int main()
{
    int tests;
    cin >> tests;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int tests_itr = 0; tests_itr < tests; tests_itr++) {
        SinglyLinkedList* llist = new SinglyLinkedList();

        int llist_count;
        cin >> llist_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < llist_count; i++) {
            int llist_item;
            cin >> llist_item;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            llist->insert_node(llist_item);
        }

        reversePrint(llist->head);
    }

    return 0;
}
