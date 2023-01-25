// problem link
// https://leetcode.com/problems/insertion-sort-list/description/

class Node {
public:
    int val;
    Node* next;

    Node() {
        this->next = NULL;
    }

    Node(int value) {
        this->val = value;
        this->next = NULL;
    }

    Node(int value, Node* address) {
        this->val = value;
        this->next = address;
    }
};

class MyLinkedList {
public:
    int size=0;
    Node* head=NULL;
    Node* tail=NULL;
    
    MyLinkedList() {

    }
    
    int get(int index) {
        if(index >= size) return -1;
        int ct = 0;
        Node* trav = this->head;
        while(ct < index) {
            trav = trav->next;
            ++ct;
        }
        return trav->val;
    }
    
    void addAtHead(int val) {
        Node* new_node = new Node(val, head);
        this->head = new_node;
        if(this->tail == NULL) this->tail = this->head;
        this->size += 1;
    }
    
    void addAtTail(int val) {
        if(this->head == NULL) {
            this->addAtHead(val);
            return;
        }
        Node* new_node = new Node(val);
        this->tail->next = new_node;
        this->tail = new_node;
        this->size += 1;
    }
    
    void addAtIndex(int index, int val) {
        if(index == 0) {
            this->addAtHead(val);
            return;
        }

        if(index == this->size) {
            this->addAtTail(val);
            return;
        }

        if(index > this->size) return;

        int ct = 1;
        Node* trav = this->head;
        while(ct<index) {
            trav = trav->next;
            ++ct;
        }
        Node* new_node = new Node(val, trav->next);
        trav->next = new_node;
        this->size += 1;
    }
    
    void deleteAtIndex(int index) {
        if(index >= this->size) return;
        Node* trav = new Node(0);
        trav->next = this->head;
        int ct = 0;

        while(ct < index) {
            trav = trav->next;
            ++ct;
        }
        
        Node* tmp = trav->next;
        trav->next = tmp->next;
        if(tmp == this->head) this->head = this->head->next;
        if(tmp == this->tail) this->tail = trav;
        delete tmp;
        this->size -= 1;
        if(this->size == 0) {
            this->head = NULL;
            this->tail = NULL;
        }
    }
};