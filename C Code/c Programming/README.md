ATM Program
===========

This is a simple ATM program in C that persists user data to `user.txt`.

File format (`user.txt`):
- line 1: username
- line 2: password
- line 3: balance (integer)

Build & Run (PowerShell / Windows):

```powershell
cd c:\Users\You\OneDrive\Desktop\Assignments
gcc -o atmProgram atmProgram.c
.\atmProgram
```

Notes:
- On first run the program will ask you to sign up (username + password) and will create `user.txt` with initial balance 1000.
- All inputs are validated: no empty strings, menu accepts only 1-4, amounts must be positive integers.
- The program overwrites `user.txt` when updating balance so the data persists across runs.
