# myBLASlib
simple C++ BLAS library being implemented for exercise

--

```

testing Matrix arithmetic:
I3 = 3x3 identity
3 rows 	3 cols	1 channels
 1, 0, 0
 0, 1, 0
 0, 0, 1


I3 + I3 =
3 rows 	3 cols	1 channels
 2, 0, 0
 0, 2, 0
 0, 0, 2


(I3 + I3) / 2 =
3 rows 	3 cols	1 channels
 1, 0, 0
 0, 1, 0
 0, 0, 1


I3 * 2 =
3 rows 	3 cols	1 channels
 2, 0, 0
 0, 2, 0
 0, 0, 2


I3 - I3 =
3 rows 	3 cols	1 channels
 0, 0, 0
 0, 0, 0
 0, 0, 0


I34 = 3x4x5 identity
3 rows 	4 cols	2 channels
 5, 0, 0, 0
 0, 5, 0, 0
 0, 0, 5, 0

 5, 0, 0, 0
 0, 5, 0, 0
 0, 0, 5, 0


A = 2x3x4 zeroes
2 rows 	3 cols	4 channels
 0, 0, 0
 0, 0, 0

 0, 0, 0
 0, 0, 0

 0, 0, 0
 0, 0, 0

 0, 0, 0
 0, 0, 0


A = 2x3x4 ones
2 rows 	3 cols	4 channels
 1, 1, 1
 1, 1, 1

 1, 1, 1
 1, 1, 1

 1, 1, 1
 1, 1, 1

 1, 1, 1
 1, 1, 1


A + A =
2 rows 	3 cols	4 channels
 2, 2, 2
 2, 2, 2

 2, 2, 2
 2, 2, 2

 2, 2, 2
 2, 2, 2

 2, 2, 2
 2, 2, 2


(A + A) / 2 =
2 rows 	3 cols	4 channels
 1, 1, 1
 1, 1, 1

 1, 1, 1
 1, 1, 1

 1, 1, 1
 1, 1, 1

 1, 1, 1
 1, 1, 1


A = A * 2 =
2 rows 	3 cols	4 channels
 2, 2, 2
 2, 2, 2

 2, 2, 2
 2, 2, 2

 2, 2, 2
 2, 2, 2

 2, 2, 2
 2, 2, 2


A = arrange(23)
2 rows 	3 cols	4 channels
 0, 1, 2
 3, 4, 5

 6, 7, 8
 9, 10, 11

 12, 13, 14
 15, 16, 17

 18, 19, 20
 21, 22, 23


t = transpose(A) =
3 rows 	2 cols	4 channels
 0, 3
 1, 4
 2, 5

 6, 9
 7, 10
 8, 11

 12, 15
 13, 16
 14, 17

 18, 21
 19, 22
 20, 23


A = A * t =
2 rows 	2 cols	4 channels
 5, 14
 14, 50

 149, 212
 212, 302

 509, 626
 626, 770

 1085, 1256
 1256, 1454


A = A - A =
2 rows 	2 cols	4 channels
 0, 0
 0, 0

 0, 0
 0, 0

 0, 0
 0, 0

 0, 0
 0, 0


set A(1, 1, 1) = 10
2 rows 	2 cols	4 channels
 0, 0
 0, 0

 0, 0
 0, 10

 0, 0
 0, 0

 0, 0
 0, 0


A(1, 1, 1) = 10

set A(1, 1, 1) = 0
2 rows 	2 cols	4 channels
 0, 0
 0, 0

 0, 0
 0, 0

 0, 0
 0, 0

 0, 0
 0, 0
 
```
