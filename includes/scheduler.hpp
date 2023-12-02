#pragma once

#include <stdlib.h>
#include <exception>
#include <time.h>
#include <unistd.h>
#include <sys/msg.h>
#include <queue>
#include <sys/time.h>
#include <csignal>
#include <fstream>
#include <thread>
#include <chrono>
#include <iostream>
using namespace std;

#include "ChildProcess.hpp"
#include "ParentProcess.hpp"

#define PROCESS_NUM 10

enum msg_type {
	TYPE_RUN_CPU_PROCESS,
	TYPE_RUN_IO_PROCESS,
	TYPE_CHILD_IO_INTERRUPT,
	TYPE_CHILD_IO_END,
	TYPE_CHILD_READY,
	TYPE_CHILD_WAITING,
	TYPE_CHILD_END,
	TYPE_CHILD_INFO,
	TYPE_TERMINATE_CHILD,
	TYPE_KILL_PROCESS
};

enum msg_id {
	MSG_ID_CPU,
	MSG_ID_IO,
	MSG_ID_LOG,
	MSG_ID_CHILDS
};
	
typedef struct {
	long		mtype;
	int			send_pid;
	msg_type	type;
} msg_load;

void printInfo(void);
