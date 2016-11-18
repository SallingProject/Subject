#include "Menu.h"
#include "DxLib.h"
#include "Define.h"

Menu::Menu(ISceneChanger* changer):SceneTask(changer){
}


Menu::~Menu()
{
}
void Menu::Init() {
	mGraphicHandle = LoadGraph(MENU_PIC);    //�摜�̃��[�h
	mSoundPlayHandle = LoadSoundMem(MENU_SOUND);
}

//�X�V
void Menu::Update() {
	if (CheckHitKey(KEY_INPUT_G) != 0) {//G�L�[��������Ă�����
		mChangeScene->ChangeScene(eScene_Game);//�V�[�����Q�[����ʂɕύX
	}
	if (CheckHitKey(KEY_INPUT_C) != 0) {//C�L�[��������Ă�����
		mChangeScene->ChangeScene(eScene_Config);//�V�[����ݒ��ʂɕύX
	}
	if (CheckHitKey(KEY_INPUT_A) != 0) {
		mChangeScene->ChangeScene(eScene_Title);
	}
}

//�`��
void Menu::Render() {
	SceneTask::Render();//�e�N���X�̕`�惁�\�b�h���Ă�
	DrawString(0, 0, "���j���[��ʂł��B", GetColor(255, 255, 255));
	DrawString(0, 20, "G�L�[�������ƃQ�[����ʂɐi�݂܂��B", GetColor(255, 255, 255));
	DrawString(0, 40, "C�L�[�������Ɓ@�ݒ��ʂɐi�݂܂��B", GetColor(255, 255, 255));
	DrawString(0, 60, "A�L�[�������Ɓ@�^�C�g���ɐi�݂܂��B", GetColor(255, 255, 255));
}

void Menu::Final() {
	SceneTask::Final();
}