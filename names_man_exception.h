#ifndef NAMES_MAN_EXCEPTION
#define NAMES_MAN_EXCEPTION

#include <QException>


class NamesManException : public QException
{
    QByteArray m_data;
public:
    NamesManException( const QString& str )
    {
        m_data = str.toLocal8Bit();//str.toUtf8();
    }
    void raise() const { throw *this; }
    NamesManException *clone() const { return new NamesManException(*this); }
    virtual ~NamesManException() throw() {  }
    virtual const char* what() const throw()
    {
        return m_data.data();
    }
};


#endif // NAMES_MAN_EXCEPTION

