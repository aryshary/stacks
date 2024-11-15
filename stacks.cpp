#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    string line;
    cin >> line;
    stack<char> stack;
    int position = -1;

    for (int i = 0; i < line.length(); i++) {
        if (line[i] == ';') break;
        else if (line[i] == '(' || line[i] == '[' || line[i] == '{') {
            stack.push(line[i]);
        }
        else if (line[i] == ')' || line[i] == ']' || line[i] == '}') {
            if (stack.empty()) {
                position = i;
                break;
            }
            char top = stack.top();
            if ((line[i] == ')' && top == '(') ||
                (line[i] == ']' && top == '[') ||
                (line[i] == '}' && top == '{')) {
                stack.pop();
            }
            else {
                position = i;
                break;
            }
        }
    }

    if (position != -1) {
        cout << "incorrect at position " << position << " - ";
        for (int i = 0; i <= position; i++) {
            cout << line[i];
        }
    }
    else if (!stack.empty()) {
        position = line.find(stack.top());
        cout << "incorrect at position " << position << " - unmatched brackets";
    }
    else {
        cout << "correct";
    }
}
