#!/bin/bash

set -euo pipefail

PY=`which ${1:-python2.7}`
if [ -z "$PY" ]; then
  echo "${1:-python2.7} is not available, cannot find python2.7"
  exit 1
fi

EZ="$PY -m easy_install"
VENV="$PY -m virtualenv"
$VENV 2>&1 > /dev/null || true
if [ ! $? -eq 0 ]; then
  echo "Installing missing virtualenv..."
  $EZ -U virtualenv
fi

$VENV --no-site-packages --python="$PY" .venv/
PY=".venv/bin/python"
PIP="$PY -m pip"

$PIP install\
  -e .\
  -e externals/stratum\
  -e externals/argon2d-hash\
  -rrequirements.txt
