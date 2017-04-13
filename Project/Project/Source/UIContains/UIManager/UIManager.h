#ifndef UI_MANAGER_H_ 
#define UI_MANAGER_H_ 

#include "../UI/UI.h" 
#include <unordered_map> 

enum class UIGroup;

// UIマネージャー 
class UIManager {
public:
	// コンストラクタ     
	UIManager();
	// 初期化     
	void initialize();
	// 更新     
	void update(float deltaTime);
	// 描画     
	void draw() const;
	// UIの追加     
	void addUI(UIGroup group, const UIPtr& ui);
	// UIの検索     
	UIPtr findUI(const UIName& name);
	// メッセージ処理     
	void handleMessage(EventMessage message, void* param);
	// コピー禁止     
	UIManager(const UIManager& other) = delete;
	UIManager& operator = (const UIManager& other) = delete;
private:
	// ルートノード     
	UI m_root;
	// UIグループ     
	std::unordered_map<UIGroup, UIPtr> m_UIs;
};

#endif