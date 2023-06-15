#include "..\include\branch.h"


Branch::Branch(Branch* parent) : m_pParent(parent), m_elf("")
{

}

//---------------------------------------------------------------------------------------

Branch::~Branch()
{
	for (Branch* child : m_vChildren)
	{
		delete child;
	}

	m_vChildren.clear();
}

//---------------------------------------------------------------------------------------

void Branch::setElfsName(std::string name)
{
	m_elf = name;
}

//---------------------------------------------------------------------------------------

std::string Branch::getElfsName() const
{
	return m_elf;
}

//---------------------------------------------------------------------------------------

Branch* Branch::getParent() const
{
	return m_pParent;
}

//---------------------------------------------------------------------------------------

const std::vector<Branch*>& Branch::getChildren() const
{
	return m_vChildren;
}

//---------------------------------------------------------------------------------------

void Branch::addChield(Branch* child)
{
	m_vChildren.push_back(child);
}
