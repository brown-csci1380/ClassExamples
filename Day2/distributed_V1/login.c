#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h>

char login (char * userName, char * passwd){
	
	//sleep(1);
	if(strcmp(userName,"tbenson")==0){
		printf("login: user Authenticated\n");
		return 1;
	}else{
		printf("login: user Authenticated FAILED!!!!! \n");
		return 0;
	}
}


void getLoginHelper (){
	char userName[10];
	char passwd[10];
	char buffer[20];
	char Wall[100];
	int sockfd, bindResults, clientAddrLen, port;
	struct sockaddr_in serverAddr, clientAddr;
	
	port = 22222;
	memset(&serverAddr, 0, sizeof(serverAddr)); 
	memset(&clientAddr, 0, sizeof(clientAddr)); 
	clientAddrLen = sizeof(clientAddr);
	
	serverAddr.sin_family    = AF_INET; 
	serverAddr.sin_addr.s_addr = INADDR_ANY; 
	serverAddr.sin_port = htons(port); 
	
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	if(sockfd < 0){
		perror ("Failed to Create the Socket");
	}
	
	//listen for connections	
	bindResults = bind(sockfd, (const struct sockaddr *)&serverAddr, sizeof(serverAddr));
	if(bindResults < 0){
		perror ("Failed to Bind to the Socket");
	}
	
	while(1){
		//return the data from getWall Over connection
    	recvfrom(sockfd, (char *)buffer, sizeof(buffer), MSG_WAITALL, 
		( struct sockaddr *) &clientAddr, (socklen_t *) &clientAddrLen); 
				 
		strncpy(userName, buffer, 10);
		strncpy(passwd, buffer+ 10, 10);
		printf("getLoginHelper: Received Remote msg for username: '%s' passwd: '%s'\n", userName,passwd);
		char loginResult = login(userName,passwd);
		
		//send results back
		sendto(sockfd, (const char *)&loginResult, sizeof(loginResult),0, 
		(const struct sockaddr *)&clientAddr,clientAddrLen);
		printf("getLoginHelper: Returned Remote msg isValid: '%d'\n", loginResult);		 
		
	}
}
int main (){
	getLoginHelper();
}