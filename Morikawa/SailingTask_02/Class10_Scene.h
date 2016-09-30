#ifndef _SCENE_H_
#define _SCENE_H_

/************************************
 �S�ẴV�[���̌p�����ƂȂ钊�ۃN���X
 ************************************/

class Scene {

public:
	virtual void Start() = 0;    // �����̊J�n

	virtual void Initialize() {} // ����������
	virtual void Input() {}      // ���͏���
	virtual void Output() {}     // �o�͏���
};

#endif // _SCENE_H_