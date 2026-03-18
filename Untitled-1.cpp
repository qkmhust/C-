#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <functional>
#include <ranges>  // C++20 Ranges
#include <format>  // C++20 Format

class StringIntHashTable {
private:
    // 专门针对 string 和 int 的键值对
    struct KeyValuePair {
        std::string key;
        int value;
    };

    std::size_t bucket_count;
    std::vector<std::list<KeyValuePair>> buckets;

public:
    // 构造函数
    explicit StringIntHashTable(std::size_t size = 5) 
        : bucket_count(size), buckets(size) {}

    // 插入函数：参数类型明确为 const std::string& 和 int
    void insert(const std::string& key, int value) {
        // 1. 计算 string 的哈希值
        std::size_t hash_val = std::hash<std::string>{}(key);
        
        // 2. 映射到桶的索引
        std::size_t index = hash_val % bucket_count;

        // 3. 遍历对应的桶，处理哈希冲突（键若存在则更新值）
        auto& bucket = buckets[index];
        for (auto& pair : bucket) {
            if (pair.key == key) {
                pair.value = value;
                return;
            }
        }

        // 4. 键不存在，使用 C++20 指定初始化器插入新节点
        bucket.emplace_back(KeyValuePair{.key = key, .value = value});
    }

    // 打印哈希表内存布局
    void print_table() const {
        std::cout << "\n--- 哈希表布局 ---\n";
        for (std::size_t i = 0; i < buckets.size(); ++i) {
            std::cout << std::format("桶 [{}] : ", i);
            if (buckets[i].empty()) {
                std::cout << "空\n";
                continue;
            }
            for (const auto& pair : buckets[i]) {
                std::cout << std::format("[{}: {}] -> ", pair.key, pair.value);
            }
            std::cout << "nullptr\n";
        }
    }

    // C++20 Ranges 查询：找出值大于指定阈值的键
    void print_keys_above_threshold(int threshold) const {
        std::cout << std::format("\n--- 查找值大于 {} 的键 ---\n", threshold);

        auto query_view = buckets 
            | std::views::join
            | std::views::filter([threshold](const KeyValuePair& pair) { 
                return pair.value > threshold; 
            })
            | std::views::transform([](const KeyValuePair& pair) { 
                return pair.key; 
            });

        for (const std::string& key : query_view) {
            std::cout << std::format("找到键: {}\n", key);
        }
    }
};

int main() {
    StringIntHashTable map(5);

    map.insert("Apple", 10);
    map.insert("Banana", 45);
    map.insert("Orange", 30);
    map.insert("Grape", 60);
    map.insert("Melon", 50);

    map.print_table();
    map.print_keys_above_threshold(40);

    return 0;
}