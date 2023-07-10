#include <iostream>
using namespace std;

struct StackNode {
    char element;
    StackNode* prevNode;
};

class Stack {
public:
    Stack() : firstNode(nullptr) {}

    void push(char element) {
        StackNode* newNode = new StackNode;
        newNode->element = element;
        newNode->prevNode = firstNode;
        firstNode = newNode;
    }

    void pop() {
        if(!isEmpty()){
            StackNode* tmpNode = firstNode;
            firstNode = firstNode->prevNode;
            delete tmpNode;
        }
    }

    char getTop() {
        if(!isEmpty()) return firstNode->element;
        else return ' ';
    }

    bool isEmpty() {
        return firstNode == nullptr;
    }

private:
    StackNode* firstNode;
};

int getPrecedence(char ch) {
    if (ch == '*' || ch == '/') {
        return 2;
    } else if (ch == '+' || ch == '-') {
        return 1;
    } else if (ch == '(' || ch == ')') {
        return 0;
    }
    return -1;
}

int main() {
    Stack stack;
    string inputStr, outputStr = "";
    cin >> inputStr;

    for (char &ch : inputStr) {
        if ('A' <= ch && ch <= 'Z') {
            outputStr += ch;
        } else if (ch == '(') {
            stack.push(ch);
        } else if (ch == ')') {
            while (stack.getTop() != '(') {
                outputStr += stack.getTop();
                stack.pop();
            }
            stack.pop();
        } else {
            while (!stack.isEmpty() && getPrecedence(stack.getTop()) >= getPrecedence(ch)) {
                outputStr += stack.getTop();
                stack.pop();
            }
            stack.push(ch);
        }
    }

    while (!stack.isEmpty()) {
        outputStr += stack.getTop();
        stack.pop();
    }
    cout << outputStr;
    return 0;
}
