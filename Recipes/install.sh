#!/bin/bash

echo "Installing the 'Logger' library, please wait" && \
  cd Library && \
  rm -rf ./Build && \
  mkdir Build && \
  cd Build && \
  source ../../Version/version.sh && cmake -GNinja -DVERSIONABLE_VERSION_PRIMARY="$VERSIONABLE_VERSION_PRIMARY" \
  -DVERSIONABLE_VERSION_SECONDARY="$VERSIONABLE_VERSION_SECONDARY" -DVERSIONABLE_NAME="$VERSIONABLE_NAME" \
  -DVERSIONABLE_VERSION_PATCH="$VERSIONABLE_VERSION_PATCH" .. && \
  ninja -j "$(nproc)" && \
  sudo ninja install && \
  echo "The 'Logger' library has been installed with success"
