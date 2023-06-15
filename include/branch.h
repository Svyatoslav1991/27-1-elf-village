#include <iostream>
#include <string>
#include <vector>


class Branch
{
public:
	Branch(Branch* parent);
	~Branch();

	void setElfsName(std::string name);
	std::string getElfsName() const;
	Branch* getParent() const;
	const std::vector<Branch*>& getChildren() const;
	void addChield(Branch* child);

private:
	Branch* m_pParent;
	std::string m_elf;
	std::vector<Branch*> m_vChildren;
};
