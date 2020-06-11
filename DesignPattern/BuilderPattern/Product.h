#pragma once
#include "../Common/head.h"

class Computer {
public:
	void SetCPU(string cpu) { m_strCPU = cpu; }
	void SetRam(string ram) { m_strRam = ram; }
	void SetMainBoard(string mainBoard) { m_strMainBoard = mainBoard; }
	void SetVideoCard(string videoCard) { m_strVideoCard = videoCard; }

	string GetCPU() { return m_strCPU; }
	string GetRam() { return m_strRam; }
	string GetMainBoard() { return m_strMainBoard; }
	string GetVideoCard() { return m_strVideoCard; }

private:
	string m_strCPU;
	string m_strRam;
	string m_strMainBoard;
	string m_strVideoCard;
};