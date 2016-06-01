#include "../src/charls.h"
#include <emscripten.h>

#define EMSCRIPTEN_API __attribute__((used))


extern "C" {

    EMSCRIPTEN_API int jpegls_decode(void* compressedBytes, int compressedSize, void** pImage, int* pImageSize, int* width, int* height, int* bitsPerSample, int*stride, int *components, int* allowedLossyError, int* interleaveMode)
    {
        // Read the header
        JlsParameters jlsParameters;
        auto error = JpegLsReadHeader(compressedBytes, compressedSize, &jlsParameters, nullptr);
        if(error != charls::ApiResult::OK) {
            return (int)error;
        }
        jlsParameters.outputBgr = false;

        // Calculate the size of the resulting image and allocate it
        auto bytesPerSample = (jlsParameters.bitsPerSample <= 8) ? 1 : 2;
        *pImageSize = (jlsParameters.width * jlsParameters.height * jlsParameters.components * bytesPerSample);
        *pImage = malloc(*pImageSize);

        // Return the parameters
        *width = jlsParameters.width;
        *height = jlsParameters.height;
        *bitsPerSample = jlsParameters.bitsPerSample;
        *stride = jlsParameters.stride;
        *components = jlsParameters.components;
        *allowedLossyError = jlsParameters.allowedLossyError;
        *interleaveMode = (int)jlsParameters.interleaveMode;

        // Decode the image
        error = JpegLsDecode(*pImage, *pImageSize, compressedBytes, compressedSize, nullptr, nullptr);
        if(error != charls::ApiResult::OK) {
            free(*pImage);
            return (int)error;
        }

        // success
        return 0;
    }

}
