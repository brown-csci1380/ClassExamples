#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h>


// void app(){
// 	char userName [10] ="tbenson";
// 	char passwd[11] ="cs1380";
// 	if(login(userName,passwd)){
// 		getWall(userName);
// 	}
// }


void remoteCallgetWall(char * userName){
	char buffer[20];
	char Wall[100];
	int sockfd, bindResults, clientAddrLen, port,remotePort;
	struct sockaddr_in serverAddr, clientAddr;
	
	port = 55555;
	remotePort = 44444;
	memset(&serverAddr, 0, sizeof(serverAddr)); 
	memset(&clientAddr, 0, sizeof(clientAddr)); 
	clientAddrLen = sizeof(clientAddr);
	
	serverAddr.sin_family    = AF_INET; 
	serverAddr.sin_addr.s_addr = INADDR_ANY; 
	serverAddr.sin_port = htons(port); 
	
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	if(sockfd < 0){
		perror ("Failed to Create the Socket");
		exit(1);
	}
	
	//listen for connections	
	bindResults = bind(sockfd, (const struct sockaddr *)&serverAddr, sizeof(serverAddr));
	if(bindResults < 0){
		perror ("Failed to Bind to the Socket");
		exit(1);
	}
	
	clientAddr.sin_family    = AF_INET; 
	clientAddr.sin_addr.s_addr = INADDR_ANY; 
	clientAddr.sin_port = htons(remotePort); 
	strncpy(buffer,userName, 10);
	
	
	sendto(sockfd, (const char *)buffer, sizeof(buffer),0, 
	(const struct sockaddr *)&clientAddr,clientAddrLen);
	
	recvfrom(sockfd, (char *)buffer, sizeof(buffer), MSG_WAITALL, 
	( struct sockaddr *) &clientAddr, (socklen_t *) &clientAddrLen); 

	close(sockfd);
	printf ("return value: %s\n",buffer);
	
}
int remoteCallLogin(char * userName, char * passwd){

	char buffer[20];
	char Wall[100];
	int sockfd, bindResults, clientAddrLen, port,remotePort;
	struct sockaddr_in serverAddr, clientAddr;
	
	port = 55555;
	remotePort = 22222;
	memset(&serverAddr, 0, sizeof(serverAddr)); 
	memset(&clientAddr, 0, sizeof(clientAddr)); 
	clientAddrLen = sizeof(clientAddr);
	
	serverAddr.sin_family    = AF_INET; 
	serverAddr.sin_addr.s_addr = INADDR_ANY; 
	
	
	serverAddr.sin_port = htons(port); 
	
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	if(sockfd < 0){
		perror ("Failed to Create the Socket");
		exit(1);
	}
	
	//listen for connections	
	bindResults = bind(sockfd, (const struct sockaddr *)&serverAddr, sizeof(serverAddr));
	if(bindResults < 0){
		perror ("Failed to Bind to the Socket");
		exit(1);
	}
	
	clientAddr.sin_family    = AF_INET; 
	clientAddr.sin_addr.s_addr = INADDR_ANY; 
	clientAddr.sin_port = htons(remotePort); fprintf(stderr,"send to local service\n");	
	strncpy(buffer,userName, 10);
	strncpy(buffer+10,passwd, 10);
	

	sendto(sockfd, (const char *)buffer, sizeof(buffer),0, 
	(const struct sockaddr *)&clientAddr,clientAddrLen);
	recvfrom(sockfd, (char *)buffer, sizeof(buffer), MSG_WAITALL, 
	( struct sockaddr *) &clientAddr, (socklen_t *) &clientAddrLen); 
	fprintf (stderr,"return value: %d\n",buffer[0]);
	close(sockfd);
	return (int)buffer[0];
}

void app(){
	struct timeval stop, start;
	gettimeofday(&start, NULL);
	char userName [10] ="tbenson";
	char passwd[11] ="cs1380";
	if(remoteCallLogin(userName,passwd)){
		remoteCallgetWall(userName);
	}
	gettimeofday(&stop, NULL);
	printf("Runtime %lu us\n", (stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec); 
	
}


int main (){
	app();
}
