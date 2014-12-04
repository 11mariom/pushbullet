CC=g++
CFLAGS=-Wall

all: pb

pb:
	$(CC) src/main.cpp -o pushbullet -lcurl

clean:
	rm pushbullet
