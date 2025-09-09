# To-Do List Manager in C

## Description
This is a simple console-based To-Do List Manager written in C.  
It allows the user to **add, view, update, and remove tasks**.  
Each task stores:
- Task description
- Priority (high, medium, low)
- Status (pending, completed, progress)
- Due date (YYYY-MM-DD)

The program also saves tasks to a file `myfile.txt` whenever changes are made.

## Features
1. Add new tasks  
2. View all tasks  
3. Remove tasks  
4. Update task details  
5. Save tasks to a file  

## How it works
1. The program maintains a dynamic array of tasks using `malloc` and `realloc`.  
2. Users interact via a simple menu.  
3. All strings for priority and status are converted to lowercase for uniformity.  
4. Updates, deletions, and additions are reflected immediately on the console and saved to a file.  

## How to Use
1. Run the program.  
2. Enter your choice from the menu:  
   - `1` to add a task  
   - `2` to view all tasks  
   - `3` to remove a task  
   - `4` to update a task  
   - `5` to exit  
3. Follow prompts to enter or modify task details.  
4. All changes are automatically saved to `myfile.txt`.
