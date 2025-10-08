CC = gcc
CFLAGS = -Wall

ifeq ($(OS),Windows_NT)
	EXEEXT = .exe
else
	EXEEXT =
endif

all: circuit_simulator$(EXEEXT) logic_simulator$(EXEEXT)

circuit_simulator$(EXEEXT): src/logic_simulator_circuit.c src/gates.c
	$(CC) $(CFLAGS) src/logic_simulator_circuit.c src/gates.c -o circuit_simulator$(EXEEXT)

logic_simulator$(EXEEXT): src/logic_simulator.c src/gates.c
	$(CC) $(CFLAGS) src/logic_simulator.c src/gates.c -o logic_simulator$(EXEEXT)

clean:
	$(RM) circuit_simulator$(EXEEXT) logic_simulator$(EXEEXT)