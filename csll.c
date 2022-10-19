#include <stdio.h>
#include <stdbool.h>

int head_node_updated_insertion=0;

struct Student{
    char stud_name[60];
    char reg_num[10];
    int mark1;
    int mark2;
    int mark3;
    int total;
    float average;
    char grade;
};

struct Node{
    struct Student student_data;
    struct Node* next_node;
};

struct Node global_head;
struct Node global_current_last;

struct Node global_list1_head;
struct Node global_list1_current_last;

void insert_node(struct Node current_last, bool back){
    struct Student student;
    printf("Enter student name : ");
    scanf("%d",&student.stud_name);
    printf("Enter regisration number : ");
    scanf("%d",&student.reg_num);
    
    printf("Enter marks 1 : ");
    scanf("%d",&student.mark1);
    printf("Enter marks 2 : ");
    scanf("%d",&student.mark2);
    printf("Enter marks 3 : ");
    scanf("%d",&student.mark3);
    

    student.total=student.mark1+student.mark2+student.mark3;
    student.average=student.total/3.0;

    if (student.average>=91 && student.average<=100) 
        student.grade='S';
    else if (student.average>=81)
        student.grade='A';
    else if (student.average>=71)
        student.grade='B';
    else if (student.average>=61)
        student.grade='C';
    else if (student.average>=51)
        student.grade='D';
    else if (student.average>=41)
        student.grade='E';
    else student.grade = 'F';                    

    struct Node newNode;
    newNode.student_data=student;
    
    if (back){     
        
        newNode.next_node=NULL;
        current_last.next_node=&newNode;
        global_current_last=newNode;
    }

    else {        
        newNode.next_node=&global_head;
        head_node_updated_insertion++;
    }

    if (student.mark1+student.mark2+student.mark3>270){

    }



}

int main(){

    global_current_last=global_head;

    int choice;
    char menu[100];
    printf(menu);
    scanf("%c",&choice);
    for (int i=0;;i++){
        switch (choice)
        {
        case 1:
            bool back = false;
            if (i%2==0){
                back=true;
            }
            insert_node(global_current_last,back);
            break;
        
        default:
            break;
        }
    }
}


