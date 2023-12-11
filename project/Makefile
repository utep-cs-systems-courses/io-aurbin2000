all: toy.elf

COMMON_OBJECTS = toy.o stateMachine.o libTimer.o
CPU = msp430g2553
CFLAGS = -mmcu=${CPU} -I.
LDFLAGS = -L/opt/ti/msp430_gcc/include
CC = msp430-elf-gcc
AS = msp430-elf-as
AR = msp430-elf-ar

toy.elf: ${COMMON_OBJECTS}
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: toy.elf
	msp430loader.sh toy.elf

clean:
	rm -f *.o *.elf

toy.o: toy.c toy.h libTimer.h

	${CC} ${CFLAGS} -c -o $@ $<



stateMachine.o: stateMachine.c toy.h libTimer.h

	${CC} ${CFLAGS} -c -o $@ $<



libTimer.o: libTimer.c libTimer.h

	${CC} ${CFLAGS} -c -o $@ $<

.PHONY: all load clean
