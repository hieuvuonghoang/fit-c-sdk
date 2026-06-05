CC=gcc
CFLAGS=-I"." -I"../../"

# FIT_USE_STDINT_H can also be defined in fit_config.h
ifneq ($(OS),Windows_NT)
	CFLAGS+=-DFIT_USE_STDINT_H
endif

change_time: change_time.o fit.o fit_convert.o fit_crc.o fit_product.o
	$(CC) $(CFLAGS) change_time.o fit.o fit_convert.o fit_crc.o fit_product.o -o change_time -lm

change_time.o: change_time.c
	$(CC) $(CFLAGS) -c change_time.c -o change_time.o

fit.o: ../../fit.c ../../fit_config.h ../../fit_include.h
	$(CC) $(CFLAGS) -c ../../fit.c -o fit.o

fit_convert.o: ../../fit_convert.c ../../fit_config.h ../../fit_include.h
	$(CC) $(CFLAGS) -c ../../fit_convert.c -o fit_convert.o

fit_crc.o: ../../fit_crc.c ../../fit_config.h ../../fit_include.h
	$(CC) $(CFLAGS) -c ../../fit_crc.c -o fit_crc.o

fit_product.o: ../../fit_product.c ../../fit_config.h ../../fit_include.h
	$(CC) $(CFLAGS) -c ../../fit_product.c -o fit_product.o

clean:
	rm -f change_time *.o

