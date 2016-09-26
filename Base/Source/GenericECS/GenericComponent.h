#ifndef GENERIC_COMPONENT_H
#define GENERIC_COMPONENT_H

#include <string>
#include "GenericEntity.h"

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
    GenericComponent(const std::string &zeName) { setName(zeName); owner_of_component = nullptr; }
    virtual ~GenericComponent() { owner_of_component = nullptr; }

    virtual void setName(const std::string zeName) { name_ = zeName; }

    virtual bool onNotify(const std::string &zeEvent) { return false; };
    virtual bool onNotify(const int &zeEvent) { return false; };
    virtual bool onNotify(const float &zeEvent) { return false; };
    virtual bool onNotify(const double &zeEvent) { return false; };
    virtual bool onNotify(const GenericComponent &zeEvent) { return false; };

    std::string getName() { return name_; }

protected:
    std::string name_;
    GenericEntity *owner_of_component;
};

#endif