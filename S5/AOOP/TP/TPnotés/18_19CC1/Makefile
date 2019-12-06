FAGS = -Wpedantic -Wall -std=c++14
BOSS = main.cc
MINIONS = NumEpisode.cc Visionnage.cc
WORKER = exe

main: $(BOSS) $(MINIONS)
	g++ $(FAGS) $(BOSS) $(MINIONS) -o $(WORKER)

clean:
	rm $(WORKER)
