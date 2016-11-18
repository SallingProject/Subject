#include "DebugManager.h"
#include "DXlib.h"


DebugManager::DebugManager()
{
	errorEndFlag = true;
}


DebugManager::~DebugManager()
{
}

void DebugManager::RenderError(RenderErrorType errorCode){

	switch (errorCode){

	case RenderErrorType::FailedInit:
		MessageBox(NULL, "ERROR CODE:-1", "ERROR", MB_OK);
		errorEndFlag = false;
		break;

	case RenderErrorType::SucsseceLord:
		MessageBox(NULL, "SUCSSECE ROAD", "SUCSSECE", MB_OK);
		break;
	}

	
}

DebugManager* DebugManager::Instance() {

	static DebugManager point;
	return &point;
}

bool DebugManager::GetEndFlag() {

	return errorEndFlag;
}

