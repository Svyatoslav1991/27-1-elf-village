#include "..\include\functions.h"

//Populate the elves by branches
void populateElves(Branch* branch) noexcept
{
	std::string name;

	static int i = 0;


	if (rand() % 5 != 0)
	{
		name = "Elf_" + std::to_string(rand() % 1000);
		branch->setElfsName(name);
	}
	

	for (Branch* child : branch->getChildren())
	{
		populateElves(child);
	}
}

//---------------------------------------------------------------------------------------

//Find the branch on which our elf sits
Branch* findElf(Branch* branch, std::string name) noexcept
{
	if (branch->getElfsName() == name)
	{
		return branch;
	}

	for (Branch* child : branch->getChildren())
	{
		Branch* result = findElf(child, name);
		if (result != nullptr)
		{
			return result;
		}
	}

	return nullptr;
}

//---------------------------------------------------------------------------------------

//Calculate the number of elves on a branch
int64_t countElves(Branch* branch) noexcept
{
	int64_t count = (branch->getElfsName() != "") ? 1 : 0;

	for(Branch* child : branch->getChildren())
	{
		count += countElves(child);
	}

	return count;
}

//---------------------------------------------------------------------------------------

//show the inhabitants of the tree on the screen
void printTree(const Branch* branch, int64_t indent) noexcept
{
	if (branch->getElfsName().empty())
	{
		std::cout << std::string(indent, ' ') << "NONE\n";
	}
	else
	{
		std::cout << std::string(indent, ' ') << branch->getElfsName() << "\n";
	}

	for (Branch* child : branch->getChildren())
	{
		printTree(child, indent + 2);
	}
}