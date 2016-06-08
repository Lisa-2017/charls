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
* emscripten
* cmake
* node
* grunt

> grunt

#### Built Files

There are four versions of the library provided to support combinations of fixed memory, dynamic memory, browser and
CommonJS.  Fixed memory is faster but will crash/blow up if memory is exceeded.  Dynamic memory is slower but
should not crash (and is therefore safer).
