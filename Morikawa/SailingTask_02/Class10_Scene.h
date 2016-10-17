#ifndef _SCENE_H_
#define _SCENE_H_

/************************************
 �S�ẴV�[���̌p�����ƂȂ钊�ۃN���X
 ************************************/

class Scene {

public:
	virtual void Initialize() = 0; // ����������
	virtual void Input() = 0;      // ���͏���
	virtual void Output() = 0;     // �o�͏���
};

#endif // _SCENE_H_