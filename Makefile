CXX = g++  -Werror=vla
CXXFLAGS = -std=c++14 
OBJECTS = chamber.o character.o enemy.o floor.o player.o stair.o item.o main.o 
DEPENDS = ${OBJECTS:.o=.d}
EXEC = cc3k

${EXEC} : ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

clean :
	rm ${DEPENDS} ${OBJECTS} ${EXEC}

-include ${DEPENDS} # reads the .d files and reruns dependencies
