#include "MeshComponent.h"
#include "../Systems/ComponentSystem.h"

MeshComponent::MeshComponent()
{
    MeshComponent(nullptr);
}

MeshComponent::MeshComponent(Mesh *zeRenderStuff)
{
    theGraphicsStuff_ = zeRenderStuff;
}

MeshComponent::~MeshComponent()
{

}


void MeshComponent::Render()
{
    theGraphicsStuff_->Render();
}