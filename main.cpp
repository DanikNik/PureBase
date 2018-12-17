#include "sys/sys.h"
#include <vector>
#include "LessonHelper/lesson_helper.h"
#include "SubjectHelper/subject_helper.h"
#include "DataHelper/Document_Helper/document_helper.h"
#include "DataHelper/data.h"
#include "TeacherHelper/teacher_helper.h"
#include "DataHelper/Video_Helper/video_helper.h"
#include "Helper/helper.h"
#include "DataHelper/Video_Helper/video_helper.h"
#include "Server/server.h"
#include "SelectTableCommand/select_table_command.h"
#include "InsertRowCommand/insert_row_command.h"
#include "DeleteRowCommand/delete_row_command.h"
#include "UpdateTableCommand/update_table_command.h"
#include "LessonHelper/lesson_helper.h"
#include "DataHelper/Document_Helper/document_helper.h"
#include "DataHelper/Video_Helper/video_helper.h"
#include "session/session.h"
#include "session_director/session_director.h"

//int main(int argc, char *argv[]) {
//
//  // Сценарий запроса SELECT из таболицы преподавателей
//  // Используется команда SELECT
//  // TODO удалить команды CreateTableCommand, DropTableCommand, DeleteDBCommand, CreateDBCommand
//  // TODO добавить реализацию в UpdateCommand
//
//
//  // Создание пользователя в системной таблице
//
//  // Создали права доступа
//  Permissions permissions;
//  permissions.set_write();
//  permissions.set_read();
//
//  // Создали пользователя в системной таблице
//  Sys *system_table = Sys::get_instance();
//  system_table->add_user("abcd", "Ivan", permissions);
//
//  // Создаем сессию с пользователем
//  SessionType type = SBN;
//  std::string token = "abcd";
//  SessionByName sba_session;
//  SessionDirector director(&sba_session);
//  director.create_session(token, type);
//  auto ses = sba_session.get_result();
//
//  // проверяем его данные
//  if (sba_session.get_result()->is_connect()) {
//    std::cout << ses->get_user_token() << " " << ses->get_user_name() << " " << ses->get_user_permissions().can_write();
//  } else {
//    std::cout << "Пользователя с такими токеном не существует" << std::endl;
//  }
//
//  // Создаем нужный хелпер
//
//  // P.S это все к Teacher helper
//  TeacherHelper helper;
//
//  // Опции для запроса
//  std::cout << std::endl;
//  std::vector<std::pair<std::string, std::string>> attributes;
//  attributes.push_back(std::make_pair<std::string, std::string>("name", "halayji"));
//
//  // В Select мы передаем сессию, хелпер, называние таблицы, название базы данных, параметы(то, что хотим получить)
//  // ошибки с этим отлавливаются на уровне базы данных, опции(аттрибуты, условия филтрации данных)
//  SelectTableCommand selectTableCommand(&sba_session, &helper, "teacher",
//                                        "purebase", {"id", "name", "specialization"}, attributes);
//
//  // Исполняем команду
//  selectTableCommand.execute();
//
//
//  return 0;
//}

int main(){
  Server().start();
}