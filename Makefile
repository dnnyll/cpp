# modules
MODULES = cpp_00 cpp_01 cpp_02 cpp_03 cpp_04 cpp_05 cpp_06 cpp_07 cpp_08 cpp_09

# detect all exercises
SUBDIRS := $(foreach mod,$(MODULES),$(wildcard $(mod)/ex*))

# ===== BUILD =====

all:
	@for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir; \
	done

clean:
	@for dir in $(SUBDIRS); do \
		echo "Cleaning $$dir"; \
		$(MAKE) -C $$dir clean || true; \
	done

fclean:
	@for dir in $(SUBDIRS); do \
		echo "Full cleaning $$dir"; \
		$(MAKE) -C $$dir fclean || true; \
		rm -rf $$dir/obj $$dir/bin; \
	done

re:
	@for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir re || true; \
	done

# ===== GIT =====

# usage: make push COMMSG="your message"
push: fclean
	@DATE=$$(date "+%Y-%m-%d %Hh%Mm%S"); \
	git add -A; \
	git commit -m "$$DATE $(COMMSG)"; \
	git push

fetch:
	git fetch
	git pull

# ===== PHONY =====

.PHONY: all clean fclean re push fetch