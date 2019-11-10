FAGS = -Wall -std=c++14
BOSS = main.cc
MINIONS = sequence.cc part2.cc
WORKER = exe

main: $(BOSS) $(MINIONS)
	g++ $(FAGS) $(BOSS) $(MINIONS) -o $(WORKER)

clean:
	rm $(WORKER)
