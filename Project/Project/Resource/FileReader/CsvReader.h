#pragma once

#include <vector>
#include <string>

// CSV���[�_�[�N���X
class CsvReader {
public:
	// �R���X�g���N�^
	CsvReader();
	// �R���X�g���N�^
	CsvReader(const std::string& fileName);
	// �t�@�C���̓ǂݍ���
	void load(const std::string& fileName);
	// �f�[�^�̎擾
	const std::string& get(int row, int column) const;
	// �f�[�^�̎擾
	int geti(int row, int column) const;
	// �f�[�^�̎擾
	float getf(int row, int column) const;
	// �s����Ԃ�
	int rows() const;
	// �񐔂�Ԃ�
	int columns(int row = 0) const;

private:
	using Row = std::vector<std::string>;
	using Rows = std::vector<Row>;
	Rows m_Rows;
};


