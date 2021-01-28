#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h>

char login (char * userName, char * passwd){
	
	sleep(1);
	if(strcmp(userName,"tbenson")==0){
		printf("login: user Authenticated\n");
		return 1;
	}else{
		printf("login: user Authenticated FAILED!!!!! \n");
		return 0;
	}
}



int main (){
	login();
}