//
// Created by daniknik on 29.10.18.
//

#include "gtest/gtest.h"

//#include "../api_endpoint.h"


#include <pistache/net.h>
#include <pistache/http.h>
#include <pistache/client.h>

using namespace Pistache;
using namespace Pistache::Http;

class TestClientInit : public ::testing::Test {
 protected:
  void SetUp() {
  }
  void TearDown() {
  }

  Http::Client client;
};

TEST_F(TestClientInit, test_ready) {
  auto resp = client.get("localhost:9080/ready").send();
  resp.then([&](Http::Response response) {
    ASSERT_TRUE((std::string)response.body()=="0");
  }, Async::IgnoreException);
//  ASSERT_TRUE(false);
}

int main(int argc, char **argv) {
  // The following line must be executed to initialize Google Mock
  // (and Google Test) before running the tests.
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();

}