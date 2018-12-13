#include <iostream>
//#include "ApiEndpoint/api_endpoint.h"
//#include <iostream>
//#include "session_by_name.h"
//#include "session_director.h"
//#include "sys.h"

//#include <vector>
//#include "LessonHelper/lesson_helper.h"
//#include "SubjectHelper/subject_helper.h"
//#include "DataHelper/Document_Helper/document_helper.h"
//#include "DataHelper/data.h"
//#include "TeacherHelper/teacher_helper.h"
//#include "DataHelper/Video_Helper/video_helper.h"
//#include "Helper/helper.h"
//#include "DataHelper/Video_Helper/video_helper.h"
#include "Server/server.h"

int main(int argc, char** argv) {
    //DocumentHelper DH("doc1");
    //DH.Create("doc1");
    //DH.ChangeName("doc2");
    //DH.Select({"doc1"});//??
    //DH.SelectByTag({"doc1"},"tag");
    //DH.ShowTables();
    //DH.DeleteRow();
    //VideoHelper VH("video1");
    //VH.Create("video1");
    //VH.ShowTables();
    //VH.SelectByTag({"video1"}, "tag");
    //VH.Select({"video1"});
    //VH.DeleteRow();
    //VH.ChangeName("video2");
    //VH.GetFile("filepath");
    //VH.PutFile("filepath");
    //SubjectHelper SH("subjectname");
    //SH.ChangeName("subjectname2");
    //SH.DeleteRow();
    //SH.Select({"subjectname"});
    //SH.ShowTables();
    //SH.Create("subjectname3");
    //SH.SelectByTag({"subjectname3"},"tag");
    //TeacherHelper TH("name");
    //TH.SelectByTag({"name"},"tag");
    ////TH.Select({"name"});
    //TH.ShowTables();
    //TH.Create("name");
    //TH.DeleteRow();
    //TH.ChangeName("name2");
    //TH.ChangeSpecialization("slut");
    //LessonHelper LH("lesson");
    //LH.ChangeName("lesson2");
    //LH.Create("lesson3");
    //LH.ShowTables();
    //LH.Select({"lesson"});
    //LH.SelectByTag({"lesson"},"tag");
    //LH.ChangeTheme("Theme");
    //LH.ChangeTeacher(2);
    //LH.ChangeSubject(1);
    //LH.DeleteRow();//Косячно реализован, пока не трогать
 //Port port(9080);
  //Address addr(Ipv4::any(), port);
  //ApiEndpoint endpoint(addr);
  //endpoint.init(1);
  //endpoint.start();
  //endpoint.shutdown();
//  Sys *system_table = Sys::get_instance();
//
//  system_table->add_user("abcd", "Ivan", 0);
//  system_table->add_user("qwerty", "Name", 1);
//  system_table->add_user("thcp", "John", 5);
//
//  SessionType type = SBN;
//  std::string token = "abcd";
//
//  SessionByName sba_session;
//  SessionDirector director(&sba_session);
//  director.create_session(token, type);
//
//  auto ses = sba_session.get_result();
//
//  if(sba_session.get_result()->is_connect()) {
//    std::cout << ses->get_user_token() << " " << ses->get_user_name() << " "
//              << ses->get_user_permissions();
//  } else {
//    std::cout << "Пользователя с такими токеном не существует" << std::endl;
//  }


using namespace std;

int main(int argc, char *argv[]) {
  Server().start();
  return 0;
}
