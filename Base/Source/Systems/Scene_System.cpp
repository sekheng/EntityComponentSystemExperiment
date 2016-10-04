#include "Scene_System.h"
#ifdef _DEBUG
    #include <assert.h>
#endif

void Scene_System::Init()
{
    //currScene = nullptr;
    graphics_scene = nullptr;
}

void Scene_System::Update(double dt)
{
#ifdef _DEBUG
    assert(dt > 0 || dt < 0 || dt == 0);    //Make there is no joker
#endif
}

void Scene_System::AddScene(SceneEntity &sceneObject)
{
#ifdef _DEBUG
    assert(graphics_scene != nullptr);  //Ensuring the Graphics are being added before the logics
#endif
	if (SceneHistory.empty() == true)
    {
		SceneHistory.push(&sceneObject);
        graphics_scene->modelStack = sceneObject.modelStack;
        graphics_scene->viewStack = sceneObject.viewStack;
        graphics_scene->projectionStack = sceneObject.projectionStack;
    }
    theSceneList.insert(std::pair<std::string, SceneEntity*>(sceneObject.getName(), &sceneObject));
}

void Scene_System::RemoveScene(SceneEntity &sceneObject)
{
    // Don't know what to do with this function
}

void Scene_System::SwitchScene(const std::string &id_)
{
#ifdef _DEBUG
    assert(graphics_scene != nullptr);  //Ensuring the Graphics are being added before the logics
#endif
    std::map<std::string, SceneEntity*>::iterator it = theSceneList.find(id_);
	if (it != theSceneList.end())
	{
		SceneHistory.push(it->second);
		graphics_scene->modelStack = SceneHistory.top()->modelStack;
		graphics_scene->viewStack = SceneHistory.top()->viewStack;
		graphics_scene->projectionStack = SceneHistory.top()->projectionStack;
	}
}

bool Scene_System::SwitchToPreviousScene()
{
	if (SceneHistory.size() > 1)
	{
		SceneHistory.pop();
		graphics_scene->modelStack = SceneHistory.top()->modelStack;
		graphics_scene->viewStack = SceneHistory.top()->viewStack;
		graphics_scene->projectionStack = SceneHistory.top()->projectionStack;
		return true;
	}
	else return false;
}

SceneEntity &Scene_System::getCurrScene()
{
	return *SceneHistory.top();
}

SceneEntity &Scene_System::getGraphicsScene()
{
    return *graphics_scene;
}

void Scene_System::setGraphics_Scene(SceneEntity &sceneObject)
{
#ifdef _DEBUG
    assert(graphics_scene == nullptr);  //Ensuring the Graphics are being added before the logics
#endif
    graphics_scene = &sceneObject;
}

void Scene_System::clearEverything()
{
    for (auto it : theSceneList)
    {
        it.second->Exit();
        delete it.second;
        it.second = nullptr;
    }
    theSceneList.clear();
    graphics_scene->Exit();
    delete graphics_scene;
    graphics_scene = nullptr;
	
	while (!SceneHistory.empty())
	{
		SceneHistory.pop();
	}
}

void Scene_System::Exit()
{
    clearEverything();
}