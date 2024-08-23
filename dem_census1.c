#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PEOPLE 100
#define NAME_LENGTH 20

//结构体，定义姓名，年龄，性别
typedef struct 
{
    char name[NAME_LENGTH];
    int age;
    char gender;   //M代表Male,F代表Female
} Person;


int count = 0;
void addPerson(Person *people, int *count);
void displayPerson(const Person *people, int count);
void modifyPerson(Person *people, int count);
void deletePerson(Person *people, int *count);

//主函数
int main() {
    Person people[MAX_PEOPLE];
    int count = 0;
    int choice;
    do
    {
        printf("------------人口普查系统------------\n");
        printf("*           1.添加人员信息         *\n");
        printf("*           2.查询人员信息         *\n");
        printf("*           3.修改人员信息         *\n");
        printf("*           4.删除人员信息         *\n");
        printf("*           5.退出系统             *\n");
        printf("------------------------------------\n");
        printf("            选择一个选项： ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            addPerson(people, &count);
            break;
        case 2:
            displayPerson(people, count);
            break;
        case 3:
            modifyPerson(people, count);
            break;
        case 4:
            deletePerson(people, &count);
        case 5:
            printf("退出系统\n");
            break;
        default:
            printf("无效选项，请重试！\n");
        }
    } while (choice != 5);
    return 0;
    
}




//添加人员信息
void addPerson(Person *people, int *count) {
    if (*count >= MAX_PEOPLE)
    {
        printf("已达到最大人数，无法添加更多人员。\n");
        return;
    }

    printf("输入姓名： ");
    scanf("%s", people[*count].name);
    printf("输入年龄： ");
    scanf("%d", &people[*count].age);
    getchar();  //%c会读取换行符，需要添加getchar()
    while (1)
    {   
        printf("请输入性别(M for Male, F for Female):  ");
        scanf("%c", &people[*count].gender);

        if (people[*count].gender == 'M' || people[*count].gender == 'F')
        {
            break;
        } else {
            printf("输入异常，请重新输入。\n");
        }
        
        
    }
    
    printf("添加成功！！\n\n");

    (*count)++;

    
}

//查询人员信息
void displayPerson(const Person *people, int count) {
    if(count == 0) {
        printf("暂无人员信息。\n\n");
        return;
    }
    printf("人口普查信息：\n");
    for (int i = 0; i < count; i++)
    {
        printf("序号： %d   姓名： %s   年龄： %d   性别: %c\n\n", i + 1, people[i].name, people[i].age, people[i].gender);
    }
    
}

//修改人员信息
void modifyPerson(Person *people, int count) {
    int number;
    printf("选择要修改人员的序号： ");
    scanf("%d", &number);

    if ((number < 1) || (number > count))
    {
        printf("%d号修改异常。\n", number);
        return;
    }


    number = (number - 1);
    count = number;
    printf("请重新填入姓名： ");
    scanf("%s", people[count].name);  //字符数组
    printf("请重新填入年龄： ");
    scanf("%d", &people[count].age);
    getchar();
    while (1)
    {   
        printf("请重新输入性别(M for Male, F for Female):  ");
        scanf("%c", &people[count].gender);

        if (people[count].gender == 'M' || people[count].gender == 'F')
        {
            break;
        } else {
            printf("输入异常，请重新输入。\n");
        }
        
        
    }
    printf("修改完成！！\n\n");

}

//删除人员信息
void deletePerson(Person *people, int *count){
    int number;
    printf("选择删除人员的序号： ");
    scanf("%d", &number);
    if ((number > *count) || (number < 1))
    {
        printf("输入序号异常。\n");
        return;
    }

    number = (number-1);
    for (int i = number; i < *count - 1; i++)
    {
        *people[i].name = *people[i + 1].name;
        people[i].age = people[i + 1].age;
        people[i].gender = people[i + 1].gender;
        
    }

    (*count)--;
    printf("删除完成。\n\n");

    
}


