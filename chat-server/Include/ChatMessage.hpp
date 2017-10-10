/*
 * chat_message.hpp
 *
 *  Created on: 2017Äê10ÔÂ10ÈÕ
 *      Author: cguo005
 */

#pragma once

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

class ChatMessage
{
public:
    static const int header_length = 4;
    static const int max_body_length = 512;
    ChatMessage() : body_length_(0)
    {
    }

    ChatMessage(const std::string& str) : body_length_(str.size()+1)
    {
        memcpy(data_ + header_length, str.c_str(), body_length_);
        encode_header();
    }

    const char* data() const
    {
        return data_;
    }

    char* data()
    {
        return data_;
    }

    size_t length() const
    {
        return header_length + body_length_;
    }

    const char* body() const
    {
        return data_ + header_length;
    }

    char* body()
    {
        return data_ + header_length;
    }

    size_t body_length() const
    {
        return body_length_;
    }

    void body_length(size_t new_length)
    {
        body_length_ = new_length;
        if (body_length_ > max_body_length)
            body_length_ = max_body_length;
    }

    bool decode_header()
    {
        using namespace std;
        char header[header_length + 1] = "";
        strncat(header, data_, header_length);
        body_length_ = atoi(header);
        if (body_length_ > max_body_length)
        {
            body_length_ = 0;
            return false;
        }
        return true;
    }

    void encode_header()
    {
        using namespace std;
        char header[header_length + 1] = "";
        sprintf(header, "%4d", static_cast<int>(body_length_));
        memcpy(data_, header, header_length);
    }

private:
    char data_[header_length + max_body_length];
    size_t body_length_;
};

