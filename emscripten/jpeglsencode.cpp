#include "../src/charls.h"
#include <emscripten.h>

#define EMSCRIPTEN_API __attribute__((used))


extern "C" {

    EMSCRIPTEN_API int jpegls_encode(void* image, int imageSize, int width, int height, int bitsPerSample, int components, int allowedLossyError, void** compressedBytes, size_t* compressedSize)
    {
        auto params = JlsParameters();
        params.width = width;
        params.height = height;
        params.bitsPerSample = bitsPerSample;
        params.components = components;
        params.allowedLossyError = allowedLossyError;

        *compressedBytes = malloc(imageSize);

        auto result = JpegLsEncode(compressedBytes, imageSize, compressedSize, image, imageSize, &params, nullptr);
        return (int)result;
    }

}
