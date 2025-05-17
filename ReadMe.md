# To-Do List Application

A simple command-line To-Do List application written in C that allows users to add, view, edit, and delete tasks. Tasks are stored persistently in a file named `todo.txt`.

## Features

* Add new tasks with unique IDs
* View all existing tasks
* Edit tasks by specifying the task ID
* Mark tasks as completed (delete by ID)
* Persistent storage using binary file operations

## How to Compile and Run

1. Save the source code in a file, for example, `todo.c`.
2. Compile the program using GCC or any C compiler:

```bash
gcc todo.c -o todo
```

3. Run the compiled executable:

```bash
./todo
```

## Usage

On running the program, you will see the following menu:

```
----- To Do List ----
1. Add task
2. View all tasks
3. Edit Task by Entering ID
4. Mark Task as completed
5. Exit
Enter your choice:
```

* **Add task:** Enter a unique task ID and description.
* **View all tasks:** Lists all tasks with their IDs.
* **Edit task:** Modify the description of an existing task by ID.
* **Mark task as completed:** Deletes the task by ID.
* **Exit:** Terminates the program.

## File Storage

Tasks are stored in a binary file `todo.txt`. Each record consists of a struct with an ID and a task description.

---

## Future Improvements / Suggestions
* []Add priority levels and sort tasks by priority.
* []Implement search by keywords.
* []Use status (Pending/Completed) instead of deleting tasks.
* []Store tasks in text formats like JSON or CSV.
* []Add undo for delete/edit actions.
* []Improve error handling and input validation.
* []Ensure cross-platform compatibility.
* []Create a GUI version for better usability.

