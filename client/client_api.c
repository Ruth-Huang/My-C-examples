#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <errno.h>

int connect_server(char *ipaddr, int port_num)
{
  int sockfd;
  struct sockaddr_in serv_addr;

  if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
	perror("Could not create socket");
	exit(1);
  }

  memset(&serv_addr, '0', sizeof(serv_addr));

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(port_num);

  if(inet_pton(AF_INET, ipaddr, &serv_addr.sin_addr)<=0){
        perror("inet_pton error");
        exit(1);
  }

  if( connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0){
       perror("Connection Failed");
       exit(1);
  }

  return sockfd;
}
