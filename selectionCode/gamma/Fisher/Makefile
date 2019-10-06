CXX = g++
CFLAGS = -O -Wall -fPIC -I $(ROOTSYS)/include -I $(ROOTSYS)/include/root -L$(ROOTSYS)/lib/root -L$(ROOTSYS)/lib
RM = rm -f

LIBS = -lCore -lCint -lHist -lGraf -lGraf3d -lGpad -lTree -lTreePlayer -lRint -lPostscript -lMatrix -lPhysics -lpthread -lm -ldl -lRIO -lNet
#LIBS = -lCore -lCint -lHist -lGraf -lGraf3d -lGpad -lTree -lTreePlayer -lRint -lPostscript -lMatrix -lPhysics -lpthread -lm -ldl 

all: fishershape fisherD0pi fisherD0K FisherVar

fishershape: fishershape.o Makefile
	$(CXX) $(CFLAGS) -o $@ $< $(LIBS)
	strip $@

fisherD0pi: fisherD0pi.o Makefile
	$(CXX) $(CFLAGS) -o $@ $< $(LIBS)
	strip $@

fisherD0K: fisherD0K.o Makefile
	$(CXX) $(CFLAGS) -o $@ $< $(LIBS)
	strip $@

FisherVar: FisherVar.o Makefile
	$(CXX) $(CFLAGS) -o $@ $< $(LIBS)
	strip $@

%.o: %.cc Makefile
	$(CXX) -o $@ -c $< $(CFLAGS)

clean:
	@ $(RM) *.{out,o} *~

