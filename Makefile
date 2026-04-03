# =========================
# MODULES / DIRECTORIES
# =========================

MODULES = cpp_00 cpp_01 cpp_02 cpp_03 cpp_04 cpp_05 cpp_06 cpp_07 cpp_08 cpp_09
SUBDIRS := $(foreach mod,$(MODULES),$(wildcard $(mod)/ex*))

# =========================
# BUILD
# =========================

all:
	@for dir in $(SUBDIRS); do \
		echo "Building $$dir"; \
		$(MAKE) -C $$dir || true; \
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
		echo "Rebuilding $$dir"; \
		$(MAKE) -C $$dir re || true; \
	done

# =========================
# GIT
# =========================

push: fclean
	@DATE=$$(date "+%Y-%m-%d %Hh%Mm%S"); \
	printf "Commit message > "; \
	read MSG; \
	MSG=$${MSG:-update}; \
	git add -A; \
	git commit -m "$$DATE $$MSG" || echo "Nothing to commit"; \
	git push

fetch:
	git fetch
	git pull

# =========================
# PHONY
# =========================

.PHONY: all clean fclean re push fetch

#make          # build everything
#make clean    # clean object files
#make fclean   # remove obj/ and bin/ directories
#make re       # rebuild everything
#make push     # interactive git commit + push
#make fetch    # git fetch + pull
