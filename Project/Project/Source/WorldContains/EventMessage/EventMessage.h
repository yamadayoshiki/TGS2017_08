#pragma once

enum class EventMessage {
	SELECT,
	END_SCENE,

	PLAYER_ROUNDS,		//����
	PLAYER_CRUSH,		//�ׂ�
	PLAYER_RELEASE,		//����
	PLAYER_ROUNDSLOST,	//����ł������̂��Ȃ��Ȃ�

	ENEMY02_DEAD,		//�G�l�~�[02������
	ENEMY_REPEL,		//�e��
};