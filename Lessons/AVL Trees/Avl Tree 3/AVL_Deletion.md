# Deletion :O

First 3 rules of Deletion are the same as insertion:

1. Start by doing a normal BST deletion
2. Then begin updating balance factors of nodes along the path from deletion point to the root
3. As soon as you find the first node out of balance, mark that node as one of your three "restructuring nodes"
4. Then, take a step down the TALLER subtree
5. Then again, take a step down the TALLER SUBTREE
    - That was 2 steps, mark both of those nodes as well
6. Label those "A B C" nodes appropriately
7. Restructure those three nodes
8. After restructuring, recursively check BFs up to root

Choosing A B C nodes:
- Remember: The nodes A,B, and C are always on the tallest path to the bottom of the tree
- So that would give us two of the three nodes we need
- From there we have a choice for the thirs node of A,B,C

1. If one side is longer than the other, choose that side
2. If the two sides are equal, you cannot just choose the taller side
    - So follow this rule: Go to the same side as the parent is to the grandparent
