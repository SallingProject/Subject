#include <iostream>
#include "SystemManager.h"
#include "SceneTitle.h"
namespace {
	const int kError = -1;
	const int kSuccess = 0;
}
int main(int argv,const char* argc) {

	SystemManager system;
	system.Initialize(new SceneTitle(&system));

	while (!system.IsEnd())
	{
		system.SceneInitalize();
		system.SceneUpdate();
	}

	return kSuccess;
}