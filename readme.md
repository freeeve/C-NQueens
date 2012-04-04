## C-NQueens
This is a C implementation of the Eight (N) Queens algorithm.

Comparing speed to my scala implementation of a similar algorithm. It's actually not any faster.
I may try to optimize it in both.

Here are my scala speeds:

```
[info] Set current project to ScalaEightQueens (in build file:/Users/wfreeman/Documents/ScalaEightQueens/)
> run 10
[info] Running scala.eightqueens.EightQueens 10
found 724 distinct solutions
[success] Total time: 1 s, completed Apr 4, 2012 3:56:10 AM
> run 11
[info] Running scala.eightqueens.EightQueens 11
found 2680 distinct solutions
[success] Total time: 0 s, completed Apr 4, 2012 3:56:15 AM
> run 12
[info] Running scala.eightqueens.EightQueens 12
found 14200 distinct solutions
[success] Total time: 2 s, completed Apr 4, 2012 3:56:20 AM
> run 13
[info] Running scala.eightqueens.EightQueens 13
found 73712 distinct solutions
[success] Total time: 9 s, completed Apr 4, 2012 3:56:32 AM
> run 14
[info] Running scala.eightqueens.EightQueens 14
found 365596 distinct solutions
[success] Total time: 60 s, completed Apr 4, 2012 3:57:59 AM
> run 15
[info] Running scala.eightqueens.EightQueens 15
found 2279184 distinct solutions
[success] Total time: 462 s, completed Apr 4, 2012 4:07:33 AM
```

And my C speeds:

```
Wess-MacBook-Pro:nqueens wfreeman$ time ./nqueens 10
found 724 distinct solutions

real 0m0.056s
user	0m0.055s
sys	0m0.001s
Wess-MacBook-Pro:nqueens wfreeman$ time ./nqueens 11
found 2680 distinct solutions

real	0m0.274s
user	0m0.272s
sys	0m0.001s
Wess-MacBook-Pro:nqueens wfreeman$ time ./nqueens 12
found 14200 distinct solutions

real	0m1.529s
user	0m1.525s
sys	0m0.002s
Wess-MacBook-Pro:nqueens wfreeman$ time ./nqueens 13
found 73712 distinct solutions

real	0m9.257s
user	0m9.239s
sys	0m0.009s
Wess-MacBook-Pro:nqueens wfreeman$ time ./nqueens 14
found 365596 distinct solutions

real	1m0.356s
user	1m0.236s
sys	0m0.060s
```

## License LGPL
Copyright 2012 Wes Freeman

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.
 
You should have received a copy of the GNU Lesser General Public License
along with this program.  If not, see http://www.gnu.org/licenses/
