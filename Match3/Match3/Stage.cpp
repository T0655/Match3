#include "Stage.h"
#include"DxLib.h"
#include"InputControl.h"
/*********************
* マクロ定義
*********************/
#define HEIGHT            (12)   //ブロック配置サイズ(高さ)
#define WIDTH             (12)   //ブロック配置サイズ(幅)
#define BLOCKSIZE        (48)   //ブロッックサイズ
#define BLOCK_IMAGE_MAX   (10)   //ブロックが増数

#define ITEM_MAX          (8)    //アイテム最大数


#define SELECT_CURSOR       (0) 
#define NEXT_CURSOR         (1)  
#define TMP_CURSOR          (2)
/******************
* 型定義
******************/
typedef struct
{
	int flg;
	int x, y;
	int width, height;
	int image;
	int backup;
}T_Object;
typedef struct
{
	int x;
	int y;
}T_CURSOR;


enum
{
	E_NONE,
	E_ONCE,
	E_SECOND
};

/*********************
* 変数宣言
*********************/
T_Object Block[HEIGHT][WIDTH];   //ブロックオブジェクトデータ
T_CURSOR Select[3];                    //セレクトカーソル座標
int Item[ITEM_MAX];
int ClickStatus;
int Stage_State;
int Stage_Mission;
int Stage_Score;
int ClearFlag;

int BlockImage[BLOCK_IMAGE_MAX];   //ブロック画像
int StageImage;                        //背景用画像
int ClickSE;                        //クリックSE
int FadeOutSE;                          //フェードアウトSE
int MoveBlockSE;                   //ブロック移動SE

/***************************
* プロトタイプ宣言
***************************/
int combo_check(int x,int y);
void combo_check(int y,int x,int* cnt,int* col);
void combo_check(int y, int x,int* cnt,int* col);
void save_block(void);
void restore_block(void);

/************************************
* ステージ制御機能：初期化処理
* 引数：なし
*戻り値：エラー情報
************************************/
int StageInitialize(void)
{
	int ret = 0;
	int i;

	//画像読み込み
	LoadDivGraph("images/block.png", BLOCK_IMAGE_MAX, BLOCK_IMAGE_MAX, 1,
  BLOCKSIZE, BLOCKSIZE, BlockImage);
	StageImage = LoadGraph("image/stage.pnt");
	//音源読み込み
	ClickSE = LoadSoundMem("sounds/click_se.mp3");
	FadeOutSE = LoadSoundMem("sounds/fadeout_se.mp3");
	MoveBlockSE = LoadSoundMem("sounds/moveblock_se.mp3");

	//ブロック生成処理
	CreateBlock();

	ClickStatus = E_NONE;
	Stage_State = 0;
	Stage_Score = 0;
	ClearFlag = FALSE;

	for (i = 0; i < 3; i++)
	{
		Select[i].x = 0;
		Select[i].y = 0;
	}
	//エラーチェック
	for (i = 0;i<BLOCK_IMAGE_MAX; i++)



























}