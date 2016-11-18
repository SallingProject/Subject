#include "TitleLogo.h"
#include "Dxlib.h"


void TitleLogo::DrawTitleInit() {

	mTitleLogoGraphicHandle = LoadGraph(TITLE_LOGO_PIC);
	mTitleNamucoGraphicHandle = LoadGraph(TITLE_NAMUCO_PIC);
}

void TitleLogo::DrawTitleFinal() {

	DeleteGraph(mTitleLogoGraphicHandle);
	DeleteGraph(mTitleNamucoGraphicHandle);
}

void TitleLogo::Update() {

	this->DrawTitleLogo();
	this->DrawTitleNamucoLogo();
}

void TitleLogo::DrawTitleLogo() {

	while (ProcessMessage() != -1) {

		//裏画面の消去
		ClearDrawScreen();

		if (mBlendModeFlag == DX_BLENDMODE_NOACTIVE) {

			//徐々に不透明に
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, mIndex);
			mIndex += 3;
			if (mIndex >= MAX_DX_BLENDMODE) {
				mIndex = MAX_DX_BLENDMODE;
				mBlendModeFlag = DX_BLENDMODE_ACTIVE;
			}
		}
		//徐々に透明に
		else if ( mBlendModeFlag == DX_BLENDMODE_ACTIVE) {

			SetDrawBlendMode(DX_BLENDMODE_ALPHA, mIndex);
			mIndex -= 3;
			if (mIndex <= MIN_DX_BLENDMODE) {
				//不透明にする
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, MIN_DX_BLENDMODE);
				mBlendModeFlag = DX_BLENDMODE_NOACTIVE;
				mIndex = MIN_DX_BLENDMODE;
				break;
			}
		}

		DrawGraph(DRAW_DRAPH_POINT_X ,DRAW_DRAPH_POINT_Y, mTitleLogoGraphicHandle, TRUE);

		ScreenFlip();
	}
}

void TitleLogo::DrawTitleNamucoLogo() {
	while (ProcessMessage() != -1) {

		//裏画面の消去
		ClearDrawScreen();

		if (mBlendModeFlag == DX_BLENDMODE_NOACTIVE) {

			//徐々に不透明に
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, mIndex);
			mIndex += 3;
			if (mIndex >= MAX_DX_BLENDMODE) {
				mIndex = MAX_DX_BLENDMODE;
				mBlendModeFlag = DX_BLENDMODE_ACTIVE;
			}
		}
		//徐々に透明に
		else if (mBlendModeFlag == DX_BLENDMODE_ACTIVE) {

			SetDrawBlendMode(DX_BLENDMODE_ALPHA, mIndex);
			mIndex -= 3;
			if (mIndex <= MIN_DX_BLENDMODE) {
				//不透明にする
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, MIN_DX_BLENDMODE);
				mBlendModeFlag = DX_BLENDMODE_NOACTIVE;
				mIndex = MIN_DX_BLENDMODE;
				break;
			}
		}

		DrawGraph(DRAW_DRAPH_POINT_X, DRAW_DRAPH_POINT_Y, mTitleNamucoGraphicHandle, TRUE);

		ScreenFlip();
	}
}

TitleLogo::TitleLogo(){
	this->DrawTitleInit();
}


TitleLogo::~TitleLogo(){
	this->DrawTitleFinal();
}
