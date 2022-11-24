# makefile for shared object file

CC = gcc
CFLAG_SOURCE = -Wall -c -fPIC
CFLAG = -shared -fPIC -Wl,-soname,
PATH_INCLUDE = src
PATH_SOURCE = src
PATH_SOURCE_RCV = src/rcv
OBJECT = convgpx.o \
	 convkml.o \
	 convrnx.o \
	 datum.o \
	 download.o \
	 ephemeris.o \
	 geoid.o \
	 gis.o \
	 ionex.o \
	 lambda.o \
	 options.o \
	 pntpos.o \
	 postpos.o \
	 ppp_ar.o \
	 ppp.o \
	 preceph.o \
	 rcvraw.o \
	 rinex.o \
	 rtcm2.o \
	 rtcm3.o \
	 rtcm3e.o \
	 rtcm.o \
	 rtkcmn.o \
	 rtkpos.o \
	 rtksvr.o \
	 sbas.o \
	 solution.o \
	 stream.o \
	 streamsvr.o \
	 tides.o \
	 tle.o \
	 binex.o \
	 crescent.o \
	 javad.o \
	 novatel.o \
	 nvs.o \
	 rt17.o \
	 septentrio.o \
	 skytraq.o \
	 ss2.o \
	 ublox.o

librtklib_test_without_java.so.0.0.0: $(OBJECT)
	$(CC) $(CFLAG)librtklib_test_without_java.so.0 -o librtklib_test_without_java.so.0.0.0 \
		$(OBJECT)

convgpx.o: $(PATH_SOURCE)/convgpx.c \
		$(PATH_INCLUDE)/rtklib.h
	$(CC) $(CFLAG_SOURCE) $(PATH_SOURCE)/convgpx.c

convkml.o: $(PATH_SOURCE)/convkml.c \
		$(PATH_INCLUDE)/rtklib.h
	$(CC) $(CFLAG_SOURCE) $(PATH_SOURCE)/convkml.c

convrnx.o: $(PATH_SOURCE)/convrnx.c \
		$(PATH_INCLUDE)/rtklib.h
	$(CC) $(CFLAG_SOURCE) $(PATH_SOURCE)/convrnx.c

datum.o: $(PATH_SOURCE)/datum.c \
		$(PATH_INCLUDE)/rtklib.h
	$(CC) $(CFLAG_SOURCE) $(PATH_SOURCE)/datum.c

download.o: $(PATH_SOURCE)/download.c \
		$(PATH_INCLUDE)/rtklib.h
	$(CC) $(CFLAG_SOURCE) $(PATH_SOURCE)/download.c

ephemeris.o: $(PATH_SOURCE)/ephemeris.c \
		$(PATH_INCLUDE)/rtklib.h
	$(CC) $(CFLAG_SOURCE) $(PATH_SOURCE)/ephemeris.c

geoid.o: $(PATH_SOURCE)/geoid.c \
		$(PATH_INCLUDE)/rtklib.h
	$(CC) $(CFLAG_SOURCE) $(PATH_SOURCE)/geoid.c

gis.o: $(PATH_SOURCE)/gis.c \
		$(PATH_INCLUDE)/rtklib.h
	$(CC) $(CFLAG_SOURCE) $(PATH_SOURCE)/gis.c

ionex.o: $(PATH_SOURCE)/ionex.c \
		$(PATH_INCLUDE)/rtklib.h
	$(CC) $(CFLAG_SOURCE) $(PATH_SOURCE)/ionex.c

lambda.o: $(PATH_SOURCE)/lambda.c \
		$(PATH_INCLUDE)/rtklib.h
	$(CC) $(CFLAG_SOURCE) $(PATH_SOURCE)/lambda.c

options.o: $(PATH_SOURCE)/options.c \
		$(PATH_INCLUDE)/rtklib.h
	$(CC) $(CFLAG_SOURCE) $(PATH_SOURCE)/options.c

pntpos.o: $(PATH_SOURCE)/pntpos.c \
		$(PATH_INCLUDE)/rtklib.h
	$(CC) $(CFLAG_SOURCE) $(PATH_SOURCE)/pntpos.c

postpos.o: $(PATH_SOURCE)/postpos.c \
		$(PATH_INCLUDE)/rtklib.h
	$(CC) $(CFLAG_SOURCE) $(PATH_SOURCE)/postpos.c

ppp_ar.o: $(PATH_SOURCE)/ppp_ar.c \
		$(PATH_INCLUDE)/rtklib.h
	$(CC) $(CFLAG_SOURCE) $(PATH_SOURCE)/ppp_ar.c

ppp.o: $(PATH_SOURCE)/ppp.c \
		$(PATH_INCLUDE)/rtklib.h
	$(CC) $(CFLAG_SOURCE) $(PATH_SOURCE)/ppp.c

preceph.o: $(PATH_SOURCE)/preceph.c \
		$(PATH_INCLUDE)/rtklib.h
	$(CC) $(CFLAG_SOURCE) $(PATH_SOURCE)/preceph.c

rcvraw.o: $(PATH_SOURCE)/rcvraw.c \
		$(PATH_INCLUDE)/rtklib.h
	$(CC) $(CFLAG_SOURCE) $(PATH_SOURCE)/rcvraw.c

rinex.o: $(PATH_SOURCE)/rinex.c \
		$(PATH_INCLUDE)/rtklib.h
	$(CC) $(CFLAG_SOURCE) $(PATH_SOURCE)/rinex.c

rtcm2.o: $(PATH_SOURCE)/rtcm2.c \
		$(PATH_INCLUDE)/rtklib.h
	$(CC) $(CFLAG_SOURCE) $(PATH_SOURCE)/rtcm2.c

