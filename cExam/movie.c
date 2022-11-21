#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _movie{
    char title[100];
    char director[100];
    char actor[100];
    int year;
    int watcher;
} movie;

typedef struct _config{
    int mode;
} config;

struct _movie sortMovie[100];

int sort(int param, char *option, char* optionp[]);
int inputInfo();
int write_config(char* path, char *mode);
int executeProg();

int main(int argc, char* argv[]){    
        if(argc < 2){
		    printf("MovieExam v1.0.0 : no command specified\nTry \'movie -h\' for more information.\n");
	    }else{
            sort(argc, argv[1], argv);
	}
	return 0;
}

int sort(int param, char *option, char* optionp[]){

	if(strncmp(option, "-h",sizeof(option))==0){
		printf("movie v1.0.0\n\nCommands\n\n-h : show command option information\n\n-v : show movie Version\n\n-r : Run program\n\n");
		printf("-m [0,1,2] : select mode to run \n0 : Register movie \n1 : sort by desc \n2: sort by asc\n\n");
	}else if(strncmp(option,"-v",sizeof(option))==0){
		printf("\nmovie Version 1.0.0 Develop by Archan All right Reversed\n\n");
	}else if(strncmp(option,"-m",sizeof(option))==0){
		if(param == 3){
            if(strncmp(optionp[2],"0",sizeof(optionp[2])) || strncmp(optionp[2],"1",sizeof(optionp[2])) || strncmp(optionp[2],"2",sizeof(optionp[2]))){
                write_config("config.conf", optionp[2]);
            }else{
                printf("Invalid option\n");
            }
		}else{
			printf("\nmoive v1.0.0 : Option \"-m\" invalid argument\n\nPlease check movie -h\n\n");
		}
	}else if (strncmp(option, "-r",sizeof(option))==0){
        executeProg();
    }else{
		printf("Not valid Option\n");
	}

	return 0;
}

int inputInfo(){
    FILE *fp;
    int num;
    fp = fopen("movie.txt","w");

    if(fp == NULL){
        printf("File open error\n");
        return -1;
    }
    printf("How much movie do you want to input? : ");
    scanf("%d", &num);
    // loop while num is same with 0
    for(int i=0; i<num; i++){
        movie *m;
        m = (movie*)malloc(sizeof(movie));
        printf("Title : ");
        scanf("%s",m->title);
        printf("Director : ");
        scanf("%s",m->director);
        printf("Actor : ");
        scanf("%s",m->actor);
        printf("Year : ");
        scanf("%d",&m->year);
        printf("Watcher : ");
        scanf("%d",&m->watcher);
        fprintf(fp,"%s %s %s %d %d\n",m->title,m->director,m->actor,m->year,m->watcher);
        printf("Next info\n");
        free(m);
    }
    fclose(fp);
    printf("Successfully create movie.txt\n");

    return 0;
}

int write_config(char* path, char *mode){
    FILE* stream = NULL;
    stream = fopen(path, "w");

    if(stream == NULL){
        printf("Error : Can't create file\n");
        return 0;
    }else{
        printf("Successfully set Conf file\n");
        fprintf(stream, "%s\n", mode);
    }
    fclose(stream);
    return 0;
}

int executeProg(){
    FILE* configStream = NULL;
    FILE* movieStream = NULL;

    configStream = fopen("config.conf", "r");
    if(configStream == NULL){
         printf("Error : Can't find config file\n");
         return 0;
    }
    
    config *c;
    c = (config*)malloc(sizeof(config));

    fscanf(configStream, "%d\n", &c->mode);
    printf("Execute mode is %d\n", c->mode);
    fclose(configStream);

    if(c->mode == 0){
        inputInfo();
    }else if(c->mode ==1){
        movieStream = fopen("movie.txt", "r");
        if(movieStream == NULL){
            printf("Error : Can't find movie file\n");
            return 0;
        }
        int i = 0;
        while(!feof(movieStream)){
            fscanf(movieStream, "%s %s %s %d %d\n", sortMovie[i].title, sortMovie[i].director, sortMovie[i].actor, &sortMovie[i].year, &sortMovie[i].watcher);
            i++;
        }
        for(int j=0; j<i; j++){
            for(int k=j+1; k<i; k++){
                if(sortMovie[j].watcher > sortMovie[k].watcher){
                    movie temp;
                    temp = sortMovie[j];
                    sortMovie[j] = sortMovie[k];
                    sortMovie[k] = temp;
                }
            }
        }
        for(int j=0; j<i; j++){
            printf("%s %s %s %d %d\n", sortMovie[j].title, sortMovie[j].director, sortMovie[j].actor, sortMovie[j].year, sortMovie[j].watcher);
        }
        fclose(movieStream);
    }else if(c->mode == 2){
        movieStream = fopen("movie.txt", "r");
        if(movieStream == NULL){
            printf("Error : Can't find movie file\n");
            return 0;
        }
        int i = 0;
        while(!feof(movieStream)){
            fscanf(movieStream, "%s %s %s %d %d\n", sortMovie[i].title, sortMovie[i].director, sortMovie[i].actor, &sortMovie[i].year, &sortMovie[i].watcher);
            i++;
        }
        for(int j=0; j<i; j++){
            for(int k=0; k<i; k++){
                if(sortMovie[j].watcher > sortMovie[k].watcher){
                    movie temp;
                    temp = sortMovie[j];
                    sortMovie[j] = sortMovie[k];
                    sortMovie[k] = temp;
                }
            }
        }
        for(int j=0; j<i; j++){
            printf("%s %s %s %d %d\n", sortMovie[j].title, sortMovie[j].director, sortMovie[j].actor, sortMovie[j].year, sortMovie[j].watcher);
        }
        fclose(movieStream);
    }
    free(c);
    return 0;

};