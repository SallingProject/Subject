#ifndef _SCENETITLE_H_
#define _SCENETITLE_H_
#include "IScene.h"
class SceneTitle :
	public IScene
{
public:
	SceneTitle(SystemManager* manager);
	~SceneTitle();
	bool Initalize()override;
	void Update()override;
private:
	std::string m_nextScene;
};

#endif