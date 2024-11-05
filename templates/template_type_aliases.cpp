#include <iostream>


/*
provide a new way to create a new name for template type
*/

template <typename T>
using Vector = std::vector<T>;

template <typename T>
class Storage{
    public:
        void add(const T& item){
            items.push_back(item)
        }
        void display() const {
            for (const auto& item : items){
                std::cout << item << std::endl;
            }
        }
    private:
        Vector<T> items;
};

int main() {

    Storage<int> intStorage;
    intStorage.add(1);
    intStorage.add(2);
    intStorage.add(3);

    std::cout << "Item storage:" << std::endl;
    intStorage.display();

    return 0;
}

