# 27-1-elf-village

Wood elves located their village in the forest, right on the trees.
It is necessary to settle the elves along the tree branches, and then calculate the total number of neighbors of a certain elf.
There are five trees in the forest, each of which is generated using random numbers given in the following ranges.
Each tree has 3-5 main large branches.
On each large branch there are 2-3 more medium branches.
Elf houses are built on large and medium branches.
Smaller branches are not considered in this problem.
At the beginning of the program, the user places one elf in each house.
This is done using a sequential enumeration of all available houses and a request for the name of the occupied elf through the standard input.
If None was entered as the name, then the house is skipped and not occupied by anyone.
After that, you need to find a specific elf by name.
The name of the elf you are looking for is entered via standard input.
For the found elf, you need to print the total number of elves living with him on one large branch.
This will be the desired number of neighbors.

Tips & Tricks

You should use the same class (for example, Branch) to represent trees and to represent large and medium branches, with a field to represent the parent branch and a field to represent the child branches.
The tree itself, in turn, will always have a parent branch that is null, that is, nullptr.
The function of searching for an elf in a tree can be implemented using a recursive method in the Branch class, which will first look for an elf in itself, and then on child branches.
