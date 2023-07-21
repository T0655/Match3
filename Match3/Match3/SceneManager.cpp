#include"SceneManager.h"
#include "TitleScene.h"
#include"GameMainScene.h"
#include"GameClearScene.h"
#include"GameOverScene.h"

/*************************
* マクロ定義
*************************/

/*************************
* 型定義
*************************/

/*************************
* 変数宣言
*************************/
GAME_MODE Game_Mode; //ゲームモード情報(現在)
GAME_MODE Next_Mode; //ゲームモード情報(次)

/*************************
* プロトタイプ宣言
*************************/

/*******************************************
* シーン管理機能：初期化処理
* 引数：なし
* 戻り値：なし
********************************************/
int SceneManager_Initialize(GAME_MODE mode)
{
	int Read_Error;

	//シーン読み込み処理
	//タイトル画面
	Read_Error = TitleScene_Initialize();
	if (Read_Error == D_ERROR)
	{
		return D_ERROR;
	}

	//ゲームクリア画面
	Read_Error = GameMainScene_Initialize();
	if (Read_Error == D_ERROR)
	{
		return D_ERROR;
	}
	//ゲームクリア画面
	Read_Error = GameClearScene_Initialize();
	if (Read_Error == D_ERROR)
	{
		return D_ERROR;
	}
	//ゲームオーバー画面
	Read_Error = GameOverScene_Initialize();
	if (Read_Error == D_ERROR)
	{
		return D_ERROR;
	}
	Game_Mode = mode;
	Next_Mode = Game_Mode;

	return Read_Error;
}
/*******************************************
* シーン管理機能：更新処理
* 引数：なし
* 戻り値：なし
********************************************/
void SceneManager_Update(void)
{
	//前フレームとゲームモードが違っていたらシーンを切り替える
	if (Game_Mode != Next_Mode)
	{
		SceneManager_Initialize(Next_Mode);
	}
	

	//各画面の更新処理
	switch (Game_Mode)
	{
	  case E_TITLE:
			TitleScene_Update();
			break;
	  case E_GAMEMAIN:
		  GameMainScene_Update();
		  break;
	  case E_GAME_CLEAR:
		  GameClearScene_Update();
		  break;
	  case E_GAME_OVER:
		  GameOverScene_Update();
		  break;
	  default:
		  break;
	}
}
/*******************************************
* シーン管理機能：描画処理
* 引数：なし
* 戻り値：なし
********************************************/
void SceneManager_Draw(void)
{
	//各画面の更新処理
	switch (Game_Mode)
	{
	case E_TITLE:
		TitleScene_Draw();
		break;
	case E_GAMEMAIN:
		GameMainScene_Draw();
		break;
	case E_GAME_CLEAR:
		GameClearScene_Draw();
		break;
	case E_GAME_OVER:
		GameOverScene_Draw();
		break;
	default:
		break;
	}
}
/*******************************************
* シーン管理機能：シーン切替処理
* 引数：変更するゲームモード
* 戻り値：なし
********************************************/
void Change_Scene(GAME_MODE mode)
{
	Next_Mode = mode;
}