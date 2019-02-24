#ifndef SERVER_API_H
#define SERVER_API_H

int setup_server_socket(int portno);
int accept_client_connection(int sockfd);

#endif
