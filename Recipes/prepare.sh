#!/bin/bash

echo "Preparing the 'Logger' library for the installation" && \
  git submodule init && git submodule update && \
  echo "The 'Logger' library is prepared for the installation"