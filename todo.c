/* to do list */
/*
- add list 
- delete list
 */


#include<stdio.h>
#include<string.h>

struct to_do_list
{
    char task[100];
    int id;
};
/*--------------ADD LIST-------------------*/
void add_list(){
    FILE* ftpr;
    ftpr=fopen("todo.txt","ab");

    if(!ftpr){
        printf("error opening the file");
        return ;
    }

    struct to_do_list todo;

    printf("Enter the Task ID: ");
    scanf("%d",&todo.id);
    getchar(); //consume leftover newline 


    //check if the ID already exists 
    FILE* checkfile;
    checkfile=fopen("todo.txt","rb");
    if (checkfile)
    {
        struct to_do_list temp;
        while (fread(&temp,sizeof(struct to_do_list),1,checkfile))
        {
            if(temp.id==todo.id)
            {
                printf("The Todo with same id %d already exists\n",todo.id);
                fclose(checkfile);
                return;
            }
        }
        
        
    }
    printf("Enter the Task: ");
    fgets(todo.task, sizeof(todo.task), stdin);
    // Remove trailing newline character if exists
    todo.task[strcspn(todo.task, "\n")] = '\0';

    fwrite(&todo, sizeof(struct to_do_list), 1, ftpr);
    fclose(ftpr);
    printf("---- Task added sucessfully ----\n");
}

/*--------------VIEW TASKS---------------------*/
void view_tasks(){
    FILE* fptr;
    fptr=fopen("todo.txt","rb");
    if (!fptr) {
        printf("No tasks found.\n");
        return;
    }

    struct to_do_list todo;

    printf("---- List of Tasks ----\n");
    printf("ID\t\tTask\n");
    while (fread(&todo, sizeof(struct to_do_list),1,fptr))
    {        
        printf("%d\t\t%s\n",todo.id,todo.task);

    }

    fclose(fptr);
}

/*--------------EDIT TASK--------------*/
void edit_task(){
    FILE* fptr;
    fptr=fopen("todo.txt","r+b");  

    struct to_do_list todo;
    if (!fptr) {
        printf("No tasks found.\n");
        return;
    }
    int edit_id;
    printf("Enter Task ID to edit: ");
    scanf("%d",&edit_id);
    getchar();
    //consume the leftover newline

    int found=0;
    //search through file for task 

    while(fread(&todo, sizeof(struct to_do_list),1,fptr)){
        if (todo.id==edit_id)
        {
            found=1;
            printf("current task: %s\n",todo.task);
            printf("Enter new task description: ");
            fgets(todo.task,sizeof(todo.task),stdin);
            todo.task[strcspn(todo.task,"\n")]= '\0';// remove newline
            
            
            // Move file pointer back to the start of this record
            fseek(fptr, -sizeof(todo), SEEK_CUR);

            // Write the updated task back
            fwrite(&todo, sizeof(todo), 1, fptr);
            printf("Task updated successfully.\n");
            break;
        }
    }

    if (!found) {
        printf("Task with ID %d not found.\n", edit_id);
    }

    fclose(fptr);

}

/*-------------DELETE TASK-------------*/
void delete_task() {
    int del_id;
    printf("Enter Task ID to mark as completed (delete): ");
    scanf("%d", &del_id);

    FILE *fptr = fopen("todo.txt", "rb");
    if (!fptr) {
        printf("No tasks found.\n");
        return;
    }

    FILE *temp = fopen("temp.txt", "wb");
    if (!temp) {
        printf("Error opening temporary file.\n");
        fclose(fptr);
        return;
    }

    struct to_do_list todo;
    int found = 0;

    while (fread(&todo, sizeof(todo), 1, fptr)) {
        if (todo.id == del_id) {
            found = 1;
            // Skip writing this task to temp file -> effectively deletes it
        } else {
            fwrite(&todo, sizeof(todo), 1, temp);
        }
    }

    fclose(fptr);
    fclose(temp);

    if (found) {
        // Remove original file and rename temp file
        remove("todo.txt");
        rename("temp.txt", "todo.txt");
        printf("Task with ID %d marked as completed and deleted.\n", del_id);
    } else {
        printf("Task with ID %d not found.\n", del_id);
        // Remove temp file as no changes
        remove("temp.txt");
    }
}




int main(){
    int choice ;


    while (1)
    {
        printf("----- To Do List ----\n");
        printf("1. Add task\n");
        printf("2. View all tasks\n");
        printf("3. Edit Task by Entering ID\n");
        printf("4. Mark Task as completed\n");
        printf("5. Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        
        switch (choice)
        {
        case 1: add_list();
            break;
        case 2: view_tasks();
            break;
        case 3: edit_task();
            break;
        case 4: delete_task();
            break;  
        case 5: return 0 ;
            break;

    }
    
}}
