#include <iostream>
using namespace std;

// Check if we can divide into <= M segments
bool canDivide(int A[], int N, int M, int maxOR) {
    int segments = 1;
    int currentOR = 0;

    for (int i = 0; i < N; i++) {
        if ((currentOR | A[i]) <= maxOR) {
            currentOR |= A[i];
        } else {
            segments++;
            currentOR = A[i];
        }
    }
    return segments <= M;
}

int minimizeMaxOR(int A[], int N, int M) {
    int low = 0, high = 0;

    for (int i = 0; i < N; i++) {
        low = max(low, A[i]);
        high |= A[i];
    }

    int answer = high;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (canDivide(A, N, M, mid)) {
            answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return answer;
}

int main() {
    int A[] = {1, 2, 3, 4};
    int N = 4;
    int M = 2;

    cout << "Minimum possible maximum OR: "
         << minimizeMaxOR(A, N, M);

    return 0;
}
