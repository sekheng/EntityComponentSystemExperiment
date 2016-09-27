#ifndef MESH_COMPONENT_H
#define MESH_COMPONENT_H

#include "../GenericECS/GenericComponent.h"
#include "../Classes/Mesh.h"

class MeshComponent : public GenericComponent
{
public:
    MeshComponent();
    MeshComponent(Mesh *zeRenderStuff);
    virtual ~MeshComponent();

    void Render();

protected:
    Mesh *theGraphicsStuff_;
};

#endif