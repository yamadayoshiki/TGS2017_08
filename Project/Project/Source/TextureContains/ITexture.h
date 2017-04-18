#ifndef ITEXTURE_H_
#define ITEXTURE_H_

class ITexture
{
public:
	//仮想デストラクタ
	virtual ~ITexture() {
		Finalize();
	}
	//初期化
	virtual void Initialize() = 0;
	//更新
	virtual void Update(float deltaTime) = 0;
	//描画
	virtual void Draw() = 0;
	//終了
	virtual void Finalize() = 0;
};

#endif // !ITEXTURE_H_
