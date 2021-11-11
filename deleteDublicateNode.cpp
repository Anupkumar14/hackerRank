/*
Delete duplicatevalue nodes from a
sorted linked list
You're given the pointer to the head node of a sorted linked list, where the data in the nodes is in
ascending order. Delete as few nodes as possible so that the list does not contain any value more than
once. The given head pointer may be null indicating that the list is empty.
For now do not be concerned with the memory deallocation. In common abstract data structure scenarios,
deleting an element might also require deallocating the memory occupied by it. For an initial intro to the
topic of dynamic memory please consult: http://www.cplusplus.com/doc/tutorial/dynamic/
Input Format
You have to complete the Node* RemoveDuplicates(Node* head) method which takes one argument - the
head of the sorted linked list. You should NOT read any input from stdin/console.
Output Format
Delete as few nodes as possible to ensure that no two nodes have the same data. Adjust the next
pointers to ensure that the remaining nodes form a single sorted linked list. Then return the head of the
sorted updated linked list. Do NOT print anything to stdout/console.
Sample Input
1 -> 1 -> 3 -> 3 -> 5 -> 6 -> NULL
NULL
Sample Output
1 -> 3 -> 5 -> 6 -> NULL
NULL
Explanation
1. 1 and 3 are repeated, and are deleted.
2. Empty list remains empty.
This challenge is part of a tutorial track byMyCodeSchool

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
 * Complete the 'removeDuplicates' function below.
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

SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* llist) {
        SinglyLinkedListNode* tem=llist;
        if(tem==NULL)return llist;
        while(tem->next!=NULL){
            if(tem->data==tem->next->data){
                tem->next=tem->next->next;
            }
            else {
            tem=tem->next;
            }
        }
        return llist;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
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

        SinglyLinkedListNode* llist1 = removeDuplicates(llist->head);

        print_singly_linked_list(llist1, " ", fout);
        fout << "\n";

        free_singly_linked_list(llist1);
    }

    fout.close();

    return 0;
}
