#include "builder.h"

class MacBuilder :public IBuilder {
public:
	MacBuilder() { m_Computer = new Computer(); }
	void BuildCPU() { m_Computer->SetCPU("i5 8600K"); }
	void BuildRam() { m_Computer->SetRam("DDR4 32G"); }
	void BuildMainBoard() { m_Computer->SetMainBoard("Z"); }
	void BuildVideoCard() { m_Computer->SetVideoCard("RTX2080"); }
	Computer *GetResult() { return m_Computer; }
private:
	Computer* m_Computer;
};


class ASUSBuilder :public IBuilder {
public:
	ASUSBuilder() { m_Computer = new Computer(); }
	void BuildCPU() { m_Computer->SetCPU("i3 8100"); }
	void BuildRam() { m_Computer->SetRam("DDR4 8G"); }
	void BuildMainBoard() { m_Computer->SetMainBoard("M"); }
	void BuildVideoCard() { m_Computer->SetVideoCard("GTX940"); }
	Computer *GetResult() { return m_Computer; }
private:
	Computer* m_Computer;
};