#pragma once

/**************
* マクロ定義
***************/
#define D_ERROR  (-1)
#define D_NORMALITY (0)

/***********************
* 型定義
***********************/

enum GAME_MODE
{
	E_TITLE,
	E_GAMEMAIN,
	E_GAME_CLEAR,
	E_GAME_OVER,
	E_END,
	E_MODE_MAX
};
/********************
* プロトタイプ宣言
********************/
int SceneManager_Initialize(GAME_MODE mode);  //初期化処理
void SceneManager_Update(void);                //更新処理
void SceneManager_Draw(void);                 //描画処理

void Change_Scene(GAME_MODE mode);            //シーン変更処理