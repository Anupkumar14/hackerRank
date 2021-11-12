/*
Find Merge Point of
Two Lists
This challenge is part of a tutorial track by MyCodeSchool
Given pointers to the head nodes of linked lists that merge together at some point, find the Node where
the two lists merge. It is guaranteed that the two head Nodes will be different, and neither will be NULL.
In the diagram below, the two lists converge at Node x :
[List #1] a--->b--->c
\
x--->y--->z--->NULL
/
[List #2] p--->q
Complete the int FindMergeNode(Node* headA, Node* headB) method so that it finds and returns the
data value of the Node where the two lists merge.
Input Format
Do not read any input from stdin/console.
The FindMergeNode(Node*,Node*) method has two parameters, and , which are the nonnull head Nodes of two separate linked lists that are guaranteed to converge.
Constraints
The lists will merge.
.headA,headB!=NULL
.headA!=headB
Output Format
Do not write any output to stdout/console.
Each Node has a data field containing an integer. Return the integer data for the Node where the two lists
merge.
Sample Input
The diagrams below are graphical representations of the lists that input Nodes and are
connected to. Recall that this is a method-only challenge; the method only has initial visibility to those
Nodes and must explore the rest of the Nodes using some algorithm of your own design.
Test Case 0
1
\
 2--->3--->NULL
/
1
Test Case 1
1--->2
      \
       3--->Null
      /
     1
Sample Output
2
3
Explanation
Test Case 0: As demonstrated in the diagram above, the merge Node's data field contains the integer .
Test Case 1: As demonstrated in the diagram above, the merge Node's data field contains the integer .

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

// Complete the findMergeNode function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
 int length(SinglyLinkedListNode* head){
     int l=0;
     SinglyLinkedListNode* tem=head;
     while (tem!=NULL) {
        tem=tem->next;
        l++;
     }
     return l;
 }
int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {   
    int l1=length(head1);
    int l2=length(head2);
    int d=0;
    SinglyLinkedListNode* tem1;
    SinglyLinkedListNode* tem2;
    if(l1>l2){
        d=l1-l2;
        tem1=head1;
        tem2=head2;
    }
    else {
        d=l2-l1;
        tem1=head2;
        tem2=head1;
    }
    while (d) {
        tem1=tem1->next;
        if(tem1==NULL){
            return -1;
        }
        d--;
    }
    while (tem1!=NULL && tem2!=NULL) {
        if(tem1==tem2){
            return tem1->data;
        }
        tem1=tem1->next;
        tem2=tem2->next;
    }
    return -1;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int tests;
    cin >> tests;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int tests_itr = 0; tests_itr < tests; tests_itr++) {
        int index;
        cin >> index;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

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
      
      	SinglyLinkedListNode* ptr1 = llist1->head;
      	SinglyLinkedListNode* ptr2 = llist2->head;
      
      	for (int i = 0; i < llist1_count; i++) {
            if (i < index) {
          		ptr1 = ptr1->next;
            }
        }
      
      	for (int i = 0; i < llist2_count; i++) {
          	if (i != llist2_count-1) {
          		ptr2 = ptr2->next;
            }
        }
      
      	ptr2->next = ptr1;

        int result = findMergeNode(llist1->head, llist2->head);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
