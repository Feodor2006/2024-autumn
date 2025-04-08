#include <iostream>

// Определение структуры Node
struct Node {
    int data;
    Node* next;

    Node(int data, Node* next = nullptr) : data(data), next(next) {}
    ~Node() {
        data = 0;
        next = nullptr;
    }
};

// Определение класса связного списка
class LinkedList {
private:
    Node* head;

    void Clear() {
        while (!IsEmpty()) {
            ExtractHead();
        }
    }

    void InsertHeadNode(Node* node) {
        node->next = head;
        head = node;
    }

    void InsertTailNode(Node* node) {
        if (IsEmpty()) {
            return InsertHeadNode(node);
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = node;
    }

    void InsertNode(Node* node, int index) {
        if (index == 0) {
            return InsertHeadNode(node);
        }
        Node* temp = head;
        for (int i = 1; i < index && temp != nullptr; ++i) {
            temp = temp->next;
        }
        if (temp != nullptr) {
            node->next = temp->next;
            temp->next = node;
        }
        else {
            delete node;
        }
    }

    Node* ExtractHeadNode() {
        if (IsEmpty()) {
            return nullptr;
        }
        Node* res = head;
        head = head->next;
        return res;
    }

    Node* ExtractTailNode() {
        if (IsEmpty()) {
            return nullptr;
        }
        if (head->next == nullptr) {
            return ExtractHeadNode();
        }
        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        Node* res = temp->next;
        temp->next = nullptr;
        return res;
    }

    Node* ExtractNode(int index) {
        if (index == 0) {
            return ExtractHeadNode();
        }
        Node* temp = head;
        for (int i = 0; i < index - 1 && temp->next != nullptr; ++i) {
            temp = temp->next;
        }
        if (temp->next == nullptr) {
            return nullptr;
        }
        Node* res = temp->next;
        temp->next = temp->next->next;
        res->next = nullptr;
        return res;
    }

public:
    LinkedList() : head(nullptr) {}
    ~LinkedList() { Clear(); }

    bool IsEmpty() {
        return (head == nullptr);
    }

    int length() {
        int res = 0;
        Node* temp = head;
        while (temp != nullptr) {
            ++res;
            temp = temp->next;
        }
        return res;
    }

    void swap(int ind1, int ind2) {
        if (ind2 == ind1) {
            return;
        }
        if (ind2 < ind1) {
            return swap(ind2, ind1);
        }
        Node* node2 = ExtractNode(ind2);
        Node* node1 = ExtractNode(ind1);
        InsertNode(node2, ind1);
        InsertNode(node1, ind2);
    }

    int Get(int index) {
        Node* temp = head;
        for (int i = 0; i < index && temp != nullptr; ++i) {
            temp = temp->next;
        }
        if (temp != nullptr) {
            return temp->data;
        }
        else {
            return -1; // Ошибка, элемент не найден
        }
    }

    void sort() {
        for (int i = 0; i < length(); ++i) {
            for (int j = 0; j < length(); ++j) {
                if (Get(i) > Get(j)) {
                    swap(i, j);
                }
            }
        }
    }

    void Insert(int element, int index) {
        return InsertNode(new Node(element), index);
    }

    void InsertHead(int element) {
        InsertHeadNode(new Node(element));
    }

    void InsertTail(int element) {
        InsertTailNode(new Node(element));
    }

    int Extract(int index) {
        Node* node = ExtractNode(index);
        if (node != nullptr) {
            int value = node->data;
            delete node; // Освобождение памяти
            return value;
        }
        return -1; // Ошибка, элемент не найден
    }

    int ExtractHead() {
        Node* node = ExtractHeadNode();
        if (node != nullptr) {
            int value = node->data;
            delete node; // Освобождение памяти
            return value;
        }
        return -1; // Ошибка, элемент не найден
    }

    int ExtractTail() {
        Node* node = ExtractTailNode();
        if (node != nullptr) {
            int value = node->data;
            delete node; // Освобождение памяти
            return value;
        }
        return -1; // Ошибка, элемент не найден
    }

    void Print() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "nullptr" << std::endl;
    }
};

int main() {
    LinkedList list;

    // Использование методов
    list.InsertHead(10);
    list.InsertTail(20);
    list.InsertHead(30);
    list.InsertTail(40);
    list.Insert(25, 2); // Вставка 25 на 2-й индекс

    std::cout << "Linked List after insertions: ";
    list.Print();

    std::cout << "Extract Head: " << list.ExtractHead() << std::endl;
    std::cout << "Linked List after extracting head: ";
    list.Print();

    std::cout << "Extract Tail: " << list.ExtractTail() << std::endl;
    std::cout << "Linked List after extracting tail: ";
    list.Print();

    std::cout << "Extract from index 1: " << list.Extract(1) << std::endl;
    std::cout << "Linked List after extracting index 1: ";
    list.Print();

    return 0;
}