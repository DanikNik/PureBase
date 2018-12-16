//
// Created by semyon on 16.12.18.
//

//#ifndef PUREBASE_SUBJECT_H
#define PUREBASE_SUBJECT_H

#include "../Helper/defaults.h"
#include <string>
#include <map>

class Subject {
private:
    std::string subject_name;
    std::string db_name;
    std::string table_name;
    std::string db_type;
    std::string user_name;
    std::string subject_id;
public:
    explicit Subject();
    explicit Subject(int);
    explicit Subject(std::string);
    explicit Subject(const Subject&);
    explicit Subject(Subject&&);

    Subject& operator=(const Subject&);
    Subject& operator=(Subject&&);

    void SetId(int id);
    void SetSubjectName(std::string);
    void SetDatabaseName(std::string);
    void SetUserName(std::string);
    void SetDatabaseType(std::string);
    std::map<std::string,std::string> GetParametrs();
};


//#endif //PUREBASE_SUBJECT_H
