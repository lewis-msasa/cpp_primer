#include <iostream>

template <typename T>
class Box; //forward declaration of Box

template <typename T>
class BoxHelper {
    public:
        void display(const Box<T>& b);
};

template <typename T>
class Box {
    friend class BoxHelper<T>;
    public: 
        Box(T val) : value(val){}
    private:
        T value;
};

/*
ONE TO ONE FRIENDSHIP - class template to another class template

in the example, Container holds type T and ContainerHelper template class needs access to private members of Container<T>
each Container<T> will only grant friendship to corresponding ContainerHelper<T> e.g. Container<int> will allow access to ContainerHelper<int> 
but not to ContainerHelper<double>
*/

template <typename T>
class Container; //forward declaration of Container<T>

template<typename T>
class ContainerHelper{
    public:
        void display(const Container<T>& c);
};

template <typename T>
class Container{
    friend class ContainerHelper<T>;

    public: 
        Container(T val) : value(val){}
    private:
        T value;
};

template <typename T>
void ContainerHelper<T>::display(const Container<T>& c){
    std::cout << "Container value: " << c.value << std::endl;
}





/*
BEFRIENDING THE TEMPLATE'S OWN TYPE PARAMETER
Useful when you want instances of the template to allow access to another class which is a specific instantiation of the type parameter
*/

//example 1
template <typename T>
class Wrapper {
    friend T;

    public: 
        Wrapper(int val) : data(val) {}
    private:
        int data;
};
class MyClass{
    public:
        void showWrapperData(const Wrapper<MyClass>& w){
            std::cout << "wrapper data" << w.data << std::endl;
        }
};
//example 2
class Error;
class Info;
class Warning;

template <typename Severity>
class LogMessage {
    friend class Severity;

    public:
        LogMessage(const std::string& msg): message(msg){}
    private:
        std::string message;
};

class Info {
    public:
        void display(const LogMessage<Info>& msg){
            std::cout << "[INFO]: " << msg.message << std::endl;
        }
};
class Warning{
    public:
        void display(const LogMessage<Warning>& msg){
             std::cout << "[WARNING]: " << msg.message << std::endl;
        }
};
class Error {
    public:
        void display(const LogMessage<Error>& msg){
             std::cout << "[ERROR]: " << msg.message << std::endl;
        }
};







int main() {

    Container<int> intContainer(42);
    ContainerHelper<int> intHelper;

    intHelper.display(intContainer);

    //the following would cause an error
    /*ContainerHelper<double> doubleHelper;
    doubleHelper.display(intContainer);*/

    //the logging example
    LogMessage<Info> infoLog("We are cruising");
    LogMessage<Warning> warningLog("We might have an issue");
    LogMessage<Error> errorLog("Total failure");

    Info info;
    Warning warning;
    Error error;

    info.display(infoLog);
    warning.display(warningLog);
    error.display(errorLog);

    return 0;
}