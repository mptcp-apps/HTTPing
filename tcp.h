/* Released under AGPL v3 with exception for the OpenSSL library. See license.txt */
#include <linux/types.h>

#ifndef IPPROTO_MPTCP
#define IPPROTO_MPTCP 262
#endif

#ifndef SOL_MPTCP
#define SOL_MPTCP 284
#endif

#ifndef MPTCP_INFO
struct mptcp_info {
	__u8	mptcpi_subflows;
	__u8	mptcpi_add_addr_signal;
	__u8	mptcpi_add_addr_accepted;
	__u8	mptcpi_subflows_max;
	__u8	mptcpi_add_addr_signal_max;
	__u8	mptcpi_add_addr_accepted_max;
	__u32	mptcpi_flags;
	__u32	mptcpi_token;
	__u64	mptcpi_write_seq;
	__u64	mptcpi_snd_una;
	__u64	mptcpi_rcv_nxt;
	__u8	mptcpi_local_addr_used;
	__u8	mptcpi_local_addr_max;
	__u8	mptcpi_csum_enabled;
};


#define MPTCP_INFO		1
#define MPTCP_TCPINFO		2
#define MPTCP_SUBFLOW_ADDRS	3
#endif




int create_socket(struct sockaddr *bind_to, struct addrinfo *ai, int recv_buffer_size, int tx_buffer_size, int max_mtu, char use_no_delay, int priority, int tos, char use_mptcp);
int connect_to(int fd, struct addrinfo *ai, double timeout, char *tfo, char *msg, int msg_len, char *msg_accepted);
void failure_close(int fd);
