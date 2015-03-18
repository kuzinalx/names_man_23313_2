#ifndef NAME_INFO
#define NAME_INFO

#include <QString>

class NameInfo
{
public:
    // имя, информацию о котором представляет объект.
    void SetName( const QString& name );

    // Установка следующих свойств не обязательна! Если они не были явно установлены, объект должен уметь их
    // вычислить, исходя из заданного имени.

    // Фамилия, образованная от имени. Может быть подана как в мужском, так и в женском роде.
    // Функция должна сама определить род. Например, для имени Илья может быть подано как Ильин, так и Ильина.
    void SetSurname( const QString& surname );
    // Отчество образованное от имени. Мужское, если bIsMale=true (Ильич), женское, если bIsMale=false.
    void SetFathername( const QString& fname, bool bIsMale );
    // род имени bMale=true - мужской, иначе - женский.
    void SetGender( bool bMale );

    QString Name() const;
    QString Surname( bool bMale ) const;
    QString Fathername( bool bMale ) const;
    bool Gender() const;
};

#endif // NAME_INFO

