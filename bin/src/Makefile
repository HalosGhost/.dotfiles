CFLAGS  +=  -Os -Wall
LIBS    =   `pkg-config --libs-only-l libcurl`
PREFIX	=	
DESTDIR	=	..

.PHONY: all isitup lsip clobber qurl strip install

all: isitup lsip qurl strip

clobber:
	@rm -f {isitup,lsip,qurl}

isitup: isitup.c
	${CC} ${CFLAGS} ${LIBS} -o isitup isitup.c

lsip: lsip.c
	${CC} ${CFLAGS} ${LIBS} -o lsip lsip.c

qurl: qurl.c
	${CC} ${CFLAGS} ${LIBS} -o qurl qurl.c

strip:
	@strip {isitup,lsip,qurl}

install:
	@install -Dm755 {isitup,lsip,qurl} ${PREFIX}${DESTDIR}/

# vim:set tabstop=4 shiftwidth=4:
