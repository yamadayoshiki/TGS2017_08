#ifndef HITPOINT_H_
#define HITPOINT_H_

//ヒットポイント
struct HitPoint
{
private:
	int maxHp;		//最大HP
	int hp;			//HP
	bool canDead;	//死ぬことができるか

public:
	//コンストラクタ
	explicit HitPoint(int maxHp);
	//HPを減らす
	void Decrease(int damage);
	//HPを増やす
	void Increase(int recover);
	//HPが0以下か
	bool IsDead();
	//倒せるか倒せないか
	bool CanDead() const;
	//最大HPの取得
	int GetMaxHp() const;
};

#endif // !HITPOINT_H_