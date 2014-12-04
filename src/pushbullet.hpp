#define API "https://api.pushbullet.com/v2/"

class Pushbullet
{
    char *token_;
public:
    Pushbullet(const char *token);
    ~Pushbullet();
    void print();
    void push(char *data);
    void push_note(const char *title, const char *body);
    void push_link(const char *title, const char *body, const char *link);
    void push_address(const char *name, const char *address);
    void push_checklist(const char *title, const char *items);
    void push_file();
};
