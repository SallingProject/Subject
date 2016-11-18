#pragma once
#include "Define.h"
class TitleLogo{
private:
	int mTitleLogoGraphicHandle;
	int mTitleNamucoGraphicHandle;
	int mIndex = MIN_DX_BLENDMODE;
	int mBlendModeFlag = DX_BLENDMODE_NOACTIVE;
	void DrawTitleLogo();
	void DrawTitleNamucoLogo();
	void DrawTitleInit();
	void DrawTitleFinal();
	
public:
	TitleLogo();
	~TitleLogo();
	void Update();
};

