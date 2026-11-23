#include <cstdio>

const int MAX_SIZE = 10;

struct VectorQueue {
    char data[MAX_SIZE];
    int front;
    int rear;
    int count;
};

void initQueue(VectorQueue &q) {
    q.front = 0;
    q.rear = -1;
    q.count = 0;
}

bool enqueue(VectorQueue &q, char val) {
    if (q.count == MAX_SIZE) {
        printf("Помилка: черга переповнена! Неможливо додати '%c'\n", val);
        return false;
    }
    q.rear = (q.rear + 1) % MAX_SIZE;
    q.data[q.rear] = val;
    q.count++;
    return true;
}

bool dequeue(VectorQueue &q, char &val) {
    if (q.count == 0) {
        printf("Помилка: черга порожня! Нічого видаляти.\n");
        return false;
    }
    val = q.data[q.front];
    q.front = (q.front + 1) % MAX_SIZE;
    q.count--;
    return true;
}

int main() {
    VectorQueue q;
    initQueue(q);

    char source[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    int N = 7;
    printf("--- Додавання %d елементів ---\n", N);
    for (int i = 0; i < N; i++) {
        if (enqueue(q, source[i])) {
            printf("Додано: %c\n", source[i]);
        }
    }

    int M = 9;
    printf("\n--- Видалення %d елементів ---\n", M);
    for (int i = 0; i < M; i++) {
        char removed;
        if (dequeue(q, removed)) {
            printf("Видалено: %c\n", removed);
        } else {
            break;
        }
    }

    return 0;
}
