#
# makefile for the avalon compiler
#
# :author   Ntwali Bashige
# :year     2017
# :email    ntwali.bashige@gmail.com
#

cc          := g++
cflags      := -std=c++11 -g -Wall -pedantic
ldpaths     := -Lbin/libs
rdpaths     := '-Wl,-rpath=$$ORIGIN/libs'
ldflags     := -lboost_filesystem -lboost_system
src_dir     := src
inc         := -Isrc -Iinclude
sysinc      := -isystem deps/boost
build_dir   := build
bin_dir     := bin
target      := $(bin_dir)/avalon

src_ext     := cpp
sources     := $(shell find $(src_dir) -type f -name *.$(src_ext))
objects     := $(patsubst $(src_dir)/%,$(build_dir)/%,$(sources:.$(src_ext)=.o))


.PHONY: all
all: setup $(target)

$(target): $(objects)
	@echo " Compiling and linking just for you..."
	@$(cc) $^ -o $(target) $(ldpaths) $(ldflags) $(rdpaths)

$(build_dir)/%.o: $(src_dir)/%.$(src_ext)
	@mkdir -p $(dir $@)
	@$(cc) $(cflags) $(sysinc) $(inc) -c -o $@ $<

.PHONY: setup
setup:
	@echo " Setting things up anew..."
	@mkdir -p $(bin_dir)/libs
	@mkdir -p $(build_dir)

.PHONY: clean
clean:
	@echo " Cleaning up the mess you made..."
	@find . -path ./docs/venv -prune -o -exec touch {} \;
	@rm -rf $(build_dir)
	@rm -f $(bin_dir)/avalon
