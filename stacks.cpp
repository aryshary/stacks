#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    int n1{ 0 }, n2{ 0 }, n3{ 0 };
    string line;
    cin >> line;
    stack <char> stack;
    for (int i = 0; i < line.length(); i++) {
        if (line[i] == ';') break;
        else {
            if (line[i] == '(' || line[i] == ')' || line[i] == '[' || line[i] == ']' || line[i] == '{' || line[i] == '}') {
                stack.push(line[i]);
            }
        }
    }
    for (int i = 0; i < stack.size(); i++) {
        if (stack.top() == ')' && n1 == 0) {
            stack.pop();
            n1++;
        }
        else if (stack.top() == ']' && n2 == 0) {
            stack.pop();
            n2++;
        }
        else if (stack.top() == '}' && n3 == 0) {
            stack.pop();
            n3++;
        }
        else if (stack.top() == '(' && n1 == 1) {
            stack.pop();
            n1 = 0;
        }
        else if (stack.top() == '[' && n2 == 1) {
            stack.pop();
            n2 = 0;
        }
        else if (stack.top() == '{' && n3 == 1) {
            stack.pop();
            n3 = 0;
        }
        else cout << "incorrect - " << stack.top();
    }
    if (n1 == 0 && n2 == 0 && n3 == 0) cout << "correct";
}
