#ifndef _SYSTEM_MANAGER_H_
#define _SYSTEM_MANAGER_H_
#include "TitleLogo.h"


class SystemManager{
private:
	int systemEndFlag;	//�v���O�������I�������邩�𔻕ʂ���ϐ�
	TitleLogo* titleLogo;
	bool endFlag = false;	//���[�v���甲���邩�ǂ����𔻒f����ϐ�
	void GameIsInit();	
	void GameEnd();
	bool IsGameEnd();
	
	void GetWindowMode(int, int);
public:
	SystemManager();	
	~SystemManager();	
	int Update();
};


#endif // !_SYSTEM_MANAGER_H_