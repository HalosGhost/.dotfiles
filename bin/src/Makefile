CFLAGS  +=  -Os -Wall
LIBS    =   `pkg-config --libs-only-l libcurl`
PREFIX	=	
DESTDIR	=	..

.PHONY: all isitup lsip clobber qurl strip

all: isitup lsip qurl strip

clobber:
	@rm -f ../{isitup,lsip,qurl}

isitup:
	${CC} ${CFLAGS} ${LIBS} -o ${PREFIX}${DESTDIR}/isitup isitup.c

lsip:
	${CC} ${CFLAGS} ${LIBS} -o ${PREFIX}${DESTDIR}/lsip lsip.c

qurl:
	${CC} ${CFLAGS} ${LIBS} -o ${PREFIX}${DESTDIR}/qurl qurl.c

strip:
	@strip ${PREFIX}${DESTDIR}/{isitup,lsip,qurl}

# vim:set tabstop=4 shiftwidth=4:
