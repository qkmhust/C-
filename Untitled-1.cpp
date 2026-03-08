#include <iostream>
#include <thread>
#include <atomic>
#include <vector>
#include <optional>
#include <chrono>

// 简单的SPSC环形缓冲区
template<typename T, size_t Size>
class SPSCQueue {
public:
    SPSCQueue() : head_(0), tail_(0) {}

    bool push(const T& item) {
        size_t next_head = (head_ + 1) % Size;
        if (next_head == tail_.load(std::memory_order_acquire)) {
            return false; // 队列满
        }
        buffer_[head_] = item;
        head_ = next_head;
        return true;
    }

    std::optional<T> pop() {
        if (tail_.load(std::memory_order_acquire) == head_) {
            return std::nullopt; // 队列空
        }
        T item = buffer_[tail_];
        tail_ = (tail_ + 1) % Size;
        return item;
    }

private:
    T buffer_[Size];
    size_t head_;
    std::atomic<size_t> tail_;
};

int main() {
    SPSCQueue<int, 1024> queue;
    constexpr int N = 10000;

    std::thread producer([&]() {
        for (int i = 0; i < N; ++i) {
            while (!queue.push(i)) {
                std::this_thread::yield();
            }
        }
    });

    std::thread consumer([&]() {
        int count = 0;
        while (count < N) {
            auto item = queue.pop();
            if (item) {
                // std::cout << "Consumed: " << *item << std::endl;
                ++count;
            } else {
                std::this_thread::yield();
            }
        }
    });

    producer.join();
    consumer.join();
    std::cout << "Done." << std::endl;
    return 0;
}