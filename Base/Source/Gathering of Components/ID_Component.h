#ifndef ID_COMPONENT_H
#define ID_COMPONENT_H

#include "../GenericECS/GenericComponent.h"

class ID_Component : public GenericComponent
{
public:
    ID_Component() {}
    ID_Component(const size_t &zeID) { zeID_ = zeID; }
    virtual ~ID_Component() {}

    virtual bool onNotify(const int &zeEvent) {
        if (zeEvent >= 0)
        {
            zeID_ = zeEvent;
            return true;
        }
        return false;
    };
    size_t &getValue() { return zeID_; }

protected:
    size_t zeID_;
};

#endif