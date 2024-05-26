#include <iostream>
#include <vector>
#include <stdexcept>

template <typename T>
class Queue {
private:
    std::vector<T> elements;

public:
    // Конструктор по умолчанию
    Queue() = default;

    // Добавление элемента в очередь
    void enqueue(const T& item) {
        elements.push_back(item);
    }

    // Удаление элемента из очереди
    void dequeue() {
        if (empty()) {
            throw std::out_of_range("Queue is empty");
        }
        elements.erase(elements.begin());
    }

    // Получение первого элемента в очереди
    T& front() {
        if (empty()) {
            throw std::out_of_range("Queue is empty");
        }
        return elements.front();
    }

    // Проверка, пуста ли очередь
    bool empty() const {
        return elements.empty();
    }

    // Получение размера очереди
    size_t size() const {
        return elements.size();
    }
};

int main() {
    Queue<int> myQueue;

    // Добавляем элементы в очередь
    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);

    // Выводим размер очереди
    std::cout << "Queue size: " << myQueue.size() << std::endl;

    // Удаляем элемент из очереди
    myQueue.dequeue();

    // Выводим первый элемент в очереди
    std::cout << "Front element: " << myQueue.front() << std::endl;

    return 0;
}