# 42-Fillit

Algorithms Practice - Fit tetris pieces into the smallest square possible.

`Score: 100/100 (Outstanding Project x 3)`

Program Specs: <https://github.com/Jemmeh/42-Fillit/blob/master/WorkFiles/fillit.en.pdf>

Code Formatting Standards: <https://github.com/Jemmeh/42-Fillit/blob/master/WorkFiles/Norm.pdf>

Speed requirements:
`time ./fillit test1.prm`
  must execute <= 1 second

`time ./fillit test7.prm`
  30 seconds+ -> 0 pts
  20-30 seconds -> 1 pt
  10-20 seconds -> 2 pt
  5-10 seconds -> 3pt
  1-5 seconds -> 4pt
  < 1 second -> 5 pt

Ours scores 0.00s in both cases.

# How does it work?
First the file is read by the parser and all the pieces are checked to make sure they are valid. If it is, it's passed to the solver.

The solver works using recursive backtracking. If the piece doesn't overlap any other pieces it places it on the map and then tries to call solve_map on all of the other pieces. If they all fit with the current piece in place then it succeeds. If not it moves the current piece and tries to solve the rest of the pieces with the current piece in it's new place. If it's moved all the pieces and still can't make them fit on the current map then it exits the solver, makes a larger map, and then tries to solve again.

# Team
Jem Cope <https://github.com/Jemmeh>

Crystal Schuller <https://github.com/tasertasertaser>
