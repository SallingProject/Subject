#pragma once

class SceneBase {
public:
	virtual void initraize() = 0;
	virtual void render() = 0;
};

class SceneTitle : public SceneBase {

};