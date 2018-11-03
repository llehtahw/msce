These two scirpts test if a spetial bug occurs.

- bug\_ver.sh outputs no **NOT OK** if the bug occurs,
- else fixed\_ver.sh outputs no **NOT OK** if the bug occurs.
- it makes no sense that both outputs no **NOT OK**.

## bug

If the following conditions satisfied, the bug would occur:

- using pyenv
- no executable `greadlink` could be found in `PATH`
- environment variable SHELLOPTS exported
- shell 'set -o pipefail' option set
- shell 'set -e' option set

## cause

some scripts in pyenv/libexec contains command as such:

'''
    READLINK=$(type -p greadlink readlink | head -1)
'''

the right side of the assign expression is a pipe,
whose retval decided by the right most command of the pipe, normally.

But once 'set -o pipefail' set, pipe returns non-zero
when any command of the pipe gets non-zero retval.
(refer to `./pipe_test.sh`)
Moreover, the script exits with failure immediatly then, while 'set -e' set.

## ...

I do not know how was it neccesary to 'export SHELLOPTS' in shell,
but it did occur in some makefile, and made me to waste time to debug.
