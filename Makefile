# Makefile for demo project
PROFILE ?= Debug
PROJECT_NAME = use_demo
PROJECT_DIR = $(shell pwd)
PROJECT_BIN_DIR = $(PROJECT_DIR)/build/bin

exe = $(PROJECT_BIN_DIR)/$(PROJECT_NAME)
cmake:
	@echo "--- Configuring demo..."
	@mkdir -p build && cd build && \
	cmake -DCMAKE_BUILD_TYPE=$(PROFILE) \
		-DCMAKE_MAKE_PROGRAM=/Users/marco/Applications/CLion.app/Contents/bin/ninja/mac/aarch64/ninja \
		-DCMAKE_CXX_COMPILER=/opt/homebrew/opt/llvm/bin/clang++ \
		-G Ninja -S ..

build: cmake
	@echo "--- Building demo..."
	@cd build && \
	cmake --build . --target all

$(exe): build

run: $(exe)
	@echo "--- Running demo..."
	@$(exe)

clean:
	@echo "--- Cleaning demo..."
	@rm -rf build
	@rm output.txt

all: build
