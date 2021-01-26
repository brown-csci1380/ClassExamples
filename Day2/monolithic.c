#include <unistd.h>
#include <string.h>
#include <time.h>
#include <stdio.h>
int login (char * userName, char * passwd){
	
	sleep(1);
	if(strcmp(userName,"tbenson")){
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
	sleep(1);
	return randomData;
}

void app(){
	time_t startTime, endTime; 
	time ( &startTime );
	char userName [10];
	char passwd[11];
	if(login(userName,passwd)){
		getInspirationalMsg(userName);
	}
	time ( &endTime );
	printf("Runtime: %ld seconds\n", endTime-startTime);
}



int main (){
	app();
}






