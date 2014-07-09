CFLAGS  +=  -Os -Wall -std=c11
LIBS    =   `pkg-config --libs-only-l libcurl`
PREFIX	=	..
DESTDIR	=	

.PHONY: all hr isitup lsip clobber sicolor qurl strip install

all: hr isitup lsip sicolor qurl strip

clobber:
	@rm -f {hr,isitup,lsip,sicolor,qurl}

hr: hr.c
	${CC} ${CFLAGS} --std=c99 -o hr hr.c

isitup: isitup.c
	${CC} ${CFLAGS} ${LIBS} -o isitup isitup.c

lsip: lsip.c
	${CC} ${CFLAGS} ${LIBS} -o lsip lsip.c

sicolor: sicolor.c ansicolor.h
	${CC} ${CFLAGS} -o sicolor sicolor.c

qurl: qurl.c
	${CC} ${CFLAGS} ${LIBS} -o qurl qurl.c

strip:
	@strip {hr,isitup,lsip,sicolor,qurl}

install:
	@install -Dm755 {hr,isitup,lsip,sicolor,qurl} ${DESTDIR}${PREFIX}/

# vim:set tabstop=4 shiftwidth=4:
