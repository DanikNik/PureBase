//
// Created by daniknik on 29.10.18.
//

#include "query.h"
Query::Query() {

}
Query::~Query() {

}
void Query::Execute() {

}

CreateDBQuery::CreateDBQuery() {

}
CreateDBQuery::~CreateDBQuery() {

}
void CreateDBQuery::Execute() {
  Query::Execute();
}

DeleteDBQuery::DeleteDBQuery() {

}
DeleteDBQuery::~DeleteDBQuery() {

}
void DeleteDBQuery::Execute() {
  Query::Execute();
}

CreateTableQuery::CreateTableQuery() {

}
CreateTableQuery::~CreateTableQuery() {

}
void CreateTableQuery::Execute() {
  Query::Execute();
}

DropTableQuery::DropTableQuery() {

}
DropTableQuery::~DropTableQuery() {

}
void DropTableQuery::Execute() {
  Query::Execute();
}

UpdateTableQuery::UpdateTableQuery() {

}
UpdateTableQuery::~UpdateTableQuery() {

}
void UpdateTableQuery::Execute() {
  Query::Execute();
}

SelectTableQuery::SelectTableQuery() {

}
SelectTableQuery::~SelectTableQuery() {

}
void SelectTableQuery::Execute() {
  Query::Execute();
}
