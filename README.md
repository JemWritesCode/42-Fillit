# 42-Fillit

**Algorithms Practice - Fit tetris pieces into the smallest square possible.**

`Score: 100/100 (Outstanding Project x 3)`

Program Specs: <https://github.com/Jemmeh/42-Fillit/blob/master/WorkFiles/fillit.en.pdf>

Code Formatting Standards: <https://github.com/Jemmeh/42-Fillit/blob/master/WorkFiles/Norm.pdf>

# What Fillit Does:
Fillit recieves a map text file like this one with pieces.
![Valid Map](https://github.com/Jemmeh/42-Fillit/blob/master/WorkFiles/ExplainationImages/ExampleMapFile.png?raw=true)

It finds the smallest possible square the pieces can be arranged in and prints out the square like this:
![SolvedSquare](https://github.com/Jemmeh/42-Fillit/blob/master/WorkFiles/ExplainationImages/ExampleSolution.png?raw=true)


# How does it work?
Our functions are also commented in our Project Files.

This project relies on the [standard C Libary functions that we had to recode for our first project.](https://github.com/Jemmeh/Libft)

First the file is read by the parser and all the pieces are checked to make sure they are valid. These are the only valid pieces. The map file format is like this:

The `valid.c` file:

* Checks for any invalid characters
* Checks for wrong-length lines ('\n' in an invalid position)
* Counts number of '#' characters (Must be 4)
* Checks for '\n' at end of piece block
* Checks each '#' character to see if it's adjacent to another - A valid piece with 4 '#' characters will either have 6 or 8 adjacencies. (This is the "Count Method" that is mentioned on [Beth Nenniger's blog post.](https://medium.com/@bethnenniger/fillit-solving-for-the-smallest-square-of-tetrominos-c6316004f909) )

![PossibleTetriminos](https://github.com/Jemmeh/42-Fillit/blob/master/WorkFiles/ExplainationImages/Screen%20Shot%202019-03-19%20at%206.38.58%20PM.png?raw=true)

The `makepiece()` function then finds and stores the # characters and turns them into (x,y) coords in a piece struct. It calls the `align()` function to make sure the piece is shifted to the top left of the map. These pieces are stored in a linked list with `makelist()`

![ArrayToCoords](https://github.com/Jemmeh/42-Fillit/blob/master/WorkFiles/ExplainationImages/BufArrayToCoords.png?raw=true)


The solver works using recursive backtracking. If the piece doesn't overlap any other pieces it places it on the map and then tries to call solve_map on all of the other pieces. If they all fit with the current piece in place then it succeeds. If not it moves the current piece and tries to solve the rest of the pieces with the current piece in it's new place. If it's moved all the pieces and still can't make them fit on the current map then it exits the solver, makes a larger map, and then tries to solve again.

![SolverRecursion](https://github.com/Jemmeh/42-Fillit/blob/master/WorkFiles/ExplainationImages/Screen%20Shot%202019-03-19%20at%206.40.16%20PM.png?raw=true)

![SampleProblem1](https://github.com/Jemmeh/42-Fillit/blob/master/WorkFiles/ExplainationImages/Screen%20Shot%202019-03-19%20at%206.42.27%20PM.png?raw=true)

![SampleProblem2](https://github.com/Jemmeh/42-Fillit/blob/master/WorkFiles/ExplainationImages/Screen%20Shot%202019-03-19%20at%206.42.45%20PM.png?raw=true)

![SampleProblem3](https://github.com/Jemmeh/42-Fillit/blob/master/WorkFiles/ExplainationImages/RecursiveBacktrack.png?raw=true)


# Speed Requirements
This is not on the PDF but is a requirement by the grading scale.

`time ./fillit test1.prm`

    must execute <= 1 second

`time ./fillit test7.prm`

    30 seconds+ -> 0 pts
    20-30 seconds -> 1 pt
    10-20 seconds -> 2 pt
    5-10 seconds -> 3pt
    1-5 seconds -> 4pt
    < 1 second -> 5 pt

Ours scores 0.00s in both cases so we got max score on this part.

# Team
Jem Cope <https://github.com/Jemmeh>

Crystal Schuller <https://github.com/tasertasertaser>
