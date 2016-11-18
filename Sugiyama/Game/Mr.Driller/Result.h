#pragma once
#include "SceneTask.h"
class Result : public SceneTask{
public:
	Result(ISceneChanger* changer);
	~Result();
	virtual void Update()override;
	virtual void Render()override;
	
private:
	virtual void Init() override;
	virtual void Final() override;
};

