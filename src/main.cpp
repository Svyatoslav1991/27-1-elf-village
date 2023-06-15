#include <iostream>
#include <ctime>

#include "functions.h"

int main() {
	std::cout << "\tTASK 27.1 ELF VILLAGE\n\n";

	srand(time(NULL));

	std::vector<Branch*> vTrees;

	for (int64_t i = 0; i < N; i++)
	{
		Branch* pTree = new Branch(nullptr);
		vTrees.push_back(pTree);

		int64_t bigBranches = rand() % 3 + 3; //3-5

		for (int64_t j = 0; j < bigBranches; j++)
		{
			Branch* pBigBranch = new Branch(pTree);
			pTree->addChield(pBigBranch);

			int64_t middleBranches = rand() % 2 + 2; //2-3

			for (int64_t k = 0; k < middleBranches; k++)
			{
				Branch* pMiddleBranch = new Branch(pBigBranch);
				pBigBranch->addChield(pMiddleBranch);
			}
		}
	}

	for (auto* tree : vTrees)
	{
		for (auto* bigBranch : tree->getChildren())
		{
			populateElves(bigBranch);
		}
	}

	for (auto* tree : vTrees)
	{
		printTree(tree);
		std::cout << "\n";
	}

	std::cout << "\n";
	std::string name;

	do
	{
		std::cout << "Enter the name of an elf to find his number of neighbors\n";
		name = myCin<decltype(name)>();
	} while (name.empty());


	Branch* pBranch = nullptr;
	for (auto* tree : vTrees)
	{
		pBranch = findElf(tree, name);
		if (pBranch)
		{
			break;
		}
	}

	std::cout << "\n";

	if (pBranch)
	{
		std::cout << "The number of neighbors of the elf " << name << " is " << countElves(pBranch->getParent()) - 1 << "\n";
	}
	else
	{
		std::cout << "An elf named " << name << " does not exist\n";
	}

	for (Branch* tree : vTrees)
	{
		delete tree;
	}
	vTrees.clear();
	

	return 0;
}