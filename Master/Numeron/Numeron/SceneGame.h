#ifndef _SCENEGAME_H_
#define _SCENEGAME_H_
#include "IScene.h"
#include <string>
#include <vector>
class SceneGame :
	public IScene
{
public:
	SceneGame(SystemManager* manager);
	~SceneGame();

	bool Initalize()override;
	void Update()override;
private:
	std::string CheckInputStrings(std::string);

private:
	std::string m_nextScene;
	std::vector<int> m_answer;
};

#endif