#include "pushbullet.cpp"
#define APIKEY "YOUR API KEY"

int main()
{
    Pushbullet pb(APIKEY);

    pb.print();
    pb.push_note("Title", "Message body");
    pb.push_link("Google", "Body", "http://google.com");
    pb.push_address("Some place", "Szczecin, Poland");
    pb.push_checklist("List", "[\"one\",\"two\",\"three\"]");
    return 0;
}
