#ifndef DRAWORDER_H_
#define DRAWORDER_H_
//描画順序
enum class DrawOrder
{
	/* 奥に描画されるもの */

	BackGround=0,		//背景
	Map,				//地形
	
	Effect_Back,		//奥演出

	/*キャラ*/
	Enemy,
	Player,

	Effect_Front,		//手前演出

	/*UI*/
	UI,
	UI_Front1,
	UI_Front2,
	UI_Front3,

	/*ポーズメニュー*/
	PauseBack,
	PauseUI,

	BlackScreen,
	/* 手前に描画されるもの */
};
#endif // !DRAWORDER_H_
