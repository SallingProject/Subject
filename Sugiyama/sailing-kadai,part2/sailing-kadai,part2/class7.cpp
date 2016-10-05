#include<iostream>
using namespace std;

class SCENE_BASE {

public:
	virtual void Update() = 0;
	virtual int DrawScreen() = 0;
	virtual int InitGame() = 0;
};