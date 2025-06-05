CPP = g++
CFLAGS = -Wall -Wextra -O2
TARGET = main
SOURCES = src/main.cpp src/lse.cpp
CLEAR = clear

${TARGET}: ${OBJECTS}
	${CPP} ${CFLAGS} -o ${TARGET} ${SOURCES}

run: ${TARGET}
	./${TARGET}

clean:
	rm -f *.o main
	${CLEAR}
