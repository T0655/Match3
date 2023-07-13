#pragma once

/*************
* マクロ定義
*************/

/**************
* 型定義
****************/

/********************
* プロトタイプ宣言
********************/

int StageInitialize(void);
void CreateBlock(void);
void SelectBlock(void);
void StageDraw(void);
void FadeOutBlock(void);
void MoveBlock(void);
void CheckBlock(void);
void CheckClear(void);

int Get_StageState(void);
int Get_StageClearFlag(void);
int Get_StageScore(void);

void Set_StageMission(int mission);
