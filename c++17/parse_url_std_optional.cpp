#include <assert.h>
#include <optional>
#include <string>
#include <regex>
using std::optional;
using std::string;

struct URL
{
   string           protocol;
   string           domain;
   optional<int>    port;
   optional<string> loc;
   optional<string> query;
   optional<string> fragment;
};

optional<URL> consume_url(string url)
{
   std::regex rex(R"(^(\w+):\/\/([\w.-]+)(:(\d+))?([\w\/\.]+)?(\?([\w=&]*)(#?(\w+))?)?$)");  
   std::smatch match;

   if (std::regex_match(url, match, rex))
   {
      if (match[1].matched && match[2].matched)
      {
         URL tokens;
         tokens.protocol = match[1].str();
         tokens.domain = match[2].str();
         if(match[4].matched)
            tokens.port = std::stoi(match[4]);
         if (match[5].matched)
            tokens.loc = match[5];
         if (match[7].matched)
            tokens.query = match[7];
         if (match[9].matched)
            tokens.fragment = match[9];

         return tokens;
      }
   }
   return {};
}

int main()
{
   auto url_first = consume_url("https://google.com");
   assert(url_first);
   assert(url_first->protocol == "https");
   assert(url_first->domain == "google.com");
   assert(!url_first->port);
   assert(!url_first->loc);
   assert(!url_first->query);
   assert(!url_first->fragment);

   auto url_second = consume_url("https://investing.com:80/en/index.html?lite=true#ui");
   assert(url_second);
   assert(url_second->protocol == "https");
   assert(url_second->domain == "investing.com");
   assert(url_second->port == 80);
   assert(url_second->loc.value() == "/en/index.html");
   assert(url_second->query.value() == "lite=true");
   assert(url_second->fragment.value() == "ui");
   
   return 0;
}
