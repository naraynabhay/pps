// C program to implement
// the above approach
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1000

void status(){
    FILE * fPtr;
    FILE * fTemp;
    char path[100];
    
    char buffer[BUFFER_SIZE];
    char newline[BUFFER_SIZE];
    int line, count;


    printf("Enter path of source file: ");
    scanf("%s", path);

    printf("Enter line number to replace: ");
    scanf("%d", &line);

    /* Remove extra new line character from stdin */
    fflush(stdin);

    printf("Replace '%d' line with: ", line);
    fgets(newline, BUFFER_SIZE, stdin);


    /*  Open all required files */
    fPtr  = fopen(path, "r");
    fTemp = fopen("replace.tmp", "w"); 

    /* fopen() return NULL if unable to open file in given mode. */
    if (fPtr == NULL || fTemp == NULL)
    {
        /* Unable to open file hence exit */
        printf("\nUnable to open file.\n");
        printf("Please check whether file exists and you have read/write privilege.\n");
        exit(EXIT_SUCCESS);
    }


    /*
     * Read line from source file and write to destination 
     * file after replacing given line.
     */
    count = 0;
    while ((fgets(buffer, BUFFER_SIZE, fPtr)) != NULL)
    {
        count++;

        /* If current line is line to replace */
        if (count == line)
            fputs(newline, fTemp);
        else
            fputs(buffer, fTemp);
    }


    /* Close all files to release resource */
    fclose(fPtr);
    fclose(fTemp);


    /* Delete original source file */
    remove(path);

    /* Rename temporary file as original file */
    rename("replace.tmp", path);

    printf("\nSuccessfully replaced '%d' line with '%s'.", line, newline);
}



void Teacher(){
    printf("Please enter the password to access as teacher: ");
    int pass;
    scanf("%d",&pass);
    
    if(pass==1){ 
        // home:
        printf("To open or add books in book list : Enter 1 \nTo open a student file: Enter 2 \n");
        int tch_choice;
        scanf("%d",&tch_choice);
        if(tch_choice==1){
            char data[100];    
            FILE* fp;
            printf("Booklists \n");
            fp=fopen("booklist.txt","a+");
            while (fgets(data, 100, fp) != NULL) {
                printf("%s", data);
            }
            fclose(fp);

            printf("If you want to add books Enter 1:\nTo edit book availability Enter 2");
            printf("Enter 0 to start again ;\n");
            printf("To exit enter any number: ");
            int add;
            scanf("%d",&add);
            

            if(add==1){
                
                char data[100];
                char new_book[100];
                FILE* fp;

                fp=fopen("booklist.txt","a+");
                printf("\nAdd new books: ");
                // Reason unknown for two input
                gets(new_book);
                fgets(new_book,100,stdin);
                // fgets(new_book,100,stdin);
        
                fputs(new_book,fp);
                fclose(fp);

                fp=fopen("booklist.txt", "a+");
                printf("The updated booklist is\n");
                while (fgets(data, 100, fp) != NULL) {
                    printf("%s", data);
                }
                fclose(fp);
            }
            else if(add==2){
                status();
            }
            else if(add==0){
                system("cls");
                // goto home;
            }
            else{
                return;
            }

        }
        else if(tch_choice==2){
            int roll;
            FILE* fp;
            char id[50];
            char data[1000];
            printf("Enter the student roll no: ");
            scanf("%d",&roll);
            sprintf(id,"%d",roll);
            char txt[5]=".txt";
            strcat(id,txt);
            if(roll<=1800000 || roll>=2200000 ){
                printf("Enter a valid roll ");
            }
            else{
                fp=fopen(id,"a+");
                while (fgets(data, 1000, fp) != NULL) {
                    printf("%s", data);
                }
                fseek (fp, 0, SEEK_END);
                int size = ftell(fp);
                fclose(fp);
               
                if (size == 0) {
                    
                    char name[50];
                    char roll[50];
                    char branch[50];
                    char batch[50];
                    char book_name[50];
                    char date[50];
                    char replace_book[50];
                    fp=fopen(id,"a+");
                    fputs("hii",fp);
                    printf("Add details: \n");
                    // struct student std;
                    printf("Name: ");
                    gets(name);
                    gets(name);
                    
                    fputs(name,fp);
                    fputs("\n",fp);
                    printf("\nRoll no: ");
                    scanf("%s",roll);
                    fputs(roll,fp);
                    fputs("\n",fp);
                    printf("\nBranch: ");
                    scanf("%s",branch);
                    fputs(branch,fp);
                    fputs("\n",fp);
                    printf("\nBatch: ");
                    scanf("%s",batch);
                    fputs(batch,fp);
                    fputs("\n",fp);
                    fputs("Student Record :\n",fp);

                    printf("To issue a book Enter 1: ");
                    int issue_book;
                    scanf("%d",&issue_book);
                    
                    if(issue_book==1){
                        printf("Book name: ");
                        gets(book_name);
                        gets(book_name);

                        printf("\nDate: ");
                        gets(date);
                        char issued_book[50];
                        strcpy(issued_book,book_name);
                        strcat(issued_book," issued on ");
                        strcat(issued_book,date);
                        fputs(issued_book,fp);
                    }
                    fclose(fp);
                    
                }
                else{
                    printf("To issue a book Enter 1:\nTo return a book Enter 2: ");
                    int iss_ret;
                    scanf("%d",&iss_ret);
                    if(iss_ret==1){
                        char book_name[50];
                        char date[50];
                        fp=fopen(id,"a+");
                    
                        printf("Book name: ");
                        gets(book_name);
                        gets(book_name);

                        printf("\nDate: ");
                        gets(date);
                        char issued_book[50];
                        strcpy(issued_book,book_name);
                        strcat(issued_book," issued on ");
                        strcat(issued_book,date);
                        fputs(issued_book,fp);
                    
                        fclose(fp);
                    }
                    else if(iss_ret==2){
                        
                        char book_name[50];
                        char date[50];
                        fp=fopen(id,"a+");
                    
                        printf("Book name: ");
                        gets(book_name);
                        gets(book_name);

                        printf("\nDate: ");
                        gets(date);
                        char returned_book[50];
                        strcpy(returned_book,book_name);
                        strcat(returned_book," returned on ");
                        strcat(returned_book,date);
                        fputs(returned_book,fp);
                    
                        fclose(fp);
                    
                    }
                }
            }
        }
        else{
            printf("Please enter a valid number");
        }
    }
    else{
            printf("Please enter correct password");
    }
}

