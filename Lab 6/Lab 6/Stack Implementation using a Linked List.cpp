#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct Stack {
    Node* head;
    Node* top;
};

void PUSH(Stack& s, int n) {
    Node* new_node = new Node;
    new_node->data = n;
    new_node->next = NULL;
    if (s.head == NULL) {
        s.head = new_node;
        s.top = new_node;
    }
    else {
        s.top->next = new_node;
        s.top = new_node;
    }
}

int POP(Stack& s) {
    if (s.head == NULL) {
        cout << "Stack underflow\n";
        return -1;
    }
    else {
        int x = s.top->data;
        if (s.top == s.head) {
            s.top = NULL;
            s.head = NULL;
        }
        else {
            Node* tmp = s.head;
            while (tmp->next != s.top) {
                tmp = tmp->next;
            }
            tmp->next = NULL;
            s.top = tmp;
        }
        return x;
    }
}

int main() {
    Stack s;
    s.head = NULL;
    s.top = NULL;

    PUSH(s, 1);
    PUSH(s, 2);
    PUSH(s, 3);
    cout << POP(s) << endl; // outputs 3
    cout << POP(s) << endl; // outputs 2
    cout << POP(s) << endl; // outputs 1
    cout << POP(s) << endl; // outputs "Stack underflow"
    return 0;
}
