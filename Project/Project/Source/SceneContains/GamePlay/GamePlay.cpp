#include "GamePlay.h"

#include <gslib.h>
#include<GSmusic.h>

#include <chrono>

#include "../SceneName.h"
#include "../../WorldContains/World/World.h"
#include"../../ActorContains/ActorGroup.h"
#include"../../CharacterContains/PlayerContains/Player/Player.h"
#include "../../Utility/InputState/InputState.h"
#include "../../Base/GameManagerContains/GameManager/GameManager.h"
#include "../../Define/Def_Nagano.h"
#include "../../Define/Def_Nakayama.h"
#include "../../Utility/Rederer2D/Renderer2D.h"
#include "../../Utility/Score/Score.h"
#include"../../MapGenerator/MapGenerator.h"
#include "../../Utility/FourDirection/FourDirection.h"
#include"../../CharacterContains/Factory/CharacterFactory.h"
#include"../../Utility/Sound/SoundName.h"
#include "../../StagingContains/TransitionStaging/Transition/Transition.h"


// �R���X�g���N�^    
GamePlay::GamePlay(const IGameManagerPtr& gameManager)
	:Scene(gameManager) {
	gameManager->GetRenderer2D()->LoadTexture("game_back", "Resource/Texture/UI/Play/back_ground.png");
	isGameClear = false;
}

// �J�n     
void GamePlay::OnStart() {
	//�}�b�v�f�[�^�ɂ�鐶��
	p_World->SetMapGenerator(p_World, p_GameManager);
	p_World->SetCharacterFactory(new CharacterFactory(p_World,p_GameManager));
	MapOrder += 1;
	MapOrder = p_GameManager->get_MapOrder();
	p_World->generate(p_World, p_GameManager, "Resource/StreamingAssets/stage"+std::to_string(MapOrder)+".csv");

	std::unordered_map<FourDirection, TileData> tmp = p_World->GetMap()->GetAroundTile(GSvector2(70, 90));

	p_GameManager->GetPlayerParameter().setRemaining(3);

	gsBindMusic(BGM_GAME_PLAY);

	PauseFlag = false;
}

// �X�V     
void GamePlay::OnUpdate(float deltaTime) {
	gsPlayMusic(BGM_GAME_PLAY);

	//�|�[�Y
	if (p_GameManager->GetInputState()->IsPadStateTrigger(GS_XBOX_PAD_START) == GS_TRUE) 
	{
		gsPlaySE(SE_PAUSE_OPEN);
		PauseFlag = !PauseFlag;
	}
	if (PauseFlag == true)
	{
		if (p_GameManager->GetInputState()->IsPadStateTrigger(GS_XBOX_PAD_B) &&
			CarsorMovement == 0) {
			gsPlaySE(SE_DECITION);
			PauseFlag = false;
		}

		if (p_GameManager->GetInputState()->IsPadStateTrigger(GS_XBOX_PAD_B) &&
			CarsorMovement == 1)
		{
			gsPlaySE(SE_DECITION);
			MapOrder = 0;
			p_World->EndRequest(SceneName::GameTitle);
			return;
		}
		//�J�[�\���ړ�
		if (p_GameManager->GetInputState()->IsPadStateTrigger(GS_XBOX_PAD_DOWN) ||
			p_GameManager->GetInputState()->IsPadStateTrigger(GS_XBOX_PAD_UP)) {
			if (CarsorMovement == 0)
			{
				CarsorMovement = 1;
			}
			else
			{
				CarsorMovement = 0;
			}
		}
	}
	
	// �����\�ȓG���O�ȉ��̏ꍇ�N���A
	if (p_World->GetSurviverSum(MapOrder) <= 0 || p_GameManager->GetInputState()->IsPadStateTrigger(GS_XBOX_PAD_X)) {
		isGameClear = true;
		p_World->EndRequest(SceneName::GameResult);
	}
	
}

void GamePlay::OnDraw() const {
	p_GameManager->GetRenderer2D()->DrawTexture("game_back", GSvector2(0, 0));

	/*
	std::chrono::system_clock::time_point  start, end; // �^�� auto �ŉ�
	start = std::chrono::system_clock::now(); // �v���J�n����
	//*/
	p_World->GetMap()->draw();
	/*
	end = std::chrono::system_clock::now();  // �v���I������
	double elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count(); //�����ɗv�������Ԃ��~���b�ɕϊ�
	std::cout << "GamePlay" << ":Draw:" << elapsed << std::endl;
	//*/
	//�|�[�Y���
	if (PauseFlag == true)
	{
		p_GameManager->GetRenderer2D()->DrawTexture("Pause", GSvector2(0, 0));
		p_GameManager->GetRenderer2D()->DrawTexture("PauseRG", GSvector2(SCREEN_SIZE.x / 2 - 128, SCREEN_SIZE.y / 2 - 128));
		p_GameManager->GetRenderer2D()->DrawTexture("PauseRT", GSvector2(SCREEN_SIZE.x / 2 - 128, SCREEN_SIZE.y / 2 + 128));
		//�J�[�\���`��
		if (CarsorMovement == 0)
		{
			p_GameManager->GetRenderer2D()->DrawTexture("Cursor", GSvector2(SCREEN_SIZE.x / 2 - 178, SCREEN_SIZE.y / 2 - 100));
		}
		else
		{
			p_GameManager->GetRenderer2D()->DrawTexture("Cursor", GSvector2(SCREEN_SIZE.x / 2 - 178, SCREEN_SIZE.y / 2 + 100));
		}
	}

	// UI�`��
	p_GameManager->GetPlayerParameter().DrawRemaining(p_GameManager->GetRenderer2D());
	p_GameManager->GetPlayerParameter().DrawCombo(p_GameManager->GetRenderer2D());
	p_GameManager->GetScore()->draw();
	p_GameManager->GetScore()->setPosition(GSvector2(200, 50));
	gsFontParameter(GS_FONT_BOLD, 50, "HG����B");
	gsTextPos(900, 50);
	gsDrawText("���� %d ��", p_World->GetSurviverSum(MapOrder));
	gsFontParameter(GS_FONT_BOLD, 20, "HG����B");
}

void GamePlay::End()
{
	gsStopMusic(BGM_GAME_PLAY);

	if (MapOrder >= 1) {
		p_GameManager->set_MapOrder(MapOrder);
	}
	else
	{
		MapOrder = 0;
	}
}
