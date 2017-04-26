#pragma once

#include "../../../WorldContains/IWorld.h"
#include "../../../ActorContains/Actor/Actor.h"

#include "../../UIType.h"
#include "../../../FileReader/CsvReaderPtr.h"

#include <unordered_map>
#include <string>

class UIManager : public Actor {
public:
	struct SpriteData {
		std::string file_name;
		GSvector2 position;
		float alpha;
		float angle;
		std::unordered_map<std::string, std::string> customize;
	};


public:
	UIManager(const IWorldPtr& world, const IGameManagerPtr& gameManager);
protected:
	void addFile(const UIType& type, const CsvReaderPtr& csv_reader);
	virtual void registButton(const std::string& file_name);
	virtual void registSprite(const std::string& file_name);
	virtual void registText(const std::string& file_name);
	virtual void create();

private:
	std::vector<SpriteData> m_SpriteDatas;
};
