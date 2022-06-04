Hello, 

This project is a unix-like terminal built from scratch. The terminal's functionality such as kernel and user access to threads and all have been abstracted by usage of relevant library functions for system calls.

The main implementation is that of the processing of multiple commands at the same time leveraging creation of multiple processes.
These multiple processes run concurrently and provide the outcomes asynchronously. 

Batch files can be processed with this shell as well.

Steps to run the shell :

1. Go to the root folder of the project
2. On the terminal, type "make".
3. If you want to run the shell in interactive mode, simply type "prunix".
4. Else, if you have a batch file in the root folder(a.sh here for example), you can type "prunix a.sh"

"" shall not be typed in the terminal (for dummies).

Thanks :)
-Pratik