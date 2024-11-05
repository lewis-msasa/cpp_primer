#include <iostream>

/*
blueprint for generating classes
*/
template <typename T, typename U> 
class Pair{
   public:
    T first;
    U second;

    Pair(T first, U second): first(first), second(second){}

    void display() const {
        std::cout << "First: " << first << ", Second: "<< second << std::endl;
    }
};

template <typename T> class Blob {
    public:
        typedef T value_type;
        typedef typename std::vector<T>::size_type size_type;
        //constructors
        Blob();
        Blob(std::initializer_list<T> il);
        // number of elements
        size_type size() const { return data->push_back(t);}
        bool empty() const { return data->empty();}
        //add and remove elements
        void push_back(const T &t) { data->push_back(t);}

        void push_back(T &&t) { data->push_back(std::move(t));}
        void pop_back();
        // element access
        T& back();
        T& operator[](size_type i);
    private:
        std::shared_ptr<std::vector<T>> data;
        void check(size_type i, const std::string &msg) const;
};

template <typename T>
void Blob<T>::check(size_type i, const std::string &msg) const{
    if( i >= data->size())
       throw std::out_of_range(msg)
}
template <typename T>
T& Blob<T>::back(){
    check(0, "empty blob");
    return data->back();
}
template <typename T>
T& Blob<T>::operator[](size_type i){
    check(i, "subscript out of rage");
    return (*data)[i];
}
template <typename T> void Blob<T>::pop_back(){
    check(0,"pop_back on empty Blob");
    data->pop_back();
}

int main(){
    Pair<int,double> pair(10,15.5);
    pair.display();

    return 0;
}