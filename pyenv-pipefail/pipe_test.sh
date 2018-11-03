#!/usr/bin/env bash

($(exit 0) | $(exit 0)) && echo O
($(exit 0) | $(exit 1)) || echo X
($(exit 1) | $(exit 0)) && echo O
($(exit 1) | $(exit 1)) || echo X

echo now set pipefail
set -o pipefail
($(exit 0) | $(exit 0)) && echo O
($(exit 0) | $(exit 1)) || echo X
($(exit 1) | $(exit 0)) || echo X
($(exit 1) | $(exit 1)) || echo X
