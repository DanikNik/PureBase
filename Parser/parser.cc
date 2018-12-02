//
// Created by daniknik on 02.12.18.
//

#include "parser.h"

#include "../DataHelper/Video_Helper/video_helper.h"
#include "../DataHelper/Document_Helper/document_helper.h"
#include "../LessonHelper/lesson_helper.h"
#include "../SubjectHelper/subject_helper.h"
#include "../TeacherHelper/teacher_helper.h"

#include "../CreateDBCommand/create_db_command.h"
#include "../CreateTableCommand/create_table_command.h"
#include "../DeleteDBCommand/delete_db_command.h"
#include "../DropTableCommand/drop_table_command.h"


Helper* Parser::query(const std::string &query) {
  return new DocumentHelper();
}