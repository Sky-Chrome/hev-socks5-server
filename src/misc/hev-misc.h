/*
 ============================================================================
 Name        : hev-misc.h
 Authors     : Heiher <r@hev.cc>
 Copyright   : Copyright (c) 2022 - 2024 everyone.
 Description : Misc
 ============================================================================
 */

#ifndef __HEV_MISC_H__
#define __HEV_MISC_H__

#include <netinet/in.h>
#include <netinet/tcp.h> // For TCP related constants


int hev_netaddr_resolve (struct sockaddr_in6 *daddr, const char *addr,
                         const char *port);

void run_as_daemon (const char *pid_file);
int set_limit_nofile (int limit_nofile);

int set_sock_bind (int fd, const char *iface);
int set_sock_ttl(int fd, int ttl);
int set_sock_sack(int fd, int enable);
int set_sock_dontfrag(int fd, int enable);
int set_sock_timestamps(int fd, int enable);
int set_sock_mss(int fd, int mss_value);
int set_sock_ecn(int fd, int enable);
int set_sock_sndbufforce(int fd, int size);
int set_sock_rcvbufforce(int fd, int size);
int set_sock_mark (int fd, unsigned int mark);

#endif /* __HEV_MISC_H__ */
