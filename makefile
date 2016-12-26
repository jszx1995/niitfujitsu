CC:=gcc
CC+=-o
IC:=-Iinclude
IC+=-c
OBJECTS:=lib/help.o lib/list.o lib/display.o lib/file.o lib/mkdir.o\
	lib/dirdelete.o lib/delete.o lib/create_dir.o lib/dircopy.o\
	lib/dircopydir.o lib/filecopy.o lib/filecopydir.o lib/copy.o\
	lib/symkink.o lib/main.o

/bin/niitfujitsu:$(OBJECTS)
	$(CC) $@ $^

lib/%.o:src/%.c
	$(CC) $@ $(IC) $^

lib/%.o:src/copy/%.c
	$(CC) $@ $(IC) $^
.PHONY:clean
clean:
	rm -fr /bin/niitfujitsu
