#!/usr/bin/env bash

if [[ ! $(which python) =~ ^.+\.pyenv/shims/python$ ]]; then
    echo pyenv is good, but it seems we are not exploiting it, unreasonably.
    echo set up pyenv and then run this script "'$0'" again.
    exit 1
fi

function assert_O() {
    echo Runnig [$*], expecting O
    ($* && echo -e "\tgot O, OK") || echo -e "\tgot X, Not OK"
}

function assert_X() {
    echo Runnig [$*], expecting X
    ($* && echo -e "\tgot X, NOT OK") || echo -e "\tgot O, OK"
}

function echrun() {
    echo $* && $*
}

export -n SHELLOPTS
echrun set +o pipefail
assert_O python -V
echrun set -o pipefail
assert_O python -V

export SHELLOPTS
echrun set +o pipefail
assert_O python -V
echrun set -o pipefail
assert_O python -V
