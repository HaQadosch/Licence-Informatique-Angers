FAGS = -Wall -std=c++14
BOSS = main.cc
MINIONS = ensemble.cc ensembleTableau.cc ensembleVector.cc 
WORKER = exe

main: $(BOSS) $(MINIONS)
	g++ $(FAGS) $(BOSS) $(MINIONS) -o $(WORKER)

clean:
	rm $(WORKER)
