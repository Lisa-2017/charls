## CharLS fork with EMSCRIPTEN JavaScript bindings

### Changed from team-charls/charls

* All code is in /EMSCRIPTEN folder


Live Example
------------

Try it out [here](https://rawgit.com/chafey/charls/master/emscripten/test/index.html).

This is also integrated with [cornerstoneWADOImageLoader](https://github.com/chafey/cornerstoneWADOImageLoader)


Building JavaScript
-------------------

Requires
* EMSCRIPTEN
* CMAKE

``` bash
git clone https://github.com/chafey/charls
cmake -DCMAKE_TOOLCHAIN_FILE=~/emsdk_portable/emscripten/1.35.0/cmake/Modules/Platform/Emscripten.cmake \
   -DCMAKE_BUILD_TYPE=Release \
   -DBUILD_JS=ON \
   -DBUILD_SHARED_LIBS=OFF \
   -DBUILD_TESTING=OFF \
   -G"Unix Makefiles" \
   .
make
emcc libCharLS.a -o dist/libCharLS.js \
     --memory-init-file 0 \
     -s EXPORTED_FUNCTIONS="['_jpegls_decode']" \
     -s ALLOW_MEMORY_GROWTH=1 \
     -s NO_FILESYSTEM=1 \
     -s EXPORT_NAME="'CharLS'" \
     -s MODULARIZE=1 \
     -O3
```