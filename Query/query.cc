//
// Created by daniknik on 29.10.18.
//

#include "query.h"
AbstractQuery::AbstractQuery() {

}
AbstractQuery::~AbstractQuery() {

}
void AbstractQuery::Execute() {

}

CreateDBQuery::CreateDBQuery() {

}
CreateDBQuery::~CreateDBQuery() {

}
void CreateDBQuery::Execute() {
  AbstractQuery::Execute();
}

DeleteDBQuery::DeleteDBQuery() {

}
DeleteDBQuery::~DeleteDBQuery() {

}
void DeleteDBQuery::Execute() {
  AbstractQuery::Execute();
}

CreateTableQuery::CreateTableQuery() {

}
CreateTableQuery::~CreateTableQuery() {

}
void CreateTableQuery::Execute() {
  AbstractQuery::Execute();
}

DropTableQuery::DropTableQuery() {

}
DropTableQuery::~DropTableQuery() {

}
void DropTableQuery::Execute() {
  AbstractQuery::Execute();
}

UpdateTableQuery::UpdateTableQuery() {

}
UpdateTableQuery::~UpdateTableQuery() {

}
void UpdateTableQuery::Execute() {
  AbstractQuery::Execute();
}

SelectTableQuery::SelectTableQuery() {

}
SelectTableQuery::~SelectTableQuery() {

}
void SelectTableQuery::Execute() {
  AbstractQuery::Execute();
}
