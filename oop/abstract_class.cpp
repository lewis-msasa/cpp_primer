#include <cmath>

class Shape {
  virtual double area() const = 0;
};

class Circle : public Shape {
    double radius;
    public:
        Circle(double r) : radius(r) {}
        double area() const override {
            return M_PI * radius * radius;
        }
};
