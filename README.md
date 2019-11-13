## CharLS fork with EMSCRIPTEN JavaScript bindings

### Changed from team-charls/charls

### Installing for Node

> npm install CharLS.js --save

### Usage

See examples/browser for access from a browser
See examples/node for access from node
See https://github.com/chafey/cornerstoneWADOImageLoader/blob/master/src/decoders/decodeJPEGLS.js

### Building

Requires
* docker


#### Building

Start a docker container with the EMSCRIPTEN build environment and shell into it
> ./emccdocker.sh

Create directory "release" to hold the cmake generated makefile and build output

> mkdir release; cd release

Run cmake with EMSCRIPTEN tool chain

> emmake cmake -DCMAKE_BUILD_TYPE=Release -DBUILD_CODEC=OFF -DBUILD_JS=ON -DBUILD_SHARED_LIBS=OFF -GUnix\ Makefiles ..

Build the library

> make

Create standalone JS/WASM outputs for browser/node/fixed-memory/dynamic-memory

> ../emccbuild.sh

Copy built files into dist folder

> cp build/*.js ../dist

#### Built Files

There are four versions of the library provided to support combinations of fixed memory, dynamic memory, browser and
CommonJS.  Fixed memory is faster but will crash/blow up if memory is exceeded.  Dynamic memory is slower but
should not crash (and is therefore safer).