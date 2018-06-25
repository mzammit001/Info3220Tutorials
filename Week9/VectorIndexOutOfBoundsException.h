#ifndef VECTORINDEXOUTOFBOUNDSEXCEPTION_H
#define VECTORINDEXOUTOFBOUNDSEXCEPTION_H

#include "VectorRuntimeException.h"

namespace Week9 {
    class VectorIndexOutOfBoundsException : public VectorRuntimeException
    {
    public:
        VectorIndexOutOfBoundsException(const char* message)
            : VectorRuntimeException(message) {
        }

        ~VectorIndexOutOfBoundsException() {}
    };
}

#endif // VECTORINDEXOUTOFBOUNDSEXCEPTION_H
