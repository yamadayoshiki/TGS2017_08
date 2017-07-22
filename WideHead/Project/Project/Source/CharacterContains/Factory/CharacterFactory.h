#ifndef CHARACTERFACTORY_H_
#define CHARACTERFACTORY_H_

#include <map>
#include "../../ActorContains/ActorPtr.h"
#include "../../WorldContains/IWorldPtr.h"
#include "../../Base/GameManagerContains/IGameManagerPtr.h"

enum class ActorName;
struct GSvector2;

//�L�����N�^�[�H��
class CharacterFactory
{
private:
	struct ActorData {
		ActorWPtr parent;	// ��������A�N�^�[�̐e
		ActorUPtr child;	// ��������A�N�^�[���g
	};

public:
	//�R���X�g���N�^
	CharacterFactory(
		const IWorldPtr& world,
		const IGameManagerPtr& gameManager);
	//�f�X�g���N�^
	~CharacterFactory();

	//����
	void Generate(const int x, const int y, const int csvData);
	//����
	void Generate(const GSvector2 position, const int csvData);
	//��������Character���擾
	ActorPtr GetGenerateCharacter(const GSvector2 position, const int csvData);

private:
	std::map<ActorName, ActorWPtr> m_ParentMap;	//�e
	std::map<int, ActorData> m_GenerateMap;		//�����L�����p�}�b�v

	IWorldWPtr p_IWorld;						//���[���h
	IGameManagerWPtr p_IGameManager;			//�Q�[���}�l�[�W���[
};

#endif