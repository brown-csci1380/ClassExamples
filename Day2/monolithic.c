#include <unistd.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <stdio.h>
int login (char * userName, char * passwd){
	
	//sleep(1);
	if(strcmp(userName,"tbenson")==0){
		printf("login: user Authenticated\n");
		return 1;
	}else{
		printf("login: user Authenticated FAILED!!!!! \n");
		return 0;
	}
}


char * getInspirationalMsg(char * userName){
	printf("getInspirationalMsg: getting msg of the day\n");
	char * randomData = "This the song that never ends....";
	//sleep(1);
	return randomData;
}

void app(){
	struct timeval stop, start;
	gettimeofday(&start, NULL);
	char userName [10] ="tbenson";
	char passwd[11] ="cs1380";
	if(login(userName,passwd)){
		getInspirationalMsg(userName);
	}
	gettimeofday(&stop, NULL);
	printf("Runtime %lu us\n", (stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec); 
	
}



int main (){
	app();
}






