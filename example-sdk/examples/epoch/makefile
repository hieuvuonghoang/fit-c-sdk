CC=gcc
CFLAGS=-I"." -I"../../"

# FIT_USE_STDINT_H can also be defined in fit_config.h
ifneq ($(OS),Windows_NT)
	CFLAGS+=-DFIT_USE_STDINT_H
endif

epoch: epoch.o fit_time.o
	$(CC) $(CFLAGS) epoch.o fit_time.o -o epoch -lm

epoch.o: epoch.c
	$(CC) $(CFLAGS) -c epoch.c -o epoch.o

fit_time.o: ../../fit_time.c ../../fit_time.h ../../fit_include.h
	$(CC) $(CFLAGS) -c ../../fit_time.c -o fit_time.o

clean:
	rm -f epoch *.o
