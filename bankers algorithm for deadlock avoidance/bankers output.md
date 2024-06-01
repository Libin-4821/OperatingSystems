D:\ai&ds\4th sem\os\lab programs\programs\deadlock>gcc safestate_bankers.c -o safestate

D:\ai&ds\4th sem\os\lab programs\programs\deadlock>safestate
                 DEADLOCK - BANKER'S ALGORITHM
ENTER THE NUMBER OF PROCESS:5
ENTER THE NUMBER OF RESOURCE TYPE:3
ENTER THE MAX MATRIX:
7 5 3
3 2 2
9 0 2
2 2 2
4 3 3

ENTER THE ALLOCATED MATRIX:
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2
ENTER THE TOTAL RESOURCES PRESENT:
Resource 1: 10
Resource 2: 5
Resource 3: 7


 AVAILABLE MATRIX

3       3       2

 NEED MATRIX:

7       4       3
1       2       2
6       0       0
0       1       1
4       3       1


 SAFE STATE S:{ P1 P3 P4 P0 P2 }

D:\ai&ds\4th sem\os\lab programs\programs\deadlock>
