#include <iostream>
#include <stack>
using namespace std;

void calculateSpan(int A[], int n, int S[]) {
    stack<int> st; // Stack to store indices of previous prices
    S[0] = 1; // First day's span is always 1
    st.push(0); // Push first index

    for (int i = 1; i < n; i++) {
        // Pop elements from stack while stack is not empty and price at stack top is <= current price
        while (!st.empty() && A[st.top()] <= A[i]) {
            st.pop();
        }

        // If stack is empty, it means current price is greater than all previous prices
        S[i] = (st.empty()) ? (i + 1) : (i - st.top());

        // Push this element index to stack
        st.push(i);
    }
}

int main() {
    int A[] = {100, 80, 60, 70, 60, 75, 85};
    int n = sizeof(A) / sizeof(A[0]);
    int S[n]; // Array to store span values

    calculateSpan(A, n, S);

    // Print the result
    cout << "Stock Spans: ";
    for (int i = 0; i < n; i++) {
        cout << S[i] << " ";
    }
    cout << endl;

    return 0;
}
