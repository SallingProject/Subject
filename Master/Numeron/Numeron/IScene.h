#ifndef _ISCENE_H_
#define _ISCENE_H_
#include <string>
#include <iostream>
#include "SystemManager.h"

class IScene
{
public:
	IScene(std::string name,SystemManager* manager) {
		m_name = name;
		m_manager = manager;
	}
	~IScene() = default;

	virtual bool Initalize() = 0;
	virtual void Update() = 0;
	std::string GetName()const {
		return m_name;
	}

	SystemManager* GetManager() const{
		return m_manager;
	}
private:
	std::string m_name;
	SystemManager* m_manager;
};

#endif