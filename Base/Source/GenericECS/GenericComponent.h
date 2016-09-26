#ifndef GENERIC_COMPONENT_H
#define GENERIC_COMPONENT_H

#include <string>
#include "GenericEntity.h"
#include "../Systems/ComponentSystem.h"
#include <assert.h>

class GenericEntity;

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
private:
    static size_t GenerateID() {
        static size_t zeID = 0;
        assert(zeID < MAX_NUM_COMPONENTS);
        return zeID++;
    }

public:
    static const size_t MAX_NUM_COMPONENTS = 32;

    GenericComponent() { GenericComponent("", nullptr); }
    GenericComponent(const std::string &zeName, GenericEntity *zeOwner) {
        setName(zeName); 
        owner_of_component = zeOwner;
        id_ = GenerateID();
    }
    virtual ~GenericComponent() { owner_of_component = nullptr; }

    void setName(const std::string zeName) { name_ = zeName; }
    void setEntityOwner(GenericEntity *zeOwner) { owner_of_component = zeOwner; }

    virtual bool onNotify(const std::string &zeEvent) { return false; };
    virtual bool onNotify(const int &zeEvent) { return false; };
    virtual bool onNotify(const float &zeEvent) { return false; };
    virtual bool onNotify(const double &zeEvent) { return false; };
    virtual bool onNotify(const GenericComponent &zeEvent) { return false; };

    std::string getName() { return name_; }
    size_t getID() { return id_; }

protected:
    std::string name_;
    GenericEntity *owner_of_component;
    size_t id_;
};

#endif