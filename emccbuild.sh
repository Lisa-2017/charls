#!/bin/bash
mkdir build
emcc libCharLS.a \
     -o build/charLS-FixedMemory-browser.js \
     --memory-init-file 0 \
     -s EXPORTED_FUNCTIONS="['_jpegls_decode', '_jpegls_encode']" \
     -s TOTAL_MEMORY=400000000 \
     -s NO_FILESYSTEM=1 \
     -s EXPORT_NAME="'CharLS'" \
     -s MODULARIZE=1 \
     -s DISABLE_EXCEPTION_CATCHING=0 \
     -O3
emcc libCharLS.a \
     -o build/charLS-DynamicMemory-browser.js \
     --memory-init-file 0 \
     -s EXPORTED_FUNCTIONS="['_jpegls_decode', '_jpegls_encode']" \
     -s ALLOW_MEMORY_GROWTH=1 \
     -s NO_FILESYSTEM=1 \
     -s EXPORT_NAME="'CharLS'" \
     -s MODULARIZE=1 \
     -s DISABLE_EXCEPTION_CATCHING=0 \
     -O3
emcc libCharLS.a \
     -o build/charLS-FixedMemory-commonJS.js \
     --memory-init-file 0 \
     -s EXPORTED_FUNCTIONS="['_jpegls_decode', '_jpegls_encode']" \
     -s TOTAL_MEMORY=400000000 \
     -s NO_FILESYSTEM=1 \
     -s DISABLE_EXCEPTION_CATCHING=0 \
     -O3
emcc libCharLS.a \
     -o build/charLS-DynamicMemory-commonJS.js \
     --memory-init-file 0 \
     -s EXPORTED_FUNCTIONS="['_jpegls_decode', '_jpegls_encode']" \
     -s ALLOW_MEMORY_GROWTH=1 \
     -s NO_FILESYSTEM=1 \
     -s DISABLE_EXCEPTION_CATCHING=0 \
     -O3
