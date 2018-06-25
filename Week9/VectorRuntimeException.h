#ifndef VECTORRUNTIMEEXCEPTION_H
#define VECTORRUNTIMEEXCEPTION_H

namespace Week9
{
class VectorRuntimeException
{
public:
    VectorRuntimeException(const char* message)
        : m_message(message)
    {

    }

    virtual ~VectorRuntimeException()
    {

    }

    virtual const char* getMessage() const
    {
        return m_message;
    }
protected:
    const char* m_message;
};
}

#endif // VECTORRUNTIMEEXCEPTION_H
