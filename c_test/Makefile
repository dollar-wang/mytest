CC ?= gcc
CFLAGS ?= -Wall
DESTDIR ?= $(PWD)/output
bindir ?= ""

EXE=test1
SRCS=test1.c

$(EXE): $(SRCS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(SRCS) -o $@

default: $(EXE)
all: default

install: $(EXE)
	install -d -m 0755 $(DESTDIR)$(bindir)
	install -m 0755 $(EXE) $(DESTDIR)$(bindir)
clean:
	rm -rf $(EXE)
