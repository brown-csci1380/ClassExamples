#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h>

char * getInspirationalMsg(char * userName){
	printf("getInspirationalMsg: getting msg of the day\n");
	char * randomData = "This the song that never ends....";
	sleep(1);
	return randomData;
}



int main (){
	getInspirationalMsg();
}
