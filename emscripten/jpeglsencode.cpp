#include "../src/charls.h"
#include <emscripten.h>

#define EMSCRIPTEN_API __attribute__((used))


extern "C" {

    EMSCRIPTEN_API int jpegls_encode(void* image, int imageSize, int width, int height, int bitsPerSample, int components, int allowedLossyError, void** compressedBytes, int* compressedSize)
    {
        auto params = JlsParameters();
        params.components = components;
        params.bitsPerSample = bitsPerSample;
        params.width = width;
        params.height = height;
        //params.allowedLossyError = allowedLossyError;

        *compressedBytes = malloc(imageSize);
        size_t compressedSize_t = 0;
        auto result = JpegLsEncode(compressedBytes, imageSize, &compressedSize_t, image, imageSize, &params, nullptr);
        *compressedSize = (int)compressedSize_t;
        return (int)result;
    }

}
