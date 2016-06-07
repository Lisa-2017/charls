## CharLS fork with EMSCRIPTEN JavaScript bindings

### Changed from team-charls/charls

### Usage

See https://github.com/chafey/cornerstoneWADOImageLoader/blob/master/src/decoders/decodeJPEGLS.js

### Building

Requires
* emscripten
* cmake
* node
* grunt

> grunt

The output is dist/charLS-DynamicMemory.js and dist/charLS-FixedMemory.js

#### charLS-DynamicMemory.js

Slower but should handle any size image

#### charLS-FixedMemory.js

Faster but will crash if you run out of memory
