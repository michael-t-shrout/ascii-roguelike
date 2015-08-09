OBJECTS = Entity.o Item.o Consumable.o Equipment.o Armor.o Weapon.o Character.o Creature.o Player.o XMLSerializable.o DungeonLevel.o Tile.o parser.o GenericFactory.o Tools.o
HEADERS = Entity.h Item.h Consumable.h Equipment.h Armor.h Weapon.h Character.h Creature.h Player.h XMLSerializable.h DungeonLevel.h Tile.h GenericFactory.h EntityVector.h parser.h Tools.h

prog1: $(OBJECTS) main.o
	g++ $^ -o prog1

la5: $(OBJECTS) la5.o
	g++ $^ -o la5
xml: $(OBJECTS) xml.o
	g++ --std=c++0x $^ -o xml
prog2: $(OBJECTS) prog2.o
	g++ --std=c++0x $^ -o prog2
prog3: $(OBJECTS) prog3.o
	g++ --std=c++0x $^ -o prog3
prog4: $(OBJECTS) prog4.o
	g++ --std=c++0x $^ -lncurses -o prog4
game: $(OBJECTS) prog4.o
	g++ --std=c++0x $^ -lncurses -o game

%.o: %.cpp $(HEADERS)
	g++ --std=c++0x -c $< -o $@

clean:
	rm -f *.o prog1 la5 xml prog2
