#ifndef APPLICATION_H
#define APPLICATION_H

struct Application {
    int tLi;
    int tLv;
    int tRi;
    int tRv;
    int fLi;
    int fRi;
    int tCS;
    int fCS;
    bool isFirst;
    int n;
    int D;
    int xn;

    Application(): tLi(0), tLv(0), tRi(0), tRv(0), fLi(0), fRi(0),
    tCS(1), fCS(1), isFirst(true), n(0), D(0), xn(0) {}
};

typedef bool (*Callback)(void *object);
bool operation(Callback callback, void *data);

bool app_get_D(void* object);
bool app_get_element(void* object);
bool app_output_match(void* object);
bool app_process(void* object);
int app_run(void* object);

#endif // APPLICATION_H