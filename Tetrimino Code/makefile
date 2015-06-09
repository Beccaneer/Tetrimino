CXX = g++
CXXFLAGS = -L/usr/X11R6/lib -lX11 -g -Wall -MMD
MAKEFILE_NAME = ${firstword ${MAKEFILE_LIST}}

OBJECTS = main.o Display.o GridClass.o window.o TetriminoClass.o TetriminoConstructors.o CommandInterpreter.o CommandInterpreterHelper.o Scoring.o NextBlock.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = quadris

.PHONY : clean

${EXEC} : ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

${OBJECTS} : ${MAKEFILE_NAME}

-include ${DEPENDS}

clean :
	rm -f ${DEPENDS} ${OBJECTS} ${EXEC}
