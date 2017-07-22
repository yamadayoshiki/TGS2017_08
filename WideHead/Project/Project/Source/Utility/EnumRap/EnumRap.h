#pragma once

#include <unordered_map>

// ��
template <typename T>
class EnumRap {
public:
	// �R���X�g���N�^
	EnumRap() {}

	// �o�^
	void AddEnum(const std::string& key, T value) {
		m_Enums[key] = value;
	}
	// �Ή������񋓌^�̎擾
	T GetEnum(const std::string& key) {
		return m_Enums[key];
	}
private:
	// �z��i�[
	std::unordered_map<std::string, T> m_Enums;
};