rtcm3.o: $(PATH_SOURCE)/rtcm3.c \
		$(PATH_INCLUDE)/rtklib.h
	$(CC) $(CFLAG_SOURCE) $(PATH_SOURCE)/rtcm3.c

rtcm3e.o: $(PATH_SOURCE)/rtcm3e.c \
		$(PATH_INCLUDE)/rtklib.h
	$(CC) $(CFLAG_SOURCE) $(PATH_SOURCE)/rtcm3e.c

rtcm.o: $(PATH_SOURCE)/rtcm.c \
		$(PATH_INCLUDE)/rtklib.h
	$(CC) $(CFLAG_SOURCE) $(PATH_SOURCE)/rtcm.c

rtkcmn.o: $(PATH_SOURCE)/rtkcmn.c \
		$(PATH_INCLUDE)/rtklib.h
	$(CC) $(CFLAG_SOURCE) $(PATH_SOURCE)/rtkcmn.c

rtkpos.o: $(PATH_SOURCE)/rtkpos.c \
		$(PATH_INCLUDE)/rtklib.h
	$(CC) $(CFLAG_SOURCE) $(PATH_SOURCE)/rtkpos.c

rtksvr.o: $(PATH_SOURCE)/rtksvr.c \
		$(PATH_INCLUDE)/rtklib.h
	$(CC) $(CFLAG_SOURCE) $(PATH_SOURCE)/rtksvr.c

sbas.o: $(PATH_SOURCE)/sbas.c \
		$(PATH_INCLUDE)/rtklib.h
	$(CC) $(CFLAG_SOURCE) $(PATH_SOURCE)/sbas.c

solution.o: $(PATH_SOURCE)/solution.c \
		$(PATH_INCLUDE)/rtklib.h
	$(CC) $(CFLAG_SOURCE) $(PATH_SOURCE)/solution.c

stream.o: $(PATH_SOURCE)/stream.c \
		$(PATH_INCLUDE)/rtklib.h
	$(CC) $(CFLAG_SOURCE) $(PATH_SOURCE)/stream.c

streamsvr.o: $(PATH_SOURCE)/streamsvr.c \
		$(PATH_INCLUDE)/rtklib.h
	$(CC) $(CFLAG_SOURCE) $(PATH_SOURCE)/streamsvr.c

tides.o: $(PATH_SOURCE)/tides.c \
		$(PATH_INCLUDE)/rtklib.h
	$(CC) $(CFLAG_SOURCE) $(PATH_SOURCE)/tides.c

tle.o: $(PATH_SOURCE)/tle.c \
		$(PATH_INCLUDE)/rtklib.h
	$(CC) $(CFLAG_SOURCE) $(PATH_SOURCE)/tle.c

binex.o: $(PATH_SOURCE_RCV)/binex.c \
		$(PATH_INCLUDE)/rtklib.h
	$(CC) $(CFLAG_SOURCE) $(PATH_SOURCE_RCV)/binex.c

crescent.o: $(PATH_SOURCE_RCV)/crescent.c \
		$(PATH_INCLUDE)/rtklib.h
	$(CC) $(CFLAG_SOURCE) $(PATH_SOURCE_RCV)/crescent.c

javad.o: $(PATH_SOURCE_RCV)/javad.c \
		$(PATH_INCLUDE)/rtklib.h
	$(CC) $(CFLAG_SOURCE) $(PATH_SOURCE_RCV)/javad.c

novatel.o: $(PATH_SOURCE_RCV)/novatel.c \
		$(PATH_INCLUDE)/rtklib.h
	$(CC) $(CFLAG_SOURCE) $(PATH_SOURCE_RCV)/novatel.c

nvs.o: $(PATH_SOURCE_RCV)/nvs.c \
		$(PATH_INCLUDE)/rtklib.h
	$(CC) $(CFLAG_SOURCE) $(PATH_SOURCE_RCV)/nvs.c

rt17.o: $(PATH_SOURCE_RCV)/rt17.c \
		$(PATH_INCLUDE)/rtklib.h
	$(CC) $(CFLAG_SOURCE) $(PATH_SOURCE_RCV)/rt17.c

septentrio.o: $(PATH_SOURCE_RCV)/septentrio.c \
		$(PATH_INCLUDE)/rtklib.h
	$(CC) $(CFLAG_SOURCE) $(PATH_SOURCE_RCV)/septentrio.c

skytraq.o: $(PATH_SOURCE_RCV)/skytraq.c \
		$(PATH_INCLUDE)/rtklib.h
	$(CC) $(CFLAG_SOURCE) $(PATH_SOURCE_RCV)/skytraq.c

ss2.o: $(PATH_SOURCE_RCV)/ss2.c \
		$(PATH_INCLUDE)/rtklib.h
	$(CC) $(CFLAG_SOURCE) $(PATH_SOURCE_RCV)/ss2.c

ublox.o: $(PATH_SOURCE_RCV)/ublox.c \
		$(PATH_INCLUDE)/rtklib.h
	$(CC) $(CFLAG_SOURCE) $(PATH_SOURCE_RCV)/ublox.c

link_library_soname:
	ln -s librtklib_test_without_java.so.0.0.0 librtklib_test_without_java.so.0

link_library:
	ln -s librtklib_test_without_java.so.0.0.0 librtklib_test_without_java.so

clean:
	rm librtklib_test_without_java.so librtklib_test_without_java.so.0 \
		librtklib_test_without_java.so.0.0.0 $(OBJECT)
