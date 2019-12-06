FAGS = -Wpedantic -Wall -std=c++14
BOSS = main.cpp
MINIONS = graphe.cpp
WORKER = exe

main: $(BOSS) $(MINIONS)
	g++ $(FAGS) $(BOSS) $(MINIONS) -o $(WORKER)

clean:
	rm $(WORKER)
