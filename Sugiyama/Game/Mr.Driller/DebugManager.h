#pragma once



class DebugManager
{
private:
	DebugManager();
	bool errorEndFlag;

public:
	~DebugManager();

	enum  class RenderErrorType
	{
		FailedInit = 0,
		SucsseceLord = 1,

	};

	static DebugManager* Instance();

	void RenderError(RenderErrorType);

	bool GetEndFlag();


};

