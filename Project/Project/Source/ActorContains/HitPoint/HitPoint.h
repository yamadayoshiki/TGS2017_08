#ifndef HITPOINT_H_
#define HITPOINT_H_

//�q�b�g�|�C���g
struct HitPoint
{
private:
	int maxHp;	//�ő�HP
	int hp;		//HP

public:
	//�R���X�g���N�^
	explicit HitPoint(int maxHp);
	//HP�����炷
	void Decrease(int damage);
	//HP�𑝂₷
	void Increase(int recover);
	//HP��0�ȉ���
	bool IsDead();
};

#endif // !HITPOINT_H_