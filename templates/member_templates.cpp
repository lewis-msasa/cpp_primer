#include <iostream>
/*
Member Templates of Ordianary (Nontemplate) Classes
*/

class String {
    public:
        template<typename T>
        T toNumber() const {
            return std::stoll(data);
        }
        template<typename T>
        String& append(const T& value){
            data += std::to_string(value);
            return *this;
        }
    private:
        std::string data;
};

/*
Member Templates of Class Templates
*/
template<typename T>
class Container{
    public:
        template<typename U>
        void copy_from(const Container<U>& other){
            data = static_cast<T>(other.get());
        }
        template<typename V>
        void set(const V& value){
            data = static_cast<T>(value);
        }
        T get() const { return data;}
    private:
        T data;
};
//provide for class and method
template<typename T>
template<typename U>
void Container<T>::copy_from(const Container<U>& other){

}





//template constructors
template<typename T>
class SmartPointer{
    public:
        SmartPointer() : ptr(nullptr){}

        explicit SmartPointer(T* p): ptr(p) {}

        template<typename U>
        SmartPointer(const SmartPointer<U>& other): ptr(static_cast<T*>(other.get())){}

        template<typename U>
        SmartPointer& operator=(const SmartPointer<U>& other){
            if (ptr) delete ptr;
            ptr = static_cast<T*>(other.get());
            return *this;
        }

        T* get() const { return ptr;}
        ~SmartPointer() { delete ptr;}

    private:
        T* ptr;
};




int main(){

Container<int> intContainer;
Container<double> doubleContainer;
intContainer.set(3.14);
doubleContainer.copy_from(intContainer);



return 0;
}