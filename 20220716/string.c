#include <stdio.h>
#include <string.h>

struct tmp{
	char buf[100];
	char buf2[100];
};

void get_input()
{
    struct tmp *tmp;
    tmp = (struct tmp *)malloc(sizeof(struct tmp));
    printf("Enter a string: ");
    scanf("%s", tmp->buf);
    strcpy(tmp->buf2, tmp->buf);
    printf("%s\n", tmp->buf2);
    free(tmp);
}

void strlen_array()
{
	struct tmp *tmp;
	tmp = (struct tmp *)malloc(sizeof(struct tmp));
	printf("input string: ");
    scanf("%s", tmp->buf);
    
    int i = 0;
    while (tmp->buf[i] != '\0')
    {
        i++;
    }
    
    printf("%d\n",i);
    free(tmp);
}

void get_input_array()
{
	struct tmp *tmp;
	tmp = (struct tmp *)malloc(sizeof(struct tmp));
    printf("input string: ");
    scanf("%s",tmp->buf);
    printf("input second String: ");
    scanf("%s",tmp->buf2);
    strcat(tmp->buf, tmp->buf2);
    
    printf("%s\n",tmp->buf);
    free(tmp);
}

void compare_strings()
{
	
	int stat;
	
	struct tmp *tmp;
	tmp = (struct tmp *)malloc(sizeof(struct tmp));
    printf("input string: ");
    scanf("%s",tmp->buf);
    printf("input second String: ");
    scanf("%s",tmp->buf2);
	
    if (strcmp(tmp->buf, tmp->buf2) == 0)
    {
        printf("Success\n");
    }
    else
    {
        printf("Failed\n");
    }
	free(tmp);
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
