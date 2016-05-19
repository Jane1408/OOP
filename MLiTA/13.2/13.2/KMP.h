#pragma once

class CKMP
{
public:
	CKMP();
	void AlgorithmKMP(std::string const& input);
	void WriteIntoOutputFile();
	std::vector<std::pair<size_t, size_t>> GetResults();
private:
	std::vector<int> GetSearchPrefixFunctions();
	std::vector<size_t> Find(std::string const& text);

	size_t m_lineNumber;
	std::string m_needle;
	std::vector<size_t> m_positions;
	std::vector<int> m_prefixFunction;
	std::vector<std::pair<size_t, size_t>> m_result;

};

