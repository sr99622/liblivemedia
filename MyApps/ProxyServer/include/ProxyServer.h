/*******************************************************************************
* ProxyServer.h
*
* copyright 2024 Stephen Rhodes
*
* This library is free software; you can redistribute it and/or modify it under
* the terms of the GNU Lesser General Public License as published by the
* Free Software Foundation; either version 3 of the License, or (at your
* option) any later version. (See <http://www.gnu.org/copyleft/lesser.html>.)
*
* This library is distributed in the hope that it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
* FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for
* more details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with this library; if not, write to the Free Software Foundation, Inc.,
* 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
*
*******************************************************************************/

#ifndef PROXY_SERVER_H
#define PROXY_SERVER_H

#include "liveMedia.hh"
#include "BasicUsageEnvironment.hh"
#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <thread>

namespace liblivemedia
{

class ProxyServer
{

public:
    UsageEnvironment* env = nullptr;
    TaskScheduler* scheduler = nullptr;
    RTSPServer* rtspServer = nullptr;

    int port = 554;
    char watchVariable = 0;

    std::map<std::string, std::string> uris;

    ~ProxyServer()
    {
        if (env) free(env);
        if (scheduler) free(scheduler);
        if (rtspServer) free(rtspServer);
    }

    ProxyServer()
    {
        scheduler = BasicTaskScheduler::createNew();
        env = BasicUsageEnvironment::createNew(*scheduler);
    }

    void addURI(const std::string& uri, const std::string& name, const std::string& username, const std::string& password)
    {
        ServerMediaSession* sms = ProxyServerMediaSession::createNew(*env, rtspServer, 
                                                                    uri.c_str(), name.c_str(), 
                                                                    username.c_str(), password.c_str(), 0, 0);

        rtspServer->addServerMediaSession(sms);
        std::string proxy = rtspServer->rtspURL(sms);
        uris[uri] = proxy;
    }

    std::string getRootURI() const 
    {
        return std::string(rtspServer->rtspURLPrefix());
    }

    void init(int port = 554)
    {
        this->port = port;
        rtspServer = RTSPServer::createNew(*env, port, nullptr);
        if (!rtspServer) {
            port = 8554;
            rtspServer = RTSPServer::createNew(*env, port, nullptr);
        }
        if (!rtspServer) {
            throw std::runtime_error("Unable to create rtsp server");
        }
    }

    void startLoop()
    {
        std::thread thread([&]() { loop(); });
        thread.detach();
    }

    void loop()
    {
        watchVariable = 0;
        env->taskScheduler().doEventLoop(&watchVariable);
    }

    void stopLoop()
    {
        watchVariable = ~0;
    }

    int watch()
    {
       return (int)watchVariable; 
    }

    std::string getProxyURI(const std::string& uri) const
    {
        std::string result;

        for (auto element :uris) {
            if (element.first == uri) {
                result = element.second;
                break;
            }
        }

        return result;
    }


};

}

#endif // PROXY_SERVER_H

