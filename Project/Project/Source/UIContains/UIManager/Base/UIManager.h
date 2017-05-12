#pragma once

#include "../../../WorldContains/IWorld.h"
#include "../../../ActorContains/Actor/Actor.h"

#include "../../UIType.h"
#include "../../../FileReader/CsvReaderPtr.h"

#include <unordered_map>
#include <string>

enum class SceneName;

class UIManager : public Actor {
public:
	UIManager(IWorld* world, const IGameManagerPtr& gameManager, const SceneName& scene);
protected:
	void registActor();

	// ƒV[ƒ“‚É‘Î‰‚µ‚½UI‚Ì¶¬
	void create(const SceneName& scene_name);

	void addFile(const UIType& type, const CsvReaderPtr& csv_reader);
	virtual void registButton(const std::string& file_name);
	virtual void registSprite(const std::string& file_name);
	virtual void registText(const std::string& file_name);

private:
	// UI“o˜^—p‚Ìmap
	std::unordered_map<SceneName, ActorPtr>m_UIManagers;

};
