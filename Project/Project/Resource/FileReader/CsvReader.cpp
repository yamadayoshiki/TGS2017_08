#include "CsvReader.h"
#include <fstream>
#include <sstream>
#include <stdexcept>

// コンストラクタ
CsvReader::CsvReader() {
}

// コンストラクタ
CsvReader::CsvReader(const std::string& fileName) {
	load(fileName);	
}

// ファイルの読み込み
void CsvReader::load(const std::string& fileName) {
	std::ifstream file(fileName);
	if (!file) throw std::runtime_error("CSVファイルがオープンできませんでした");
	m_Rows.clear();
	std::string line;
	while (std::getline(file, line)) {
		std::stringstream ss(line);
		std::string value;
		Row row;
		while (std::getline(ss, value, ',')) {
			row.push_back(value);
		}
		m_Rows.push_back(row);
	}
}

// データの取得
const std::string& CsvReader::get(int row, int column) const {
	return m_Rows[row][column];
}

// データの取得
int CsvReader::geti(int row, int column) const {
	return std::stoi(get(row, column));
}

// データの取得
float CsvReader::getf(int row, int column) const {
	return std::stof(get(row, column));
}

// 行数を返す
int CsvReader::rows() const {
	return (int)m_Rows.size();
}

// 列数を返す
int CsvReader::columns(int row) const {
	return (int)m_Rows[row].size();
}
