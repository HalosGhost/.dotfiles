CFLAGS  +=  -Os -Wall
LIBS    =   `pkg-config --libs-only-l libcurl`
PREFIX	=	..
DESTDIR	=	

.PHONY: all isitup lsip clobber sicolor qurl strip install

all: isitup lsip sicolor qurl strip

clobber:
	@rm -f {isitup,lsip,sicolor,qurl}

isitup: isitup.c
	${CC} ${CFLAGS} ${LIBS} -o isitup isitup.c

lsip: lsip.c
	${CC} ${CFLAGS} ${LIBS} -o lsip lsip.c

sicolor: sicolor.c ansicolor.h
	${CC} ${CFLAGS} ${LIBS} -o sicolor sicolor.c

qurl: qurl.c
	${CC} ${CFLAGS} ${LIBS} -o qurl qurl.c

strip:
	@strip {isitup,lsip,sicolor,qurl}

install:
	@install -Dm755 {isitup,lsip,sicolor,qurl} ${DESTDIR}${PREFIX}/

# vim:set tabstop=4 shiftwidth=4:
