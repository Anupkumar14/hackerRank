/*
Merge two sorted
linked lists
You’re given the pointer to the head nodes of two sorted linked lists. The data in both lists will be sorted in
ascending order. Change the next pointers to obtain a single, merged linked list which also has data in
ascending order. Either head pointer given may be null meaning that the corresponding list is empty.
Input Format
You have to complete the Node* MergeLists(Node* headA, Node* headB) method which takes two
arguments - the heads of the two sorted linked lists to merge. You should NOT read any input from
stdin/console.
Output Format
Change the next pointer of individual nodes so that nodes from both lists are merged into a single list.
Then return the head of this merged list. Do NOT print anything to stdout/console.
Sample Input
1 -> 3 -> 5 -> 6 -> NULL
2 -> 4 -> 7 -> NULL
15 -> NULL
12 -> NULL
NULL
1 -> 2 -> NULL
Sample Output
1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> NULL
12 -> 15 -> NULL
1 -> 2 -> NULL
Explanation
1. We merge elements in both list in sorted order and output.
This challenge is part of a tutorial track byMyCodeSchool

solution: 
1.iterative method
2.recursive method
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

// Complete the mergeLists function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode* p=head1;
    SinglyLinkedListNode* p1=head2;
    SinglyLinkedListNode* dummynode=new SinglyLinkedListNode(-1);
    SinglyLinkedListNode* tem=dummynode;
    
    while(p!=NULL && p1!=NULL){
        if(p->data<p1->data){
            tem->next=p;
            p=p->next;
        }
        else {
            tem->next=p1;
            p1=p1->next;
        }
        tem=tem->next;
    }
    while (p!=NULL) {
        tem->next=p;
        p=p->next;
        tem=tem->next;
    }
    while (p1!=NULL) {
        tem->next=p1;
        p1=p1->next;
        tem=tem->next;
    }
    return dummynode->next;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int tests;
    cin >> tests;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int tests_itr = 0; tests_itr < tests; tests_itr++) {
        SinglyLinkedList* llist1 = new SinglyLinkedList();

        int llist1_count;
        cin >> llist1_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < llist1_count; i++) {
            int llist1_item;
            cin >> llist1_item;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            llist1->insert_node(llist1_item);
        }
      
      	SinglyLinkedList* llist2 = new SinglyLinkedList();

        int llist2_count;
        cin >> llist2_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < llist2_count; i++) {
            int llist2_item;
            cin >> llist2_item;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            llist2->insert_node(llist2_item);
        }

        SinglyLinkedListNode* llist3 = mergeLists(llist1->head, llist2->head);

        print_singly_linked_list(llist3, " ", fout);
        fout << "\n";

        free_singly_linked_list(llist3);
    }

    fout.close();

    return 0;
}
