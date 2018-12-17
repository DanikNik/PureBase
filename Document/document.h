//
// Created by semyon on 15.12.18.
//

#ifndef PUREBASE_DOCUMENT_H
#define PUREBASE_DOCUMENT_H

#include "../Helper/defaults.h"
#include <string>
#include <map>

class Document {
private:
    std::string doc_name;
    std::string db_name;
    std::string table_name;
    std::string db_type;
    std::string user_name;
    std::string doc_id;
public:
    explicit Document();
    explicit Document(int);
    explicit Document(std::string);
    explicit Document(const Document&);
    explicit Document(Document&&);

    Document& operator=(const Document&);
    Document& operator=(Document&&);

    void SetId(int id);
    void SetDocumentName(std::string);
    void SetDatabaseName(std::string);
    void SetUserName(std::string);
    void SetDatabaseType(std::string);
    std::map<std::string,std::string> GetParametrs();
};


#endif //PUREBASE_DOCUMENT_H
