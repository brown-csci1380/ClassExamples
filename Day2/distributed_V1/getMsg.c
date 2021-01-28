#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h>

void getInspirationalMsg(char * userName,char * buffer){
	printf("getInspirationalMsg: getting msg of the day\n");
	char * randomData = "This the song that never ends....";
	//sleep(1);
	strcpy(buffer, randomData);
}

void getInspirationalMsgHelper (){
	char userName[10];
	char Wall[100];
	int sockfd, bindResults, clientAddrLen, port;
	struct sockaddr_in serverAddr, clientAddr;
	
	port = 44444;
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
    	recvfrom(sockfd, (char *)userName, sizeof(userName), MSG_WAITALL, 
		( struct sockaddr *) &clientAddr, (socklen_t *) &clientAddrLen); 
				 
		
		printf ("getInspirationalMsgHelper: received request for msg %s\n",userName);
		 getInspirationalMsg(userName,Wall);
				 
		//send results back
		sendto(sockfd, (const char *)Wall, sizeof(Wall),0, 
		(const struct sockaddr *)&clientAddr,clientAddrLen);
		printf ("getInspirationalMsgHelper: responded with msg %s\n",Wall);
	}
}

int main (){
	getInspirationalMsgHelper();
}
