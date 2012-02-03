# CTEA
These are implementations of the various Tiny Encryption Algorithms. Due to the lack of official test vectors, these are used to generate them. I have tried to make them correct, but I cannot guarantee their correctness. If any problems are found, let me know.

## Tea
An implementation of the original TEA algorithm can be found in tea.c. 

Compiling can be done with:
`gcc tea.c; ./a.out`

## XTea
An implementation of the Tea Extensions algorithm can be found in xtea.c. 

Compiling can be done with:
`gcc xtea.c; ./a.out`

## XXTea
An implementation of the Corrected Block TEA algorithm found in "Corrections to XTEA" by Wheeler and Needham can be found in xxtea.c. 

Compiling can be done with:
`gcc xxtea.c; ./a.out`

