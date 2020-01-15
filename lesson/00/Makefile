SRCDIR := ./src
OUTDIR := ./dist
BINDIR := /usr/bin

STNDART_TARGETS := build install run clean

# By default object files will be deleted
# as soon as theay are added to an archive.
# To keep object files they must be added
# to the .SECONDARY target.
.SECONDARY: $(OUTDIR)/HelloWorld.o

# Define the default compiler
CC = g++

__PHONY += $(STNDART_TARGETS)

build: $(OUTDIR) $(OUTDIR)/HelloWorld

install: build
	@cp $(OUTDIR)/HelloWorld $(BINDIR)

run: build
	@$(OUTDIR)/HelloWorld

clean:
	@rm -rdf ./dist

$(OUTDIR):
	@mkdir $@


$(OUTDIR)/%.o: $(SRCDIR)/%.cpp
	g++ -c -o $@ $^


.PHONY: $(__PHONY)
