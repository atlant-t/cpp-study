# Importable Variables
define IMPORTED_VARIABLES
# To setting only targeted lessons change target_lesson variable.
target_lesson = $(patsubst $(LESSON_SRC)/%/,%,$(LESSON_DIR_LIST))

endef

export IMPORTED_VARIABLES
$(eval $(call IMPORTED_VARIABLES))

include .variables

# Constants
LESSON_SRC := lesson
LESSON_DIR_LIST := $(dir $(wildcard $(LESSON_SRC)/*/Makefile))
STNDART_TARGETS := build install run clean

# System Variables
__PHONY += $(STNDART_TARGETS)

build:

# Standart targets
$(STNDART_TARGETS):
	@for lesson in $(target_lesson); do \
		if [ -e $(LESSON_SRC)/$$lesson/Makefile ]; then \
			echo -e "\e[96m$@ lesson:\e[00m $$lesson"; \
			$(MAKE) --no-print-directory --directory=$(LESSON_SRC)/$$lesson $@; \
		else \
			echo -e "\e[33mWarning:\e[00m Lesson $$lesson does not exist and skiped"; \
		fi \
	done || /bin/true;


.PHONY: $(__PHONY) variables-file

.variables:
	@echo "$$IMPORTED_VARIABLES" > .variables
