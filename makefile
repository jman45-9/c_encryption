CC = gcc
DB = gdb
SRCS_DIREC = src/
SRCS := ${wildcard ${SRCS_DIREC}*.c}
BINARY = cEncryption

release:
	@${CC} ${SRCS} -o bin/${BINARY}-release

debug:
	@${CC} -g ${SRCS} -o bin/${BINARY}-debug
