CFLAGS  +=  -Os -Wall
LIBS    =   `pkg-config --libs-only-l libcurl`

.PHONY: all isitup lsip clobber qurl

all: isitup lsip qurl

clobber:
	@rm -f ../lsip
	@rm -f ../isitup
	@rm -f ../qurl

isitup:
	${CC} ${CFLAGS} ${LIBS} -o ../isitup isitup.c
	@strip ../isitup

lsip:
	${CC} ${CFLAGS} ${LIBS} -o ../lsip lsip.c
	@strip ../lsip

qurl:
	${CC} ${CFLAGS} ${LIBS} -o ../qurl qurl.c
	@strip ../qurl

# vim:set tabstop=4 shiftwidth=4:
