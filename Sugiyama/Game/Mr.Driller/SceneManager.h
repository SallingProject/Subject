#pragma once

#include "ISceneChanger.h"
#include "IScene.h"

class SceneManager : public ISceneChanger, IScene {

private:
	IScene* mScene;
	eScene mNextScene;
public:
	SceneManager();
	~SceneManager();
	void Init() override;//������
	void Final() override;//�I������
	void Update() override;//�X�V
	void Render() override;//�`��

	 // ���� nextScene �ɃV�[����ύX����
	void ChangeScene(eScene NextScene) override;


};

