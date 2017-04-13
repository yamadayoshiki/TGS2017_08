#ifndef UI_MANAGER_H_ 
#define UI_MANAGER_H_ 

#include "../UI/UI.h" 
#include <unordered_map> 

enum class UIGroup;

// UI�}�l�[�W���[ 
class UIManager {
public:
	// �R���X�g���N�^     
	UIManager();
	// ������     
	void initialize();
	// �X�V     
	void update(float deltaTime);
	// �`��     
	void draw() const;
	// UI�̒ǉ�     
	void addUI(UIGroup group, const UIPtr& ui);
	// UI�̌���     
	UIPtr findUI(const UIName& name);
	// ���b�Z�[�W����     
	void handleMessage(EventMessage message, void* param);
	// �R�s�[�֎~     
	UIManager(const UIManager& other) = delete;
	UIManager& operator = (const UIManager& other) = delete;
private:
	// ���[�g�m�[�h     
	UI m_root;
	// UI�O���[�v     
	std::unordered_map<UIGroup, UIPtr> m_UIs;
};

#endif