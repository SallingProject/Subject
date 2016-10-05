#ifndef _SYSTEMMANAGER_H_
#define _SYSTEMMANAGER_H_

#include <unordered_map>
#include <string>
#include <memory>
class IScene;
class SystemManager
{
public:
	SystemManager();
	~SystemManager();

	enum class EState:int32_t
	{
		Error = 0,
		Initialize,
		Update,
		End,
		Change,
	};

	void Initialize(IScene*);
	void SceneInitalize();
	void SceneUpdate();
	void SceneChanger(std::string);
	void AddScene(IScene*);


	void IsEnd(bool);
	bool IsEnd()const;

private:
	bool FindScene(std::string);
private:
	EState m_state;
	IScene* m_pScene;
	std::unordered_map<std::string, IScene*> m_sceneMap;
	bool m_isEnd;

};

#endif