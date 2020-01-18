SRCDIR := ./src
OUTDIR := ./dist
BINDIR := /usr/bin

STNDART_TARGETS := build install run clean

# Define the default compiler
CC = g++

__PHONY += $(STNDART_TARGETS)

build: $(OUTDIR) $(OUTDIR)/Riddler

install: build
	@cp $(OUTDIR)/Riddler $(BINDIR)

run: build
	@$(OUTDIR)/Riddler

clean:
	@rm -rdf ./dist

$(OUTDIR):
	@mkdir $@


$(OUTDIR)/%.o: $(SRCDIR)/%.cpp
	g++ -c -o $@ $^


.PHONY: $(__PHONY)
