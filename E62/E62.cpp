#include <iostream>
#include <stack>

void smash(std::stack<int>& Stack, int value) {
    while (!Stack.empty() && value >= Stack.top()) {
        Stack.pop();
    }
    Stack.push(value);
}

int main() {
    std::stack<int> Stack;
    smash(Stack, 5);
    smash(Stack, 10);
    smash(Stack, 3);
    smash(Stack, 8);
    while (!Stack.empty()) {
        std::cout << Stack.top() << " ";
        Stack.pop();
    }
    return 0;
}