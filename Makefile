CXX = g++-5
CXXFLAGS = -std=c++14 -Wall -MMD
EXEC = cc3k
OBJECTS = gold.o ngold.o sgold.o mgold.o dgold.o potion.o rh.o ph.o bd.o wd.o wa.o ba.o npc.o elf.o orc.o halfling.o merchant.o dragon.o human.o dwarf.o shade.o troll.o vampire.o drow.o goblin.o player.o controller.o textdisplay.o  floor.o cell.o game.o main.o view.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}

