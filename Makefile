CPP = g++
CFLAGS = -Wall -Wextra -O2
TARGET = main
SOURCES = src/main.cpp src/hash_map.cpp

${TARGET}: ${SOURCES}
	${CPP} ${CFLAGS} -o ${TARGET} ${SOURCES}

run: ${TARGET}
	./${TARGET}

clean:
	rm -f ${TARGET} *.o
