#include <iostream>
using namespace std;

struct Stack {
    int top;
    int size;
    int* arr;
};

void PUSH(Stack& s, int x) {
    s.top = s.top + 1;
    if (s.top > s.size) {
        cout << "Stack overflow\n";
        s.top = s.top - 1;
    }
    else {
        s.arr[s.top] = x;
    }
}

int POP(Stack& s) {
    if (s.top < 0) {
        cout << "Stack underflow\n";
        return -1;
    }
    else {
        int popped = s.arr[s.top];
        s.top = s.top - 1;
        return popped;
    }
}

int main() {
    Stack s;
    cout << "Enter the size of the stack: ";
    cin >> s.size;
    s.top = -1;
    s.arr = new int[s.size];

    PUSH(s, 1);
    PUSH(s, 2);
    PUSH(s, 3);
    cout << POP(s) << endl; // outputs 3
    cout << POP(s) << endl; // outputs 2
    cout << POP(s) << endl; // outputs 1
    cout << POP(s) << endl; // outputs "Stack underflow"
    return 0;
}
