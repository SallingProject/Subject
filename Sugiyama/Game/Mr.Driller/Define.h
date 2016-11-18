#ifndef _DEFINE_H_
#define _DEFINE_H_

// パス定義
#define TITLE_PIC  "Image/Title.jpg"
#define GAME_PIC   "Image/Game.png"
#define MENU_PIC   "Image/Menu.png"
#define CONFIG_PIC "Image/Config.png"
#define TITLE_LOGO_PIC "Image/TitleLogo.jpg"
#define TITLE_NAMUCO_PIC "Image/TitleNamuco.png"

#define PLAYER_PIC "Image/sample.png"
#define BLOCK_LIST "Image/BlockList.png"
#define OBJECT_LIST "Image/ObjectList.png"

#define TITLE_SOUND  "Sound/Mr_Driller_Soundtracks_Title_Screen.mp3"
#define MENU_SOUND   "Sound/Mr_Driller_Soundtracks-Nuts!_Menu_Screen.mp3"
#define RESULT_SOUND "Sound/Mr_Driller_Result_Scene.mp3"
#define GAME_SOUND   "Sound/game.mp3"
// 定数定義

// MapObj
#define MAP_HORIZONTAL_NUM 11
#define MAP_VERTICAL_NUM 42
#define OBJECT_TYPE_NUM 4
#define OBJECT_SIZE 60
#define BLANK_TYPE 0
#define BLOCK_TYPE 1
#define OBJECT_TYPE 2
#define BLOCKLIST_NUM 12
#define OBJECTLIST_NUM 8
#define OBJECT_DRAWSIZE_256 0.234375 
#define OBJECT_DRAWSIZE 0.46875
#define START_CAMERA OBJECT_SIZE * 20
#define CAMERA_SPEED 8
#define START_BLOCK 26
#define CHAR_SPEED 4
#define CHAR_START_X 620
#define CHAR_START_Y OBJECT_SIZE * 6 - OBJECT_SIZE / 2

//titlelogo
#define MAX_DX_BLENDMODE 255
#define MIN_DX_BLENDMODE 0
#define DX_BLENDMODE_ACTIVE 1
#define DX_BLENDMODE_NOACTIVE 0
#define DRAW_DRAPH_POINT_X 200
#define DRAW_DRAPH_POINT_Y 300

#endif // !_DEFINE_H_