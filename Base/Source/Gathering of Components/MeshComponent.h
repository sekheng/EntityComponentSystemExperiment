#ifndef MESH_COMPONENT_H
#define MESH_COMPONENT_H

#include "../GenericECS/GenericComponent.h"

class MeshComponent : public GenericComponent
{
public:
    MeshComponent();
    virtual ~MeshComponent();

private:
    static MeshComponent *toRegisterItselfToComponentSystem;
};

#endif