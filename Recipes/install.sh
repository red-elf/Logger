#!/bin/bash

echo "Installing the 'Logger' library, please wait" && \
  cd Library && \
  rm -rf ./Build && \
  mkdir Build && \
  cd Build && \
  cmake .. && \
  make && \
  sudo make install && \
  echo "The 'Logger' library has been installed with success"
