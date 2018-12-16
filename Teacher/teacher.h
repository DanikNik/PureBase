//
// Created by semyon on 16.12.18.
//

//#ifndef PUREBASE_TEACHER_H
#define PUREBASE_TEACHER_H

#include "../Helper/defaults.h"
#include <string>
#include <map>

class Teacher {
private:
    std::string teacher_name;
    std::string db_name;
    std::string table_name;
    std::string db_type;
    std::string user_name;
    std::string teacher_id;
public:
    explicit Teacher();
    explicit Teacher(int);
    explicit Teacher(std::string);
    explicit Teacher(const Teacher&);
    explicit Teacher(Teacher&&);

    Teacher& operator=(const Teacher&);
    Teacher& operator=(Teacher&&);

    void SetId(int id);
    void SetTeacherName(std::string);
    void SetDatabaseName(std::string);
    void SetUserName(std::string);
    void SetDatabaseType(std::string);
    std::map<std::string,std::string> GetParametrs();
};


//#endif //PUREBASE_TEACHER_H
