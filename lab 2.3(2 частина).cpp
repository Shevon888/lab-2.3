#include <cstdio>

struct Node {
    int data;
    Node* prev;
    Node* next;
};

struct DoublyLinkedList {
    Node* head;
    Node* tail;
};

void initList(DoublyLinkedList &list) {
    list.head = nullptr;
    list.tail = nullptr;
}

void pushBack(DoublyLinkedList &list, int val) {
    Node* newNode = new Node{val, list.tail, nullptr};
    if (list.tail != nullptr) {
        list.tail->next = newNode;
    } else {
        list.head = newNode;
    }
    list.tail = newNode;
}

bool popFront(DoublyLinkedList &list, int &val) {
    if (list.head == nullptr) {
        printf("Список порожній!\n");
        return false;
    }
    Node* temp = list.head;
    val = temp->data;
    list.head = list.head->next;
    if (list.head != nullptr) {
        list.head->prev = nullptr;
    } else {
        list.tail = nullptr;
    }
    delete temp;
    return true;
}

int main() {
    DoublyLinkedList list;
    initList(list);

    int source[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int N = 6;
    for (int i = 0; i < N; i++) {
        pushBack(list, source[i]);
        printf("Додано в список: %d\n", source[i]);
    }

    int M = 8;
    printf("\nВидалення елементів:\n");
    for (int i = 0; i < M; i++) {
        int val;
        if (popFront(list, val)) {
            printf("Видалено: %d\n", val);
        } else {
            break;
        }
    }

    return 0;
}
