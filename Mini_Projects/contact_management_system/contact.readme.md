# Contact Manager in C

## Description
This is a simple console-based Contact Manager program written in C.  
It allows the user to **add, view, update, remove, and search contacts**.  
Each contact stores:
- Name
- Email
- Gender
- Date of Birth
- Phone number

The program also saves the contacts to a file `myfile.txt` whenever changes are made.

## Features
1. Add new contacts  
2. View all contacts  
3. Remove contacts  
4. Update contact details  
5. Search contacts by name  
6. Save contacts to a file  

## How it works
1. The program maintains a dynamic array of contacts using `malloc` and `realloc`.  
2. Users interact via a simple menu.  
3. All strings are converted to lowercase for uniformity.  
4. Updates, deletions, and searches are reflected immediately on the console and saved to a file.  

## How to Use
1. Run the program.  
2. Enter your choice from the menu:  
   - `1` to add a contact  
   - `2` to view all contacts  
   - `3` to remove a contact  
   - `4` to update a contact  
   - `5` to search for a contact  
   - `6` to exit  
3. Follow prompts to enter or modify contact details.  
4. All changes are automatically saved to `myfile.txt`.
