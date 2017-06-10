#ifndef FRONTCHIPLIST_H_
#define FRONTCHIPLIST_H_

#include <vector>
#include "../Map/MapType.h"
#include <GSvector2.h>
#include "../Utility/FourDirection/FourDirection.h"
#include "../Map/MapPtr.h"

//�O���}�X�N���X
class FrontChipList
{
public:
	//�R���X�g���N�^
	FrontChipList(
		const MapPtr& map,
		const GSvector2 pos,
		const FourDirection front,
		const MapType type = MapType::Default);
	//�f�X�g���N�^
	~FrontChipList();
	//�O���}�X�̐ݒ�
	void SetFrontChipList(const GSvector2 pos, const FourDirection front);
	//�󂫃}�X�̗L��
	bool GetSpeaceExist();
	//�ǃ}�X�܂ł̐�
	int GetSpeaceNum();
	//�ǂ̌��������̋󂫃}�X�܂ł̐�
	int GeTheOffSideOfTheWallChipNum();

private:
	MapWPtr p_Map;					//�}�b�v
	std::vector<int> m_List;	//�O���}�XList
	MapType m_Type;				//�}�b�v�^�C�v
};

#endif