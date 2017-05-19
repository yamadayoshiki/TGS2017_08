#ifndef HITPOINT_H_
#define HITPOINT_H_

//ヒットポイント
struct HitPoint
{
private:
	int maxHp;	//最大HP
	int hp;		//HP

public:
	//コンストラクタ
	explicit HitPoint(int maxHp);
	//HPを減らす
	void Decrease(int damage);
	//HPを増やす
	void Increase(int recover);
	//HPが0以下か
	bool IsDead();
};

#endif // !HITPOINT_H_