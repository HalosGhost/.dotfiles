CFLAGS  +=  -Os -Wall
LIBS    =   `pkg-config --libs-only-l libcurl`

.PHONY: all isitup lsip clobber

all: isitup lsip

clobber:
	@rm -f ../lsip
	@rm -f ../isitup

isitup:
	${CC} ${CFLAGS} ${LIBS} -o ../isitup isitup.c
	@strip ../isitup

lsip:
	${CC} ${CFLAGS} ${LIBS} -o ../lsip lsip.c
	@strip ../lsip

# vim:set tabstop=4 shiftwidth=4:
