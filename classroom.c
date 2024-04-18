#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct
{
    char name[100];
    char roll[100];
    char pass[100];
}student;

typedef struct
{
    char name[100];
    char ID[100];
    char pass[100];
}teacher;

typedef struct
{
    char text[1000];
    //char count[100];
    //int sl;
    //int seen[100];
}notice;

typedef struct
{
    char name[100];
    char roll[100];
    char marks[100];
    //char seen[100];
}student_info;

int num=0;

void teacher_reg()
{
    FILE* fp=fopen("teacher.txt","a");
    if(fp==NULL)
    {
        printf("File not opened\n");
    }
    teacher info;
    printf("Enter name:\n");
    fflush(stdin);
    gets(info.name);
//    scanf(" %[^\n]",&info.name);
    //fprintf(fp,"%s\n",info.name);
    printf("Enter ID:\n");
    gets(info.ID);
//    scanf(" %[^\n]",&info.ID);
    //fprintf(fp,"%s\n",info.ID);
    printf("Enter password:\n");
    gets(info.pass);
//    scanf(" %[^\n]",&info.pass);
    //fprintf(fp,"%s\n",info.pass);
    fwrite(&info,sizeof(info),1,fp);
    fclose(fp);
}

void student_reg()
{
    FILE* fp=fopen("student.txt","a");
    if(fp==NULL)
    {
        printf("File not opened\n");
    }
    student info;
    printf("Enter name:\n");
    fflush(stdin);
    gets(info.name);
//    scanf(" %[^\n]",&info.name);
    //fprintf(fp,"%s\n",info.name);
    printf("Enter roll:\n");
    gets(info.roll);
//    scanf(" %[^\n]",&info.roll);
    //fprintf(fp,"%d\n",info.roll);
    printf("Enter password:\n");
    gets(info.pass);
//    scanf(" %[^\n]",&info.pass);
    //fprintf(fp,"%s\n",info.pass);
    fwrite(&info,sizeof(info),1,fp);
    fclose(fp);
}

int teacher_login()
{
//    FILE* fp=fopen("teacher.txt","r");
//    if(fp==NULL)
//    {
//        printf("File not opened\n");
//    }
//    char ID[100];
//    char pass[100];
//    teacher info;
//    printf("Enter ID :\n");
//    fflush(stdin);
//    gets(ID);
////    scanf(" %[^\n]",ID);
//    printf("Enter password :\n");
//    gets(pass);
//    int flag=0;
//    int found=0;
//    while(fread(&info,sizeof(info),1,fp))
//    {
//        if(strcmp(ID,info.ID)==0)
//        {
//            found++;
//            if(strcmp(pass,info.pass)==0)
//            {
//                printf("\n\nSuccessful login\n");
//                flag++;
//            }
//        }
//    }
//
//    if(!found)
//    {
//        printf("\n\nID not registered\n");
//    }
//    if(found&&!flag)
//    {
//        printf("\n\nIncorrect password\n");
//    }
//    fclose(fp);
//    return flag;
    FILE* fp=fopen("teacher.txt","r");
    if(fp==NULL)
    {
        printf("File not opened\n");
    }
    char ID[100];
    char pass[100];
    teacher info;
    printf("Enter ID :\n");
    fflush(stdin);
    gets(ID);
    printf("Enter password :\n");
    gets(pass);
    int flag=0;
    int found=0;
    while(fread(&info,sizeof(teacher),1,fp))
    {
        if(strcmp(ID,info.ID)==0)
        {
            found++;
            if(strcmp(pass,info.pass)==0)
            {
                printf("\n\nSuccessful login\n");
                flag++;
            }
        }
    }
    if(!found)
    {
        printf("\n\nID not registered\n");
    }
    if(found&&!flag)
    {
        printf("\n\nIncorrect password\n");
    }
    return flag;
}

int student_login(char roll[100])
{
    FILE* fp=fopen("student.txt","r");
    if(fp==NULL)
    {
        printf("File not opened\n");
    }
    //char roll[100];
    char pass[100];
    student info;
//    printf("Enter roll :\n");
//    fflush(stdin);
//    gets(roll);
    printf("Enter password :\n");
    gets(pass);
    int flag=0;
    int found=0;
    while(fread(&info,sizeof(student),1,fp))
    {
        if(strcmp(roll,info.roll)==0)
        {
            found++;
            if(strcmp(pass,info.pass)==0)
            {
                printf("\n\nSuccessful login\n");
                flag++;

            }
        }
    }
    fclose(fp);
    if(!found)
    {
        printf("\n\nID not registered\n");
    }
    if(found&&!flag)
    {
        printf("\n\nIncorrect password\n");
    }
    return flag;
}

void addstudent()
{
    int another;
    FILE *fp;
    student_info info;
    do
    {
        system("CLS");
        printf("\n\n\n\t\t\t\t\t\t\tAdd Student Info\n");
        printf("_______________________________________________________________________________________________________________________\n");
        printf("_______________________________________________________________________________________________________________________\n");
        fp=fopen("class.txt","a");
        printf("Enter name :\n");
        scanf(" %[^\n]",info.name);
        printf("Enter roll :\n");
        scanf(" %[^\n]",info.roll);
        printf("Enter marks :\n");
        scanf(" %[^\n]",info.marks);
//        printf("Enter seen count :");
//        scanf(" %[^\n]",&info.seen);
        if(fp==NULL)
        {
            printf("\nFile not opened\n");
        }
        fwrite(&info,sizeof(student_info),1,fp);
        fclose(fp);
        printf("\n\nStudent added successfully\n");
        getch();
        system("CLS");
        printf("\nAdd more students? (1/0)\n");
        scanf("%i",&another);
    }while(another==1);
}

void searchstudent()
{
    int another;
    FILE*fp;
    student_info info;
    do
    {
        system("CLS");
        printf("\n\n\n\t\t\t\t\t\t\tSearch Student\n");
        printf("_______________________________________________________________________________________________________________________\n");
        printf("_______________________________________________________________________________________________________________________\n");
        char search_roll[100];
        int found=0;
        fp=fopen("class.txt","r");
        printf("Enter roll :\n");
        scanf(" %[^\n]",search_roll);
        while(fread(&info,sizeof(info),1,fp))
        {
            if(strcmp(search_roll,info.roll)==0)
            {
                found++;
                system("CLS");
                printf("\n\n\n\t\t\t\t\t\t\tSeacrh Results\n");
                printf("_______________________________________________________________________________________________________________________\n");
                printf("_______________________________________________________________________________________________________________________\n");
                printf("\nStudent name : %s\n",info.name);
                printf("Student roll : %s\n",info.roll);
                printf("Marks : %s\n",info.marks);
            }
        }
        if(found==0)
        {
            printf("\nNo results found\n");
        }
        fclose(fp);
        getch();
        system("CLS");
        printf("\nSearch more records? (1/0)\n");
        scanf("%i",&another);
    }while(another==1);
}

void removestudent()
{
    int another;
    FILE *fp;
    FILE *fp1;
    student_info info;
    do
    {
        system("CLS");
        printf("\n\n\n\t\t\t\t\t\t\tRemove Student\n");
        printf("_______________________________________________________________________________________________________________________\n");
        printf("_______________________________________________________________________________________________________________________\n");
        char search_roll[100];
        int match=0;
        fp=fopen("class.txt","r");
        fp1=fopen("temp.txt","w");
        printf("\nEnter roll :\n");
        scanf(" %[^\n]",search_roll);
        if(fp==NULL)
        {
            printf("\nFile not opened\n");
        }
        while(fread(&info,sizeof(student_info),1,fp))
        {
            if(strcmp(search_roll,info.roll)==0)
            {
                match++;
            }
            else if(strcmp(search_roll,info.roll)!=0)
            {
                fwrite(&info,sizeof(info),1,fp1);
            }
        }
        fclose(fp);
        fclose(fp1);
        if(match)
        {
            remove("class.txt");
            rename("temp.txt","class.txt");
            printf("\nStudent removed successfully\n");
        }
        if(!match)
        {
            printf("\nNo matches found\n");
        }
        getch();
        system("CLS");
        printf("Remove more students?(1/0)\n");
        scanf("%d",&another);
    }while(another==1);
}

void studentrecords()
{
    FILE*fp;
    student_info info;
    system("CLS");
    printf("\n\n\n\t\t\t\t\t\t\tStudent Records\n");
    printf("_______________________________________________________________________________________________________________________\n");
    printf("_______________________________________________________________________________________________________________________\n");
    fp=fopen("class.txt","r");
    if(fp==NULL)
    {
        printf("File not opened\n");
    }
    while(fread(&info,sizeof(info),1,fp))
    {
        printf("\nStudent name : %s\n",info.name);
        printf("Student roll : %s\n",info.roll);
        printf("Marks : %s\n",info.marks);
    }
    fclose(fp);
    getch();
}

void addnotice()
{
    int another;
    FILE *fp;
    notice info;
    system("CLS");
    printf("\n\n\n\t\t\t\t\t\t\tAdd Notice\n");
    printf("_______________________________________________________________________________________________________________________\n");
    printf("_______________________________________________________________________________________________________________________\n");
    fp=fopen("notice.txt","a");
//       printf("Enter notice serial no :\n");
//        scanf("%d",&info.sl);
    printf("Enter notice :\n");
    scanf(" %[^\n]",info.text);
//    printf("Enter seen count :\n");
//    scanf(" %[^\n]",info.count);
//        for(int i=0;i<100;i++)
//        {
//            info.seen[i]=0;
//        }
    if(fp==NULL)
    {
        printf("\nFile not opened\n");
    }
    fwrite(&info,sizeof(notice),1,fp);
    fclose(fp);
    printf("\n\nNotice added successfully\n");
    getch();
}

void shownotice()
{
    FILE*fp;
    notice info;
    system("CLS");
    printf("\n\n\n\t\t\t\t\t\t\tNotices\n");
    printf("_______________________________________________________________________________________________________________________\n");
    printf("_______________________________________________________________________________________________________________________\n");
    fp=fopen("notice.txt","r");
    int nflag=0;
//    if(fp==NULL)
//    {
//        printf("File not opened\n");
//    }
    while(fread(&info,sizeof(info),1,fp))
    {
        //printf("%d. %s\n",info.sl,info.text);
        printf("%s\n",info.text);
        printf("Seen by : %d\n",num);
        nflag++;
    }
    if(nflag==0)
    {
        printf("No notices\n");
    }
    fclose(fp);
    getch();
}

//int seen_count()
//{
//    FILE* fp=fopen("class.txt","r");
//    int sum=0;
//    student_info info;
//    while(fread(&info,sizeof(info),1,fp))
//    {
//        sum+=(info.seen-'0');
//    }
//    fclose(fp);
//    return sum;
//}

void removenotice()
{
    system("CLS");
    printf("\n\n\n\t\t\t\t\t\t\tRemove Notices\n");
    printf("_______________________________________________________________________________________________________________________\n");
    printf("_______________________________________________________________________________________________________________________\n");
    remove("notice.txt");
    rename("temp2.txt","notice.txt");
    num=0;
    printf("\nNotice removed successfully\n");
}

int showclasses(char search_roll[100])
{
    FILE*fp;
    student_info info;
    system("CLS");
    printf("\n\n\n\t\t\t\t\t\t\tClasses\n");
    printf("_______________________________________________________________________________________________________________________\n");
    printf("_______________________________________________________________________________________________________________________\n");
//    char search_roll[100];
    int found=0;
    fp=fopen("class.txt","r");
//    printf("Enter roll :\n");
//    scanf(" %[^\n]",search_roll);
    while(fread(&info,sizeof(student_info),1,fp))
    {
        if(strcmp(search_roll,info.roll)==0)
        {
            found++;
            system("CLS");
            printf("\n\n\n\t\t\t\t\t\t\tClasses\n");
            printf("_______________________________________________________________________________________________________________________\n");
            printf("_______________________________________________________________________________________________________________________\n");
            printf("Welcome to your class!!");
        }
    }
    if(found==0)
    {
        printf("\nNo classes\n");
    }
    fclose(fp);
    getch();
    return found;
}

