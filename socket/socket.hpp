#include <string>
#include <unistd.h>     // close()
#include <memory>
#include <functional>


std::string int2ipv4(uint32_t ip);


class Socket {
public:
    Socket() : m_Sd(-1) {}

    Socket(int sd) : m_Sd(sd) {}

    ~Socket() { if (m_Sd > 0) ::close(m_Sd); }

public:
    int sd() const noexcept { return m_Sd; }

    void connect(const std::string &host, int port);

    void connect(const std::string &host, int port, int timeout);

    void send(const std::string &s);

    bool hasData();

    std::string recv();

    std::string recv(size_t bytes);

    std::string recvTimed(int timeout);

    void setRcvTimeout(int sec, int microsec);

    void setNonBlocked(bool opt);

    void setReuseAddr(int sd);

    void createServerSocket(uint32_t port, uint32_t queue_size);

    std::shared_ptr<Socket> accept();

    void close() { ::close(m_Sd); }

    void httpQuery(const std::string &query, std::function<void(const std::string &s)> cb) {
        send(query);
        std::string res = recv();
        cb(res);
    }

private:
    //Socket(const Socket &s);
    //const Socket& operator=(const Socket &s);
private:
    int m_Sd;
};

