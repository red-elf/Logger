#!/bin/bash

echo "Installing" && \
  cd Library && \
  rm -rf ./Build && \
  mkdir Build && \
  cd Build && \
  cmake .. && \
  make && \
  sudo make install && \
  echo "Installed"
