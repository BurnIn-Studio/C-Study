#include <stdio.h>
#include <string.h>

void get_input()
{
	char buf[100], buf2[100];
    printf("input string: ");
    scanf("%s",buf);
    strcpy(buf2, buf);
    printf("%s\n",buf2);
}

void strlen_array()
{
	char buf[100];
	printf("input string: ");
    scanf("%s",buf);
    
    int i = 0;
    while (buf[i] != '\0')
    {
        i++;
    }
    
    printf("%d\n",i);
}

void get_input_array()
{
	char buf[100], buf2[100];
    printf("input string: ");
    scanf("%s",buf);
    printf("input second String: ");
    scanf("%s",buf2);
    strcat(buf, buf2);
    
    printf("%s\n",buf);
}

void compare_strings()
{
	
	int stat;
	
	char buf[100], buf2[100];
    printf("input string: ");
    scanf("%s",buf);
    printf("input second String: ");
    scanf("%s",buf2);
	
    if (strcmp(buf, buf2) == 0)
    {
        printf("Success\n");
    }
    else
    {
        printf("Failed\n");
    }

}

void main(){
	
	while(1){
	
	int num;
	
	printf("Welcome to my exam program\n");
	
	printf("Select your menu!\n");
	
	printf("1.Copy\n 2.strlen\n 3.appendstr\n 4.compareString\n");
	
	scanf("%d", &num);
	
	if(num == 1){
		get_input();
	}else if (num == 2){
		strlen_array();
	}else if(num == 3){
		get_input_array();
	}else if(num == 4){
		compare_strings();
	}else{
		printf("please enter valid number!");
	}
}
	
}
