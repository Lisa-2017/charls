
make
emcc libCharLS.a -o dist/libCharLS.js \
     --memory-init-file 0 \
     -s EXPORTED_FUNCTIONS="['_jpegls_decode']" \
     -s ALLOW_MEMORY_GROWTH=1 \
     -s NO_FILESYSTEM=1 \
     -s EXPORT_NAME="'CharLS'" \
     -s MODULARIZE=1 \
     -O3
#cp dist/libCharLS.js ../cornerstoneWADOImageLoader/examples