SHELL := /bin/bash
PYTHONPATH := $(shell .venv/bin/python -c 'import sys; print("."+":".join(sys.path))')

server: 
	exec env -i PYTHONPATH="$(PYTHONPATH)" .venv/bin/twistd -ny launcher.tac

clean:
	exec git clean -X -f -d

cleanenv:
	exec rm -rf .venv

venv:
	./virtualenv.sh


.PHONY: server clean cleanenv venv
