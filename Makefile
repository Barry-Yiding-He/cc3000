CXX = g++  -Werror=vla
CXXFLAGS = -std=c++14 
OBJECTS = 
DEPENDS = ${OBJECTS:.o=.d}
EXEC = cc3000

${EXEC} : ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

clean :
	rm ${DEPENDS} ${OBJECTS} ${EXEC}

-include ${DEPENDS} # reads the .d files and reruns dependencies