void Student_enq(){
    
    printf("To open book list: Enter 1\n");
    printf("To know your record: Enter 2\n");
    int std_choice;
    scanf("%d",&std_choice);

    if(std_choice==1){
        char data[100];    
        FILE* fp;
        printf("The available books are\n");
        fp=fopen("booklist.txt","a+");
        while (fgets(data, 100, fp) != NULL) {
            printf("%s", data);
        }
        fclose(fp);
    }
    else if(std_choice==2){
        int roll;
        FILE* fp;
        char id[50];
        char data[1000];
        printf("Enter your roll no: ");
        scanf("%d",&roll);
        sprintf(id,"%d",roll);
        char txt[5]=".txt";
        strcat(id,txt);
        if(roll<=1800000 || roll>=2200000 ){
            printf("Roll No not found");
        }
        else{
            fp=fopen(id,"a+");
            while (fgets(data, 1000, fp) != NULL) {
                    printf("%s", data);
            }
            fseek (fp, 0, SEEK_END);
            int size = ftell(fp);
            
            if (0 == size) {
                printf("file is empty\n");
            }
            
            fclose(fp);
        }
    }
    else{
        printf("Please enter a valid number");
    }
}

void Login(){
    // start:
    printf("To Login as teacher: Enter 1\n");
    printf("To Login as student: Enter 2\n");
    printf("To exit Enter any number: ");

    int login_as;
    scanf("%d",&login_as);
    if(login_as==1){
         Teacher();
         system("cls");
        //  goto start; 
    }
    else if(login_as==2){
         Student_enq();
         system("cls");
        //  goto start; 
    }
    else{ 
        printf("Please enter a valid number"); 
        system("cls");
        // goto start;
    }
}
// Driver code
int main()
{
    Login();
    return 0;
}
