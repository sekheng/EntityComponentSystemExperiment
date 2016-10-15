#ifndef SCENE_TEXT1_H
#define SCENE_TEXT1_H

#include "../Classes/SceneEntity.h"

class SceneTest1 : public SceneEntity
{
public:
    virtual ~SceneTest1();

    virtual void Init();
    virtual void Update(float dt);
    virtual void Render();
    virtual void Exit();

private:
    SceneTest1();
    static SceneTest1 zeTest1;
};

#endif