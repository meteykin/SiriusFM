all: Test2.o IRProviderConst.o
		g++ -o all Test2.o IRProviderConst.o
Test1.o: Test2.cpp DiffusionCEV.h DiffusionCIR.h DiffusionGBM.h DiffusionLipton.h DiffusionOU.h MCEngine1D.hpp VanillaOptions.h
		g++ -c -o Test2.o Test2.cpp
IRProviderConst.o: IRProviderConst.cpp IRProviderConst.h
		g++ -c -o IRProviderConst.o IRProviderConst.cpp
clean:
		rm -rf *.o *.h.gch *.hpp.gch
