#include <iostream>
/*
GENERAL AND SPECIFIC TEMPLATE FRIENDSHIP
- General template friendship - a class template can declare all instantiations of another template as its friend
- Specific template friendship - allows a class template to make only a particular instatiation of another template a friend
*/
template <typename T> class Pal;

class C {
    //only Pal<C> is a friend of C
    friend class Pal<C>;
    //all instances of Pal2 are friends of C
    template <typename T> friend class Pal2;

    public:
        void display() const {
            std::cout << "Class C instance" << std::endl;
        }

};

template <typename T>
class C2 {
    //each instance of C2 has the corresponding instance of Pal as a friend
    friend class Pal<T>;
    //all instances of Pal2 are friend of each instance of C2
    template <typename X> friend class Pal2;
    public:
        void display() const {
            std::count << "Class C2 instance of type: "<<typeid(T).name() << std::endl;
        }
};

template <typename T>
class Pal {
    public:
        void accessC(const C& c){
            std::cout << "Accessing C from Pal<C>" << std::endl;
            c.display();
        }
        void accessC2(const C2<T>& c2){
            std::cout << "Accessing C2 from Pal" << std::endl;
            c2.display();
        }
};
template <typename T>
class Pal2 {
    public:
        void accessC2(const C2<T>& c2){
            std::cout << "Accessing C2 from Pal2" << std::endl;
            c.display();
        }
};

int main(){
    C c_instance;
    Pal<C> pal_instance;
    pal_instance.accessC(c_instance); //access C from Pal<C>

    C2<int> c2_instance;
    Pal<int> pal_int_instance;
    pal_int_instance.accessC2(c2_instance);

    Pal2<int> pal2_instance;
    pal2_instance.accessC2(c2_instance);


    return 0;
}
