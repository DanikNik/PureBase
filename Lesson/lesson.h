//
// Created by semyon on 13.12.18.
//

#ifndef PUREBASE_LESSON_H
#define PUREBASE_LESSON_H
#include "../Helper/defaults.h"
#include <string>
#include <map>

class Lesson {
private:
    std::string lesson_name;
    std::string db_name;
    std::string table_name;
    std::string db_type;
    std::string user_name;
    std::string lesson_id;
public:
    explicit Lesson();
    explicit Lesson(int);
    explicit Lesson(std::string);
    explicit Lesson(const Lesson&);
    explicit Lesson(Lesson&&);

    Lesson& operator=(const Lesson&);
    Lesson& operator=(Lesson&&);

    void SetLessonName(std::string);
    void SetDatabaseName(std::string);
    void SetUserName(std::string);
    void SetDatabaseType(std::string);
    std::map<std::string,std::string> GetParametrs();
};


#endif //PUREBASE_LESSON_H
