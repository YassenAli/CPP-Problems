// Purpose: create a template stack class with methods of stack.
// Author: Yassin Ali Mamdouh
// Date: 24 Dec 2023

#include <bits/stdc++.h>

using namespace std;

class StackOverflowException : public runtime_error {
public:
    StackOverflowException();
};

StackOverflowException::StackOverflowException() : runtime_error("Stack overflow") {}

class StackEmptyException : public runtime_error {
public:
    StackEmptyException();
};

StackEmptyException::StackEmptyException() : runtime_error("Stack empty") {}

template<typename T>
class Stack {
private:
    T *arr;
    int topIndex;
    int maxSize;

public:
    // Constructor with fixed size
    Stack(int size);

    // Copy constructor
    Stack(const Stack &other);

    ~Stack(); // Destructor

    // Assignment operator
    Stack &operator=(const Stack &other);

    void push(const T &data);

    T pop();

    T top();

    int size();

    bool empty();
};

template<typename T>
Stack<T>::Stack(int size) : arr(new T[size]), topIndex(-1), maxSize(size) {}

template<typename T>
Stack<T>::Stack(const Stack &other) : arr(new T[other.maxSize]), topIndex(other.topIndex), maxSize(other.maxSize) {
    for (int i = 0; i <= topIndex; i++) {
        arr[i] = other.arr[i];
    }
}

template<typename T>
Stack<T>::~Stack() {
    delete[] arr;
}

template<typename T>
Stack<T> &Stack<T>::operator=(const Stack &other) {
    if (this != &other) {
        delete[] arr;
        arr = new T[other.maxSize];
        maxSize = other.maxSize;
        topIndex = other.topIndex;
        for (int i = 0; i <= topIndex; i++) {
            arr[i] = other.arr[i];
        }
    }
    return *this;
}

template<typename T>
void Stack<T>::push(const T &data) {
    if (topIndex == maxSize - 1) {
        throw StackOverflowException();
    }
    arr[++topIndex] = data;
}

template<typename T>
T Stack<T>::pop() {
    if (topIndex == -1) {
        throw StackEmptyException();
    }
    return arr[topIndex--];
}

template<typename T>
T Stack<T>::top() {
    if (topIndex == -1) {
        throw StackEmptyException();
    }
    return arr[topIndex];
}

template<typename T>
int Stack<T>::size() {
    return topIndex + 1;
}

template<typename T>
bool Stack<T>::empty() {
    return topIndex == -1;
}

void manageStack() {
    int size;
    cout << "Enter stack size: ";
    cin >> size;

    Stack<int> stack(size); // Create a stack of integers

    while (true) {
        int choice;
        cout << "\nMenu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Check top element\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        try {
            switch (choice) {
                case 1: {
                    int data;
                    cout << "Enter data to push: ";
                    cin >> data;
                    stack.push(data);
                    cout << data << " pushed onto stack.\n";
                    break;
                }
                case 2: {
                    int data = stack.pop();
                    cout << data << " popped from stack.\n";
                    break;
                }
                case 3: {
                    int top = stack.top();
                    cout << "Top element: " << top << "\n";
                    break;
                }
                case 4:
                    return;
                default:
                    cout << "Invalid choice!\n";
            }
        } catch (const StackOverflowException &e) {
            cout << "Over Flow Occurred\nError: " << e.what() << "\n";
        } catch (const StackEmptyException &e) {
            cout << "Stack is Empty\nError: " << e.what() << "\n";
        }
    }
}

int main() {

    manageStack();

    return 0;
}