void showclassmates(char search_roll[100])
{
    system("CLS");
    printf("\n\n\n\t\t\t\t\t\t\tClassmates\n");
    printf("_______________________________________________________________________________________________________________________\n");
    printf("_______________________________________________________________________________________________________________________\n");
//    char search_roll[100];
//    printf("Enter your roll :\n");
//    scanf(" %[^\n]",search_roll);
    FILE*fp;
    student_info info;
    int cmflag=0;
    system("CLS");
    printf("\n\n\n\t\t\t\t\t\t\tClassmates\n");
    printf("_______________________________________________________________________________________________________________________\n");
    printf("_______________________________________________________________________________________________________________________\n");
    fp=fopen("class.txt","r");
    if(fp==NULL)
    {
        printf("File not opened\n");
    }
    while(fread(&info,sizeof(info),1,fp))
    {
        if(strcmp(search_roll,info.roll)!=0)
        {
            printf("\nStudent name : %s\n",info.name);
            printf("Student roll : %s\n",info.roll);
            cmflag++;
        }
    }
    if(cmflag==0)
    {
        printf("No classmates\n");
    }
    fclose(fp);
    getch();
}

void shownotice_students()
{
    FILE*fp;
    fp=fopen("notice.txt","r");
    notice info;
    system("CLS");
    printf("\n\n\n\t\t\t\t\t\t\tNotices\n");
    printf("_______________________________________________________________________________________________________________________\n");
    printf("_______________________________________________________________________________________________________________________\n");
    int nflag=0;
//    if(fp==NULL)
//    {
//        printf("File not opened\n");
//    }
    while(fread(&info,sizeof(info),1,fp))
    {
        //int num=atoi(info.count);
        num++;
        //printf("%d. %s\n",info.sl,info.text);
        printf("%s\n",info.text);
        printf("Seen by : %d\n",num);
        nflag++;
    }
    if(nflag==0)
    {
        printf("No notices\n");
    }
    fclose(fp);
    getch();
}

void showmark(char search_roll[100])
{
    system("CLS");
    printf("\n\n\n\t\t\t\t\t\t\tMarksheet\n");
    printf("_______________________________________________________________________________________________________________________\n");
    printf("_______________________________________________________________________________________________________________________\n");
    //char search_roll[100];
    FILE* fp;
    student_info info;
    //int found=0;
    fp=fopen("class.txt","r");
//    printf("Enter roll :\n");
//    scanf(" %[^\n]",search_roll);
    while(fread(&info,sizeof(student_info),1,fp))
    {
        if(strcmp(search_roll,info.roll)==0)
        {
            //found++;
            system("CLS");
            printf("\n\n\n\t\t\t\t\t\t\tMarksheet\n");
            printf("_______________________________________________________________________________________________________________________\n");
            printf("_______________________________________________________________________________________________________________________\n");
            printf("\nStudent name : %s\n",info.name);
            printf("Student roll : %s\n",info.roll);
            printf("Marks : %s\n",info.marks);
        }
    }
//    if(found==0)
//    {
//        printf("\nNo results found\n");
//    }
    fclose(fp);
    getch();
}

void drawgraph()
{
    system("CLS");
    printf("\n\n\n\t\t\t\t\t\t\tMarks Statistics\n");
    printf("_______________________________________________________________________________________________________________________\n");
    printf("_______________________________________________________________________________________________________________________\n");
    FILE* fp=fopen("class.txt","r");
    student_info info;
    while(fread(&info,sizeof(info),1,fp))
    {
        int n=atof(info.marks);
        n=n/5;
        printf("\n%s   ",info.roll);
        for(int i=0;i<n;i++)
        {
            printf("*");
        }
        printf("\n");
    }
    getch();
}

