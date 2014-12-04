#include <iostream>
#include <curl/curl.h>
#include <cstring>
#include "pushbullet.hpp"

Pushbullet::Pushbullet(const char *token)
{
    token_ = (char*)token;
}

Pushbullet::~Pushbullet()
{
//    delete token_;
}

void Pushbullet::print()
{
    std::cout << "Class Pushbullet" << std::endl
	      << " token_ = " << token_ << std::endl;
}

void Pushbullet::push(char *data)
{
    CURL *api;
    CURLcode response;
    api = curl_easy_init();

    curl_slist *headers = NULL;
    headers = curl_slist_append(headers, "Content-Type: application/json");

    char *url = NULL;
    asprintf(&url, "%s%s", API, "pushes");

    curl_easy_setopt(api, CURLOPT_URL, url);
    curl_easy_setopt(api, CURLOPT_USERPWD, token_);
    curl_easy_setopt(api, CURLOPT_POSTFIELDS, data);
    curl_easy_setopt(api, CURLOPT_HTTPHEADER, headers);

    response = curl_easy_perform(api);
    curl_easy_cleanup(api);
    curl_slist_free_all(headers);
    delete url;
}

void Pushbullet::push_note(const char *title, const char *body)
{
    char *data = NULL;

    asprintf(&data, "{\"type\":\"%s\",", "note");
    asprintf(&data, "%s\"title\":\"%s\",", data, title);
    asprintf(&data, "%s\"body\":\"%s\"", data, body);
    asprintf(&data, "%s}", data);

    push(data);
    delete data;
}

void Pushbullet::push_link(const char *title, const char *body, const char *url)
{
    char *data = NULL;

    asprintf(&data, "{\"type\":\"%s\",", "link");
    asprintf(&data, "%s\"title\":\"%s\",", data, title);
    asprintf(&data, "%s\"body\":\"%s\",", data, body);
    asprintf(&data, "%s\"url\":\"%s\"", data, url);
    asprintf(&data, "%s}", data);

    push(data);
    delete data;
}

void Pushbullet::push_address(const char *name, const char *address)
{
    char *data = NULL;

    asprintf(&data, "{\"type\":\"%s\",", "address");
    asprintf(&data, "%s\"name\":\"%s\",", data, name);
    asprintf(&data, "%s\"address\":\"%s\"", data, address);
    asprintf(&data, "%s}", data);

    push(data);
    delete data;
}

void Pushbullet::push_checklist(const char *title, const char *items)
{
    char *data = NULL;

    asprintf(&data, "{\"type\":\"%s\",", "list");
    asprintf(&data, "%s\"title\":\"%s\",", data, title);
    asprintf(&data, "%s\"items\":%s", data, items);
    asprintf(&data, "%s}", data);

    push(data);
    delete data;
}

