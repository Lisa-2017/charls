
make
emcc libCharLS.a -o dist/libCharLS.js \
     --memory-init-file 0 \
     -s ELIMINATE_DUPLICATE_FUNCTIONS=1 \
     -s EXPORTED_FUNCTIONS="['_jpegls_decode', 'jpegls_encode']" \
     -s ALLOW_MEMORY_GROWTH=1 \
     -s NO_FILESYSTEM=1 \
     -s EXPORT_NAME="'CharLS'" \
     -s MODULARIZE=1 \
     -s DISABLE_EXCEPTION_CATCHING=0 \
     -O3
cp dist/libCharLS.js ../cornerstoneWADOImageLoader/examples