void drawmarkst(char search_roll[100])
{
    system("CLS");
    printf("\n\n\n\t\t\t\t\t\t\tMarks Statistics\n");
    printf("_______________________________________________________________________________________________________________________\n");
    printf("_______________________________________________________________________________________________________________________\n");
//    printf("Enter roll :\n");
//    char search_roll[100];
//    scanf(" %[^\n]",search_roll);
    system("CLS");
    printf("\n\n\n\t\t\t\t\t\t\tMarks Statistics\n");
    printf("_______________________________________________________________________________________________________________________\n");
    printf("_______________________________________________________________________________________________________________________\n");
    FILE* fp=fopen("class.txt","r");
    student_info info;
    while(fread(&info,sizeof(info),1,fp))
    {
        int n=atof(info.marks);
        n=n/5;
        printf("\n%s ",info.roll);
        if(strcmp(search_roll,info.roll)==0)
        {
            printf("(YOU) ");
        }
        else
        {
            printf("      ");
        }
        for(int i=0;i<n;i++)
        {
            printf("*");
        }
        printf("\n");
    }
    getch();
}

int main()
{
    while(1)
    {
        system("CLS");
        printf("\n\n\n\t\t\t\t\t\t\tClassroom\n");
        printf("_______________________________________________________________________________________________________________________\n");
        printf("_______________________________________________________________________________________________________________________\n");
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("\n\nEnter your choice :");
        int choice1;
        scanf("%d",&choice1);
        switch(choice1)
        {
        case 1:
            system("CLS");
            printf("\n\n\n\t\t\t\t\t\tRegister\n");
            printf("_______________________________________________________________________________________________________________________\n");
            printf("_______________________________________________________________________________________________________________________\n");
            printf("1. Teacher\n");
            printf("2. Student\n");
            printf("3. Back\n");
            printf("\n\nEnter your choice :");
            int choice2;
            scanf("%d",&choice2);
            switch(choice2)
            {
            case 1:
                system("CLS");
                printf("\n\n\n\t\t\t\t\t\tTeacher Registration\n");
                printf("_______________________________________________________________________________________________________________________\n");
                printf("_______________________________________________________________________________________________________________________\n");
                teacher_reg();
                printf("\nRegistration successful\n");
                getch();
                break;
            case 2:
                system("CLS");
                printf("\n\n\n\t\t\t\t\t\tStudent Registration\n");
                printf("_______________________________________________________________________________________________________________________\n");
                printf("_______________________________________________________________________________________________________________________\n");
                student_reg();
                printf("\nRegistration successful\n");
                getch();
                break;
            case 3:
                break;
            default :
                system("CLS");
                printf("\n\nInvalid choice");
                getch();
                break;
            }
            break;
        case 2:
            system("CLS");
            printf("\n\n\n\t\t\t\t\t\tLogin\n");
            printf("_______________________________________________________________________________________________________________________\n");
            printf("_______________________________________________________________________________________________________________________\n");
            printf("1. Teacher\n");
            printf("2. Student\n");
            printf("3. Back\n");
            int choice3;
            printf("\n\nEnter your choice :");
            scanf("%d",&choice3);
            switch(choice3)
            {
            case 1:
                system("CLS");
                printf("\n\n\n\t\t\t\t\t\tTeacher Login\n");
                printf("_______________________________________________________________________________________________________________________\n");
                printf("_______________________________________________________________________________________________________________________\n");
                int tlog;
                tlog=teacher_login();
                if(tlog!=0)
                {
                    while(1)
                    {
                        system("CLS");
                        printf("\n\n\n\t\t\t\t\t\tClassroom Portal\n");
                        printf("_______________________________________________________________________________________________________________________\n");
                        printf("_______________________________________________________________________________________________________________________\n");
                        printf("1. Add Student\n");
                        printf("2. Search Student\n");
                        printf("3. Remove Student\n");
                        printf("4. Student Records\n");
                        printf("5. Add Notice\n");
                        printf("6. Show Notice\n");
                        printf("7. Remove Notice\n");
                        printf("8. Marks Statistics\n");
                        printf("9. Logout\n");
                        int choice4;
                        printf("\n\nEnter your choice :\n");
                        scanf("%d",&choice4);
                        if(choice4==9)
                        {
                            break;
                        }
                        switch(choice4)
                        {
                        case 1:
                            system("CLS");
                            addstudent();
                            getch();
                            break;
                        case 2:
                            system("CLS");
                            searchstudent();
                            getch();
                            break;
                        case 3:
                            system("CLS");
                            removestudent();
                            getch();
                            break;
                        case 4:
                            system("CLS");
                            studentrecords();
                            getch();
                            break;
                        case 5:
                            system("CLS");
                            addnotice();
                            getch();
                            break;
                        case 6:
                            system("CLS");
                            shownotice();
                            getch();
                            break;
                        case 7:
                            system("CLS");
                            removenotice();
                            getch();
                            break;
                        case 8:
                            system("CLS");
                            drawgraph();
                            getch();
                            break;
                        default :
                            system("CLS");
                            printf("\n\nInvalid choice");
                            getch();
                            break;
                        }
                    }
                }
                getch();
                break;
            case 2:
                system("CLS");
                printf("\n\n\n\t\t\t\t\t\tStudent Login\n");
                printf("_______________________________________________________________________________________________________________________\n");
                printf("_______________________________________________________________________________________________________________________\n");
                int slog;
                char roll[100];
                printf("Enter roll :\n");
                fflush(stdin);
                gets(roll);
                slog=student_login(roll);
                if(slog!=0)
                {
                    while(1)
                    {
                        system("CLS");
                        printf("\n\n\n\t\t\t\t\t\tStudent Portal\n");
                        printf("_______________________________________________________________________________________________________________________\n");
                        printf("_______________________________________________________________________________________________________________________\n");
                        printf("1. Show Classes\n");
                        printf("2. Logout\n");
                        int choice5;
                        printf("\n\nEnter your choice :\n");
                        scanf("%d",&choice5);
                        if(choice5==2)
                        {
                            break;
                        }
                        switch(choice5)
                        {
                        case 1:
                            system("CLS");
                            int cl;
                            cl=showclasses(roll);
                            if(cl!=0)
                            {
                                while(1)
                                {
                                    system("CLS");
                                    printf("\n\n\n\t\t\t\t\t\tClassroom\n");
                                    printf("_______________________________________________________________________________________________________________________\n");
                                    printf("_______________________________________________________________________________________________________________________\n");
                                    printf("1. Show Classmates\n");
                                    printf("2. Show Notices\n");
                                    printf("3. Show Marks\n");
                                    printf("4. Marks Statistics\n");
                                    printf("5. Logout\n");
                                    int choice6;
                                    printf("\n\nEnter your choice :\n");
                                    scanf("%d",&choice6);
                                    if(choice6==5)
                                    {
                                        break;
                                    }
                                    switch(choice6)
                                    {
                                    case 1:
                                        system("CLS");
                                        showclassmates(roll);
                                        getch();
                                        break;
                                    case 2:
                                        system("CLS");
                                        shownotice_students();
                                        getch();
                                        break;
                                    case 3:
                                        system("CLS");
                                        showmark(roll);
                                        getch();
                                        break;
                                    case 4:
                                        system("CLS");
                                        drawmarkst(roll);
                                        getch();
                                        break;
                                    default :
                                        system("CLS");
                                        printf("\n\nInvalid choice\n");
                                        getch();
                                        break;
                                    }
                                }
                            }
                            getch();
                            break;
//                        case 2:
//                            system("CLS");
//                            return 0;
                        default :
                            system("CLS");
                            printf("\n\nInvalid choice\n");
                            getch();
                            break;
                        }
                    }
                }
                getch();
                break;
            case 3:
                break;
            default :
                system("CLS");
                printf("\n\nInvalid choice");
                getch();
                break;
            }
            break;
        case 3:
            return 0;
        default :
            system("CLS");
            printf("\n\nInvalid choice");
            getch();
            break;
        }
    }
}
