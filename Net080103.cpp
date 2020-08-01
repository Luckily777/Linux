//Makefile

.PHONY:clean all

TARGET = svr cli
CC = gcc
FLAGS = -g - lpthread

all : $(TARGET)

svr : tcp_svr.o public.o
$(CC) - o $@ $ ^ $(FLAGS)

cli : tcp_cli.o public.o
$(CC) - o $@ $ ^ $(FLAGS)

% .o : % .c
$(CC) - c $ ^ $(FLAGS)

clean rm - rf * .o $(TARET)


