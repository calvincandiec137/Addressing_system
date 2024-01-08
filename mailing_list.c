#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int enter(void);
int delete(void);
int list(void);
int menu(void);
int free_slot(void);

struct addr
{
    char name[30];
    char m_name[30];
    char l_name[30];
    char flat_house[10];
    char bldg[30];
    char street[40];
    char station[20];
    unsigned long zip;
}addr_info[100];

void ini(void){
for (int t = 0; t < 100; t++)
{
    memset(addr_info[t].name, 0, sizeof(addr_info[t].name));

}

}


int main(void){

    ini();
    printf("-------MAILING LIST------\n\n\n\n\n");

    char choice;
    
    for(;;){
        choice =menu();
    switch (choice)
    {
    case 1:
        enter();
        break;
    case 2:
        delete();
        break;
    case 3:
        list();
        break;
    case 4:
        exit(0);
        break;

    }
}
return 0;
}

int menu(void){
    char s[20];
    int c;

    printf("1.Enter a mail.\n");
    printf("2.Delete a mail.\n");
    printf("3.List mails.\n");
    printf("4.Quit.\n");

   fgets(s, sizeof(s), stdin);

    c=atoi(s);
    return c;

}

int enter(void){
    
    int slot;
   
    slot=free_slot();
    if(slot== -1){
        printf("\nList is full");
    }else{
        printf("Enter the First name:");
        scanf("%s",addr_info[slot].name);
       
        printf("Enter the Middle name:");
        scanf("%s",addr_info[slot].m_name);

        printf("Enter the Last name:");
        scanf("%s",addr_info[slot].l_name);

        printf("Enter the flat or house No. :");
        scanf("%s",addr_info[slot].flat_house);
        
        printf("Enter the name of the building:");
        scanf("%s",addr_info[slot].bldg);
       
        printf("Enter the street name:");
        scanf("%s",addr_info[slot].street);
       

        printf("Enter the station :");
        scanf("%s",addr_info[slot].station);
       

        printf("Enter the Zip code :");
        scanf("%lu", &addr_info[slot].zip);
       
    }
}

   int free_slot(void) {
    for (int i = 0; i < 100; i++) {
        if (addr_info[i].name[0] == '\0') {
            return i; 
        }
    }
    return -1; 
   }

    int delete(void){
        int i;
        printf("Enter the index of the mail :");
        scanf("%d",&i);
        printf("%d",i);
        addr_info[i].name[0]='\0';
    }

/**int list(void){
    printf("The list is as follow:\n");

    for (int i = 0; i < 100; i++)
    {if(addr_info[i].name[0]!='\0'){
        printf("%s ",addr_info[i].name);
        printf("%s ",addr_info[i].m_name);
        printf("%s\n",addr_info[i].l_name);
        printf("%s, ",addr_info[i].flat_house);
        printf("%s\n",addr_info[i].bldg);
        printf("%s, ",addr_info[i].street);
        printf("%s\n",addr_info[i].station);
        printf("%lu\n",addr_info[i].zip);
    }
    }
    printf("\n\n");
    return 1;
}**/

int list(void){
    printf("The list is as follows:\n");

    for (int i = 0; i < 100; i++) {
        if (addr_info[i].name[0] != '\0') {
            printf("Name: %s %s %s\n", addr_info[i].name, addr_info[i].m_name, addr_info[i].l_name);
            printf("Address: %s %s %s %s\n", addr_info[i].flat_house, addr_info[i].bldg, addr_info[i].street, addr_info[i].station);
            printf("ZIP Code: %lu\n", addr_info[i].zip);
        }
    }
    printf("\n\n");
    return 1;
}




