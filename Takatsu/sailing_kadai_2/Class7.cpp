#include <iostream>

using namespace std;

/***********************************************************

�N���XSceneBase���������Ȃ����B�v���͈ȉ��̂��̂Ƃ���B
�X�V�������s���֐��A�`�揈�����s���֐��A���������s���֐�
���쐬���A�N�Z�X���x���́u���J�v�Ƃ���B
���ꂼ��̃����o�֐��͏������z�֐��Ƃ���B
�R���\�[����ʂ͕s�v�B

***********************************************************/


class SceneBase {

	/* �A�N�Z�X���x�� ���J */
public:
	virtual void update() = 0;      //�X�V����
	virtual void render() = 0;      //�`�揈��
	virtual void initialize() = 0;  //������

};


void main()
{

	return;

}