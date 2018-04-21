#include "basic.h"

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>

int sock_set_nonblock(int sock)
{
	int ret = fcntl(sock, F_GETFL);
	if (ret < 0)
		return ret;

	return fcntl(sock, F_SETFL, ret | O_NONBLOCK);
}

int sock_set_reuse(int sock)
{
	int so_reuseaddr = 1;
	return setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &so_reuseaddr, sizeof(so_reuseaddr));
}
