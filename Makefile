all: Test3.o IRProviderConst.o
		g++ -o all Test3.o IRProviderConst.o
Test3.o: Test3.cpp DiffusionCEV.h DiffusionCIR.h DiffusionGBM.h DiffusionLipton.h DiffusionOU.h IRProviderConst.h VanillaOptions.h MCOptionPricer1D.hpp
		g++ -c -o Test3.o Test3.cpp
IRProviderConst.o: IRProviderConst.cpp IRProviderConst.h
		g++ -c -o IRProviderConst.o IRProviderConst.cpp
clean:
		rm -rf *.o *.h.gch *.hpp.gch
