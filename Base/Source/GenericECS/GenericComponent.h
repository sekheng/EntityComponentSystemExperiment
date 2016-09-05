#ifndef GENERIC_COMPONENT_H
#define GENERIC_COMPONENT_H

#include <string>

template<class Type>
struct Data {
    Data() {}
    virtual ~Data() {}

    Type theDataType;

    Type operator+(const Type &rhs) {
        return (theDataType + rhs);
    }
    Type operator-(const Type &rhs) {
        return (theDataType - rhs);
    }
    
};

class GenericComponent
{
public:
    GenericComponent() { setName(""); }
    GenericComponent(const std::string &zeName) { setName(zeName); }
    virtual ~GenericComponent() {}

    virtual void setName(const std::string zeName) { name_ = zeName; }

    std::string getName() { return name_; }

protected:
    std::string name_;
};

#endif