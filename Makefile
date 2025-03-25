# Makefile for demo project
PROJECT_NAME = use_demo
PROJECT_DIR = $(shell pwd)
PROJECT_BIN_DIR = $(PROJECT_DIR)/build/bin

# Input arguments
PROFILE ?= Debug
CLANG ?=/opt/homebrew/opt/llvm/bin/clang++

exe = $(PROJECT_BIN_DIR)/$(PROJECT_NAME)
cmake:
	@echo "--- Configuring demo..."
	@mkdir -p build && cd build && \
	cmake -DCMAKE_BUILD_TYPE=$(PROFILE) \
		-DCMAKE_MAKE_PROGRAM=ninja \
		-DCMAKE_CXX_COMPILER=$(CLANG) \
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
	@rm -f output.txt

all: build
