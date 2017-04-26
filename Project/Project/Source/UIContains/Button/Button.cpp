#include "Button.h"

#include "../../FileReader/CsvReader.h"
#include "../../Base/GameManagerContains/GameManager/GameManager.h"
#include "../../Utility/Rederer2D/Renderer2D.h"

Button::Button(const IWorldPtr & world, const ActorName & name, const GSvector2 & position, const IGameManagerPtr & gameManager, const std::string & file_name) :
	UI_Base(world, name, position, gameManager) {
	regist(file_name);
}

void Button::regist(const std::string & file_name){
	CsvReader csv = CsvReader(file_name);

	// çsÇÃÉãÅ[Év
	for (int row = 1; row < csv.rows(); row++) {
		ButtonData data;

		data.file_name = "Resource/Texture/UI/" + csv.get(row, 0);
		data.number = csv.geti(row, 1);
		data.up = csv.geti(row, 2);
		data.down = csv.geti(row, 3);
		data.left = csv.geti(row, 4);
		data.right = csv.geti(row, 5);
		data.anim = csv.geti(row, 6);
		data.param.SetRect(GSrect(0.0f, 0.0f, csv.getf(row, 7), csv.getf(row, 8)));
		data.param.SetPosition(GSvector2(csv.getf(row, 9), csv.getf(row, 10)));
		data.param.SetCenter(GSvector2(0.0f, 0.0f));
		data.param.SetScale(GSvector2(1.0f, 1.0f));
		data.param.SetRotate(csv.getf(row, 11));
		data.param.SetColor(GScolor(1.0f, 1.0f, 1.0f, csv.getf(row, 12)));

		m_Buttons.push_back(data);

		p_GameManager->GetRenderer2D()->LoadTexture(data.file_name, data.file_name);
	}
}

void Button::onUpdate(float deltaTime){
}

void Button::onDraw() const
{
	for (auto button : m_Buttons) {
		p_GameManager->GetRenderer2D()->DrawTexture(button.file_name, button.param);
	}
}
