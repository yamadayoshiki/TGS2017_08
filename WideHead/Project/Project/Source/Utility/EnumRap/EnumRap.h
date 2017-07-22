#pragma once

#include <unordered_map>

// —ñ‹“
template <typename T>
class EnumRap {
public:
	// ƒRƒ“ƒXƒgƒ‰ƒNƒ^
	EnumRap() {}

	// “o˜^
	void AddEnum(const std::string& key, T value) {
		m_Enums[key] = value;
	}
	// ‘Î‰‚µ‚½—ñ‹“Œ^‚Ìæ“¾
	T GetEnum(const std::string& key) {
		return m_Enums[key];
	}
private:
	// ”z—ñŠi”[
	std::unordered_map<std::string, T> m_Enums;
};

