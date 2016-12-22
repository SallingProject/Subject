#include <iostream>

using namespace std;

/***********************************************************************

Class7.cpp�ō쐬�����ASceneBase���p�����N���X
SceneGame���������Ȃ����B�v���͈ȉ��̂��̂Ƃ���B
�X�V�������s���֐��A�`�揈�����s���֐��A���������s���֐�
���쐬���A�N�Z�X���x���́u���J�v�Ƃ���B
���ꂼ��̃����o�֐����I�[�o�[���C�h����
���C���ɂ͊��N���X�̃I�u�W�F�N�g�����A
�h���N���X�����N���X�ɃA�b�v�L���X�g����
�X�V�����֐���update�A�`�揈����render�A
������initialize�Əo�͂��Ȃ����B
�������֐��͕K��1�x�����Ă΂�Ȃ����̂Ƃ���B
�R���\�[����ʂ̓y�[�W�̓s���㊄���B

***********************************************************************/


class SceneBase {

	/* �A�N�Z�X���x�� ���J */
public:
	virtual void update() = 0;      //�X�V����
	virtual void render() = 0;      //�`�揈��
	virtual void initialize() = 0;  //������

};


class SceneGame :public SceneBase {

public:
	void update()
	{

		/* update�ƕ\�� */

		cout << "update" << endl;

	}

	void render()
	{

		/* render�ƕ\�� */

		cout << "render" << endl;

	}

	void initialize()
	{

		/* initialize�ƕ\�� */

		cout << "initialize" << endl;

	}

};


void main()
{
	/* ���N���X�̃I�u�W�F�N�g */
	SceneBase *pBase = new SceneGame;


	pBase->update();
	pBase->render();
	pBase->initialize();

	return;

}