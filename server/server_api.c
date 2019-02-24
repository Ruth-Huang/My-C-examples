#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <errno.h>

int setup_server_socket(int portno)
{
	int sockfd;
	struct sockaddr_in serv_addr;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0)
	{
		perror("Could not create socket");
		exit(1);
	}

	bzero((char *) &serv_addr, sizeof(serv_addr));

        serv_addr.sin_family = AF_INET;
        serv_addr.sin_addr.s_addr = INADDR_ANY;
        serv_addr.sin_port = htons(portno);

	if(bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        {
                perror("Binding socket");
                exit(1);
        }

        listen(sockfd, 5);

        printf("listening on port %i...\n", portno);

	return sockfd;
}

int accept_client_connection(int sockfd)
{
	int newsockfd, clilen;
	struct sockaddr_in cli_addr;

	clilen = sizeof(cli_addr);
	newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *)&clilen);

	if(newsockfd < 0)
	{
		perror("Accepting connection");
		exit(1);
	}

	return newsockfd;
}

