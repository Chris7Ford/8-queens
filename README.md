# 8 Queens Challenge

How many possible ways are there to fit 8 queens onto a standard 8x8 chessboard without them being able to reach each other?

### Introduction

This was an exercise I did in the beginning months of my time at 42. The point of the exercises was to prepare myself for an upcoming project called Fillit (link to fillit.), which requires a strong understanding of recursive backtracking.

### Compilation

There are two exercises in this repository, each with a photo of its instructions from the original Piscine C PDF (I did not get to these exercises at the time of the Piscine.)

Each of the exercises can be compiled from their own directories (The Libft library must be included.)

### Description

In the code, the board is represented by an 8x8 grid of 0s, and queens by 1s.  There is an output file that shows what the program is doing step by step in order to place the queens for the first solution.

![00](https://user-images.githubusercontent.com/29003743/62428923-97e53a80-b6bc-11e9-93f0-24c5d2f0a57f.png)

Running the first program will give the number of possible ways the queens can be placed without touching each other.  Running the second program will give the queens position by row and column.
