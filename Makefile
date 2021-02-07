all: main.o IRProviderConst.o
		g++ -o all main.o IRProviderConst.o
main.o: main.cpp DiffusionCEV.h DiffusionCIR.h DiffusionGBM.h DiffusionLipton.h DiffusionOU.h
		g++ -c -o main.o main.cpp
IRProviderConst.o: IRProviderConst.cpp IRProviderConst.h
		g++ -c -o IRProviderConst.o IRProviderConst.cpp
clean:
		rm -rf *.o *.h.gch
