CC=gcc
CFLAGS=-I"." -I"../../"

# FIT_USE_STDINT_H can also be defined in fit_config.h
ifneq ($(OS),Windows_NT)
	CFLAGS+=-DFIT_USE_STDINT_H
endif

epoch: epoch.o
	$(CC) $(CFLAGS) epoch.o -o epoch -lm

epoch.o: epoch.c
	$(CC) $(CFLAGS) -c epoch.c -o epoch.o

clean:
	rm -f epoch *.o
