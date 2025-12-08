#include <bits/stdc++.h>
using namespace std;

class MyCircularQueue {
    vector<int> q;
    int frontIdx, rearIdx, capacity, size;
public:
    MyCircularQueue(int k) {
        capacity = k;
        q.assign(k, 0);
        frontIdx = 0;
        rearIdx = -1;
        size = 0;
    }

    bool enQueue(int value) {
        if (isFull()) return false;
        rearIdx = (rearIdx + 1) % capacity;
        q[rearIdx] = value;
        size++;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;
        frontIdx = (frontIdx + 1) % capacity;
        size--;
        if (size == 0) { // reset pointers for clarity
            frontIdx = 0;
            rearIdx = -1;
        }
        return true;
    }

    int Front() {
        return isEmpty() ? -1 : q[frontIdx];
    }

    int Rear() {
        return isEmpty() ? -1 : q[rearIdx];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }
};

int main() {
    MyCircularQueue q(3);
    cout << q.enQueue(1) << "\n"; // true -> 1
    cout << q.enQueue(2) << "\n"; // 1
    cout << q.enQueue(3) << "\n"; // 1
    cout << q.enQueue(4) << "\n"; // false -> 0 (full)
    cout << "Rear: " << q.Rear() << "\n"; // 3
    cout << "Front: " << q.Front() << "\n"; // 1
    q.deQueue();
    cout << q.enQueue(4) << "\n"; // true -> 1
    cout << "Rear after enqueue: " << q.Rear() << "\n"; // 4
    return 0;
}
