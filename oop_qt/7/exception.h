#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <QException>
#include <QMessageBox>

class myException : public QException
{
public:
    myException(QString const &text = " ") noexcept : msg(text) {}
    myException(const myException &err) { this->msg = err.msg; }
    ~myException() override {}
    void raise() const override { throw *this; }
    myException *clone() const override { return new myException(*this); }
    const char *what() const noexcept override { return this->msg.toStdString().c_str(); }
private:
    QString msg;
};

#endif // EXCEPTION_H
