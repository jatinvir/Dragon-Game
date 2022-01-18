CXX = g++
CXXFLAGS = -std=c++14 -Wall -g -MMD
EXEC = cc3k
OBJECTS = main.o cell.o chamber.o gold.o dragon.o enemy.o baseStats.o potionbox.o floor.o human.o player.o shade.o randomMoveOneBlock.o randomMoveZeroBlock.o potion.o potionBA.o potionBD.o potionWA.o potionWD.o concreteCreator.o drow.o vampire.o troll.o goblin.o dwarf.o orcs.o elf.o halfling.o merchant.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
