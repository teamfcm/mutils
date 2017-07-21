#include "serializer/Serializable.hpp"

class A : public mutils::Serializable<A, mutils::out::DefaultOutput>
{

public:
    A() : Serializable(std::make_pair("Header", &A::_type), std::make_pair("x", &A::x), std::make_pair("y", &A::y)), x(5), y(10) {}

public:
    int         x;
    int         y;

    std::string       _type = "Class A";
};

int                     main()
{
    A                   obj;
    A                   obj1;
    std::stringstream   ss;

    obj.x = 15;
    obj.y = 20;
    ss << obj << std::endl;
    ss >> obj1;
    std::cout << obj1 << std::endl;
    return 0;
}