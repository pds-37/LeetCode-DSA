#include <bits/stdc++.h>
using namespace std;

class MinStack {
    stack<int> st;
    stack<int> mn;
public:
    MinStack() {}

    void push(int val) {
        st.push(val);
        if (mn.empty() || val <= mn.top()) mn.push(val);
        else mn.push(mn.top());
    }

    void pop() {
        if (!st.empty()) {
            st.pop();
            mn.pop();
        }
    }

    int top() {
        return st.empty() ? -1 : st.top();
    }

    int getMin() {
        return mn.empty() ? INT_MIN : mn.top();
    }
};

int main() {
    MinStack ms;
    ms.push(3);
    ms.push(5);
    ms.push(2);
    ms.push(2);
    cout << "Top: " << ms.top() << "\n";        // 2
    cout << "Min: " << ms.getMin() << "\n";    // 2
    ms.pop();
    cout << "Top after pop: " << ms.top() << "\n"; // 2
    cout << "Min after pop: " << ms.getMin() << "\n"; // 2
    ms.pop();
    cout << "Min now: " << ms.getMin() << "\n"; // 3
    return 0;
}
